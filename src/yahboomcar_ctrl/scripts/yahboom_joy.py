#!/usr/bin/env python3
# encoding: utf-8
"""
Yahboom Joystick Control Node - ROS2 Implementation

High-Level Architecture Overview:

Service Communication Layer:
- srv_armcallback() - Initiates async service calls to query driver for current arm angles
- handle_arm_response() - Processes service responses with retry logic for invalid angles

Arm Control Layer:
- pub_armjoint() - Creates threaded arm control for non-blocking continuous movement
- Armcallback() - Synchronizes joystick node state with actual servo positions from driver
- arm_ctrl() - Threaded function providing smooth continuous arm movement with joint limits

Main Control Layer:
- buttonCallback() - Main entry point that routes joystick data to appropriate controller handler
- user_jetson() - Handles 15-button Jetson controller with specific button/axis mappings
- user_pc() - Handles 11-button PC controllers (Xbox, PlayStation, generic USB)

Utility Layer:
- filter_data() - Applies deadzone to prevent movement from controller drift
- cancel_nav() - Emergency stop function with debouncing and state management

This node provides a responsive joystick interface for controlling both robot base movement
and robotic arm simultaneously, with proper state management and feedback loops.
"""
import os
import time
import threading
from time import sleep
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from yahboomcar_msgs.msg import *
from yahboomcar_msgs.srv import *
from yahboomcar_msgs.srv import RobotArmArray
from geometry_msgs.msg import Twist
from std_msgs.msg import Int32, Bool
from action_msgs.msg import GoalInfo  # FIXED: replaced GoalID with GoalInfo
from rclpy.qos import qos_profile_sensor_data

class JoyTeleop(Node):
    def __init__(self):
        super().__init__('yahboom_joy')
        
        # Parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('xspeed_limit', 1.0),
                ('yspeed_limit', 1.0),
                ('angular_speed_limit', 5.0),
            ]
        )
        
        # Initialize variables
        self.Joy_active = False
        self.Buzzer_active = False
        self.gripper_active = True
        self.getArm_active = True
        self.loop_active = True
        self.RGBLight_index = 0
        self.geta_arm_index = 0
        self.cancel_time = time.time()
        self.linear_Gear = 1
        self.angular_Gear = 1
        self.armjoint = ArmJoint()
        self.armjoint.run_time = 10
        self.arm_joints = [90.0, 90.0, 90.0, 90.0, 90.0, 90.0]
        
        # Get parameters
        self.xspeed_limit = self.get_parameter('xspeed_limit').value
        self.yspeed_limit = self.get_parameter('yspeed_limit').value
        self.angular_speed_limit = self.get_parameter('angular_speed_limit').value
        
        # Publishers
        self.pub_goal = self.create_publisher(GoalInfo, "move_base/_action/cancel_goal", 10)
        self.pub_cmdVel = self.create_publisher(Twist, 'cmd_vel', 10)
        self.pub_Buzzer = self.create_publisher(Bool, "Buzzer", 1)
        self.pub_JoyState = self.create_publisher(Bool, "JoyState", 10)
        self.pub_RGBLight = self.create_publisher(Int32, "RGBLight", 10)
        self.pub_Arm = self.create_publisher(ArmJoint, "TargetAngle", 1000)
        
        # Subscribers
        self.sub_Joy = self.create_subscription(
            Joy,
            'joy',
            self.buttonCallback,
            qos_profile_sensor_data
        )
        self.sub_Arm = self.create_subscription(ArmJoint, "ArmAngleUpdate", self.Armcallback, 1000)
        
        # Service client
        self.srv_arm = self.create_client(RobotArmArray, "CurrentAngle")
        
        # Timer for periodic tasks
        self.create_timer(0.05, self.timer_callback)  # 20Hz
        
        self.get_logger().info('Yahboom joy node started')

    def timer_callback(self):
        pass

    # Service Communication: Makes async service call to query current arm angles from driver
    # Called when getArm_active is True, initiates communication with driver node to get
    # current servo positions. Uses async pattern with handle_arm_response as callback.
    def srv_armcallback(self):
        self.get_logger().info("srv_armcallback: called")
        self.getArm_active = False
        self.srv_arm.wait_for_service()
        request = RobotArmArray.Request()
        request.apply = "GetArmJoints"
        self.get_logger().info("srv_armcallback: service available")
        future = self.srv_arm.call_async(request)
        future.add_done_callback(self.handle_arm_response)

    # Service Response Handler: Processes arm angle data from driver, handles retries for invalid values
    # Receives service response with current arm angles. Implements retry logic if angles
    # are invalid (-1), updates local arm_joints array to keep joystick node synchronized
    # with actual servo positions. Max 10 retries before resetting.
    def handle_arm_response(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"handle_arm_response: got response: {response}")
            if response is not None and hasattr(response, "angles"):
                self.get_logger().info(f"handle_arm_response: response.angles = {response.angles}")
                for i in range(len(response.angles)):
                    self.get_logger().info(f"handle_arm_response: angle[{i}] = {response.angles[i]}")
                    if response.angles[i] == -1:
                        if self.geta_arm_index <= 10:
                            self.geta_arm_index += 1
                            self.get_logger().info(f"handle_arm_response: angle[{i}] == -1, retrying (geta_arm_index={self.geta_arm_index})")
                            time.sleep(0.1)
                            self.srv_armcallback()
                            return
                        else:
                            self.geta_arm_index = 0
                            self.get_logger().info("handle_arm_response: max retries reached, resetting geta_arm_index")
                    else:
                        self.arm_joints[i] = response.angles[i]
                self.get_logger().info(f"handle_arm_response: updated arm_joints: {self.arm_joints}")
            else:
                self.get_logger().info("handle_arm_response: Service call failed or response missing 'angles'")
        except Exception as e:
            self.get_logger().info(f"handle_arm_response: Exception: {e}")

    # Arm Movement Initiator: Creates threaded arm control for continuous movement without blocking
    # Called by user_jetson/user_pc when arm buttons are pressed. Creates daemon thread
    # running arm_ctrl() to allow smooth, continuous arm movement while other controls
    # remain responsive. Sets loop_active=True to start movement.
    def pub_armjoint(self, id, direction):
        self.loop_active = True
        arm_thread = threading.Thread(target=self.arm_ctrl, args=(id, direction))
        arm_thread.setDaemon(True)
        arm_thread.start()

    # State Synchronization: Receives arm position updates from driver to keep joystick node synchronized
    # Subscriber callback for /ArmAngleUpdate topic. Updates local arm_joints array with
    # actual servo positions from driver. Ensures joystick node has accurate state for
    # continuous movement calculations and prevents position drift.
    def Armcallback(self, msg):
        if not isinstance(msg, ArmJoint): return
        if len(msg.joints) != 0:
            self.arm_joints = [float(j) for j in msg.joints]
        else:
            self.arm_joints[msg.id - 1] = float(msg.angle)

    # Continuous Arm Control: Runs in separate thread to provide smooth, continuous arm movement
    # Threaded function that runs while loop_active=True. Incrementally changes joint angles,
    # applies joint limits (0-180°, 0-270°, 30-180° depending on joint), publishes commands
    # every 30ms. Allows holding buttons for smooth movement without blocking other controls.
    def arm_ctrl(self, id, direction):
        while rclpy.ok() and self.loop_active:
            self.arm_joints[id - 1] += direction
            if id == 5:
                if self.arm_joints[id - 1] > 270: self.arm_joints[id - 1] = 270
                elif self.arm_joints[id - 1] < 0: self.arm_joints[id - 1] = 0
            elif id == 6:
                if self.arm_joints[id - 1] >= 180: self.arm_joints[id - 1] = 180
                elif self.arm_joints[id - 1] <= 30: self.arm_joints[id - 1] = 30
            else:
                if self.arm_joints[id - 1] > 180: self.arm_joints[id - 1] = 180
                elif self.arm_joints[id - 1] < 0: self.arm_joints[id - 1] = 0
            self.armjoint.id = id
            self.armjoint.angle = float(self.arm_joints[id - 1])
            if rclpy.ok():
                self.pub_Arm.publish(self.armjoint)
            else:
                break
            sleep(0.03)

    # Main Entry Point: Receives joystick data, determines controller type, routes to appropriate handler
    # Primary callback for /joy topic. Checks joystick data validity, triggers arm state query
    # if needed, detects controller type by button count (15=Jetson, else=PC), and routes to
    # appropriate handler function for button/axis processing.
    def buttonCallback(self, joy_data):
        #self.get_logger().info(f"buttonCallback called! Buttons: {len(joy_data.buttons)}, Axes: {len(joy_data.axes)}")
        #self.get_logger().info(f"Buttons : {joy_data.buttons}")
        if not isinstance(joy_data, Joy): return
        if self.getArm_active: self.srv_armcallback()
        if len(joy_data.buttons) == 15: self.user_jetson(joy_data)
        else: self.user_pc(joy_data)

    # Jetson Controller Handler: Processes 15-button controller with specific button/axis mappings
    # Handles specialized Jetson controller with 15 buttons. Maps buttons: A[0], B[1], X[3], Y[4],
    # L1[6], R1[7], SELECT[10], START[11], etc. Axes: Left stick[0,1], Right stick[2,3], R2[4],
    # L2[5], D-pad[6,7]. Controls arm movement, robot base, gear changes, RGB lights, buzzer.
    def user_jetson(self, joy_data):
        '''
        :jetson joy_data:
            axes 8: [0.0, -0.0, -0.0, -0.0, 0.0, 0.0, 0.0, 0.0]
            左摇杆(左正右负): axes[0]
            左摇杆(上正下负): axes[1]
            右摇杆(左正右负): axes[2]
            右摇杆(上正下负): axes[3]
            R2(按负抬正): axes[4]
            L2(按负抬正): axes[5]
            左按键(左正右负): axes[6]
            左按键(上正下负): axes[7]
            buttons 15:  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
            A: buttons[0]
            B: buttons[1]
            X: buttons[3]
            Y: buttons[4]
            L1: buttons[6]
            R1: buttons[7]
            SELECT: buttons[10]
            START: buttons[11]
            左摇杆按下: buttons[13]
            右摇杆按下: buttons[14]
        '''
        if joy_data.buttons[10] == 1: 
            self.gripper_active = not self.gripper_active
        if joy_data.buttons[0] == joy_data.buttons[1] == joy_data.buttons[
            6] == joy_data.buttons[3] == joy_data.buttons[4] == 0 and joy_data.axes[
            7] == joy_data.axes[6] == 0 and joy_data.axes[5] != -1: 
            self.loop_active = False
        else:
            if joy_data.buttons[3] == 1: 
                self.pub_armjoint(1, -1) # X
            if joy_data.buttons[1] == 1: 
                self.pub_armjoint(1, 1)  # B
            if joy_data.buttons[0] == 1: 
                self.pub_armjoint(2, -1) # A
            if joy_data.buttons[4] == 1: 
                self.pub_armjoint(2, 1)  # Y
            if joy_data.axes[6] != 0: 
                self.pub_armjoint(3, -joy_data.axes[6]) # 左按键左正右负
            if joy_data.axes[7] != 0: 
                self.pub_armjoint(4, joy_data.axes[7]) # 左按键上正下负
            if self.gripper_active:
                if joy_data.axes[5] == -1: 
                    self.pub_armjoint(6, -1)  # L2
                if joy_data.buttons[6] == 1: 
                    self.pub_armjoint(6, 1) # L1
            else:
                if joy_data.axes[5] == -1: 
                    self.pub_armjoint(5, -1)  # L2
                if joy_data.buttons[6] == 1: 
                    self.pub_armjoint(5, 1) # L1
        # Cancel
        if joy_data.axes[4] == -1: 
            self.cancel_nav()
        # RGBLight
        if joy_data.buttons[7] == 1:
            if self.RGBLight_index < 6: 
                self.pub_RGBLight.publish(Int32(data=int(self.RGBLight_index)))
            else: 
                self.RGBLight_index = 0
            self.RGBLight_index += 1
        # Buzzer
        if joy_data.buttons[11] == 1:
            self.Buzzer_active = not self.Buzzer_active
            self.pub_Buzzer.publish(Bool(data=self.Buzzer_active))
        # linear Gear control
        if joy_data.buttons[13] == 1:
            if self.linear_Gear == 1.0: 
                self.linear_Gear = 1.0 / 3
            elif self.linear_Gear == 1.0 / 3: 
                self.linear_Gear = 2.0 / 3
            elif self.linear_Gear == 2.0 / 3: 
                self.linear_Gear = 1
        # angular Gear control
        if joy_data.buttons[14] == 1:
            if self.angular_Gear == 1.0: 
                self.angular_Gear = 1.0 / 4
            elif self.angular_Gear == 1.0 / 4: 
                self.angular_Gear = 1.0 / 2
            elif self.angular_Gear == 1.0 / 2: 
                self.angular_Gear = 3.0 / 4
            elif self.angular_Gear == 3.0 / 4: 
                self.angular_Gear = 1.0
        xlinear_speed = self.filter_data(joy_data.axes[1]) * self.xspeed_limit * self.linear_Gear
        ylinear_speed = self.filter_data(joy_data.axes[0]) * self.yspeed_limit * self.linear_Gear
        angular_speed = self.filter_data(joy_data.axes[2]) * self.angular_speed_limit * self.angular_Gear
        if xlinear_speed > self.xspeed_limit: 
            xlinear_speed = self.xspeed_limit
        elif xlinear_speed < -self.xspeed_limit: 
            xlinear_speed = -self.xspeed_limit
        if ylinear_speed > self.yspeed_limit: 
            ylinear_speed = self.yspeed_limit
        elif ylinear_speed < -self.yspeed_limit: 
            ylinear_speed = -self.yspeed_limit
        if angular_speed > self.angular_speed_limit: 
            angular_speed = self.angular_speed_limit
        elif angular_speed < -self.angular_speed_limit: 
            angular_speed = -self.angular_speed_limit
        twist = Twist()
        twist.linear.x = xlinear_speed
        twist.linear.y = ylinear_speed
        twist.angular.z = angular_speed
        for i in range(3): 
            self.pub_cmdVel.publish(twist)

    # PC Controller Handler: Processes standard 11-button controllers (Xbox, PlayStation, generic USB)
    # Handles standard PC game controllers with 11 buttons. Maps buttons: A[0], B[1], X[2], Y[3],
    # L1[4], R1[5], SELECT[6], MODE[7], START[8], etc. Axes: Left stick[0,1], L2[2], Right stick[3,4],
    # R2[5], D-pad[6,7]. Same functionality as Jetson controller but with different button mappings.
    def user_pc(self, joy_data):
        '''
        :pc joy_data:
            axes 8: [ -0.0, -0.0, 0.0, -0.0, -0.0, 0.0, 0.0, 0.0 ]
            左摇杆左正右负: axes[0]
            左摇杆上正下负: axes[1]
            L2按负抬正:  axes[2]
            右摇杆左正右负: axes[3]
            右摇杆上正下负: axes[4]
            R2按负抬正:  axes[5]
            左按键左正右负: axes[6]
            左按键上正下负: axes[7]
            buttons 11: [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
            A: buttons[0]
            B: buttons[1]
            X: buttons[2]
            Y: buttons[3]
            L1: buttons[4]
            R1: buttons[5]
            SELECT: buttons[6]
            MODE: buttons[7]
            START: buttons[8]
            左摇杆按下: buttons[9]
            右摇杆按下: buttons[10]
        '''
        # print ("joy_data.buttons: ", joy_data.buttons)
        # print ("joy_data.axes: ", joy_data.axes)
        if joy_data.buttons[6] == 1: 
            self.gripper_active = not self.gripper_active
        if joy_data.buttons[0] == joy_data.buttons[1] == joy_data.buttons[
            2] == joy_data.buttons[3] == joy_data.buttons[4] == 0 and joy_data.axes[
            7] == joy_data.axes[6] == 0 and joy_data.axes[2] != -1: 
            self.loop_active = False
        else:
            if joy_data.buttons[2] == 1: 
                self.pub_armjoint(1, -1) # X
            if joy_data.buttons[1] == 1: 
                self.pub_armjoint(1, 1)  # B
            if joy_data.buttons[0] == 1: 
                self.pub_armjoint(2, -1) # A
            if joy_data.buttons[3] == 1: 
                self.pub_armjoint(2, 1)  # Y
            if joy_data.axes[6] != 0: 
                self.pub_armjoint(3, -joy_data.axes[6]) # 左按键左正右负
            if joy_data.axes[7] != 0: 
                self.pub_armjoint(4, joy_data.axes[7]) # 左按键上正下负
            if self.gripper_active:
                if joy_data.axes[2] == -1: 
                    self.pub_armjoint(6, -1)  # L2
                if joy_data.buttons[4] == 1: 
                    self.pub_armjoint(6, 1) # L1
            else:
                if joy_data.axes[2] == -1: 
                    self.pub_armjoint(5, -1)  # L2
                if joy_data.buttons[4] == 1: 
                    self.pub_armjoint(5, 1) # L1
        # 取消 Cancel
        if joy_data.axes[5] == -1: 
            self.cancel_nav()
        if joy_data.buttons[5] == 1:
            if self.RGBLight_index < 6: 
                self.pub_RGBLight.publish(Int32(data=int(self.RGBLight_index)))
            else: 
                self.RGBLight_index = 0
            self.RGBLight_index += 1
        if joy_data.buttons[7] == 1:
            self.Buzzer_active = not self.Buzzer_active
            self.pub_Buzzer.publish(Bool(data=self.Buzzer_active))
        # 档位控制 Gear control
        if joy_data.buttons[9] == 1:
            if self.linear_Gear == 1.0: 
                self.linear_Gear = 1.0 / 3
            elif self.linear_Gear == 1.0 / 3: 
                self.linear_Gear = 2.0 / 3
            elif self.linear_Gear == 2.0 / 3: 
                self.linear_Gear = 1
        if joy_data.buttons[10] == 1:
            if self.angular_Gear == 1.0: 
                self.angular_Gear = 1.0 / 4
            elif self.angular_Gear == 1.0 / 4: 
                self.angular_Gear = 1.0 / 2
            elif self.angular_Gear == 1.0 / 2: 
                self.angular_Gear = 3.0 / 4
            elif self.angular_Gear == 3.0 / 4: 
                self.angular_Gear = 1.0
        xlinear_speed = self.filter_data(joy_data.axes[1]) * self.xspeed_limit * self.linear_Gear
        ylinear_speed = self.filter_data(joy_data.axes[0]) * self.yspeed_limit * self.linear_Gear
        angular_speed = self.filter_data(joy_data.axes[3]) * self.angular_speed_limit * self.angular_Gear
        if xlinear_speed > self.xspeed_limit: 
            xlinear_speed = self.xspeed_limit
        elif xlinear_speed < -self.xspeed_limit: 
            xlinear_speed = -self.xspeed_limit
        if ylinear_speed > self.yspeed_limit: 
            ylinear_speed = self.yspeed_limit
        elif ylinear_speed < -self.yspeed_limit: 
            ylinear_speed = -self.yspeed_limit
        if angular_speed > self.angular_speed_limit: 
            angular_speed = self.angular_speed_limit
        elif angular_speed < -self.angular_speed_limit: 
            angular_speed = -self.angular_speed_limit
        twist = Twist()
        twist.linear.x = xlinear_speed
        twist.linear.y = ylinear_speed
        twist.angular.z = angular_speed
        for i in range(3): 
            self.pub_cmdVel.publish(twist)

    # Input Filtering: Applies deadzone to joystick inputs to prevent drift from small movements
    # Utility function that applies 0.2 deadzone to joystick axis values. Prevents robot movement
    # from small controller drift or accidental touches. Returns 0 for values below threshold.
    def filter_data(self, value):
        if abs(value) < 0.2: value = 0
        return value

    # Navigation Control: Handles emergency stop, joystick state toggle, and navigation cancellation
    # Emergency function called by cancel buttons (R2 on Jetson, R2 on PC). Toggles Joy_active state,
    # publishes emergency stop commands (cmd_vel=0), cancels navigation goals, resets arm state.
    # Includes 1-second debouncing to prevent rapid toggling.
    def cancel_nav(self):
        self.geta_arm_index = 0
        self.getArm_active = True
        now_time = time.time()
        if now_time - self.cancel_time > 1:
            self.Joy_active = not self.Joy_active
            for i in range(3):
                self.pub_JoyState.publish(Bool(data=self.Joy_active))
                self.pub_Buzzer.publish(Bool(data=False))
                self.pub_goal.publish(GoalInfo())  # FIXED: Use GoalInfo instead of GoalID
                self.pub_cmdVel.publish(Twist())
            self.cancel_time = now_time

if __name__ == '__main__':
    rclpy.init()
    joy = JoyTeleop()
    try:
        rclpy.spin(joy)
    except KeyboardInterrupt:
        joy.get_logger().info('Keyboard interrupt, shutting down')
    finally:
        joy.destroy_node()
        rclpy.shutdown()
