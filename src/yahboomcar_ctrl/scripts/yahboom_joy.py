#!/usr/bin/env python3
# encoding: utf-8
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

    def srv_armcallback(self):
        self.get_logger().info("srv_armcallback: called")
        self.getArm_active = False
        self.srv_arm.wait_for_service()
        request = RobotArmArray.Request()
        request.apply = "GetArmJoints"
        self.get_logger().info("srv_armcallback: service available")
        future = self.srv_arm.call_async(request)
        future.add_done_callback(self.handle_arm_response)

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

    def pub_armjoint(self, id, direction):
        self.loop_active = True
        arm_thread = threading.Thread(target=self.arm_ctrl, args=(id, direction))
        arm_thread.setDaemon(True)
        arm_thread.start()

    def Armcallback(self, msg):
        if not isinstance(msg, ArmJoint): return
        if len(msg.joints) != 0:
            self.arm_joints = [float(j) for j in msg.joints]
        else:
            self.arm_joints[msg.id - 1] = float(msg.angle)

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

    def buttonCallback(self, joy_data):
        #self.get_logger().info(f"buttonCallback called! Buttons: {len(joy_data.buttons)}, Axes: {len(joy_data.axes)}")
        #self.get_logger().info(f"Buttons : {joy_data.buttons}")
        if not isinstance(joy_data, Joy): return
        if self.getArm_active: self.srv_armcallback()
        if len(joy_data.buttons) == 15: self.user_jetson(joy_data)
        else: self.user_pc(joy_data)

    def user_jetson(self, joy_data):
        #self.get_logger().info(f"user_jetson called. Button 11 state: {joy_data.buttons[11]}")
        if joy_data.buttons[10] == 1: self.gripper_active = not self.gripper_active
        if joy_data.buttons[0] == joy_data.buttons[1] == joy_data.buttons[
            6] == joy_data.buttons[3] == joy_data.buttons[4] == 0 and joy_data.axes[
            7] == joy_data.axes[6] == 0 and joy_data.axes[5] != -1: self.loop_active = False
        else:
            if joy_data.buttons[3] == 1: self.pub_armjoint(1, -1)
            if joy_data.buttons[1] == 1: self.pub_armjoint(1, 1)
            if joy_data.buttons[0] == 1: self.pub_armjoint(2, -1)
            if joy_data.buttons[4] == 1: self.pub_armjoint(2, 1)
            if joy_data.axes[6] != 0: self.pub_armjoint(3, -joy_data.axes[6])
            if joy_data.axes[7] != 0: self.pub_armjoint(4, joy_data.axes[7])
            if self.gripper_active:
                if joy_data.axes[5] == -1: self.pub_armjoint(6, -1)
                if joy_data.buttons[6] == 1: self.pub_armjoint(6, 1)
            else:
                if joy_data.axes[5] == -1: self.pub_armjoint(5, -1)
                if joy_data.buttons[6] == 1: self.pub_armjoint(5, 1)
        if joy_data.axes[4] == -1: self.cancel_nav()
        if joy_data.buttons[7] == 1:
            if self.RGBLight_index < 6:
                self.pub_RGBLight.publish(Int32(data=int(self.RGBLight_index)))
            else:
                self.RGBLight_index = 0
            self.RGBLight_index += 1
        if joy_data.buttons[11] == 1:
            #self.get_logger().info("Publishing cmd_vel regardless of button")
            self.Buzzer_active = not self.Buzzer_active
            self.pub_Buzzer.publish(Bool(data=False))
            self.pub_Buzzer.publish(Bool(data=self.Buzzer_active))
            # Only publish cmd_vel if button 11 (start button) is held down
            xlinear_speed = self.filter_data(joy_data.axes[1]) * self.xspeed_limit * self.linear_Gear
            ylinear_speed = self.filter_data(joy_data.axes[0]) * self.yspeed_limit * self.linear_Gear
            angular_speed = self.filter_data(joy_data.axes[2]) * self.angular_speed_limit * self.angular_Gear
            twist = Twist()
            twist.linear.x = xlinear_speed
            twist.linear.y = ylinear_speed
            twist.angular.z = angular_speed
            for i in range(3):
                self.pub_cmdVel.publish(twist)
        if joy_data.buttons[13] == 1:
            if self.linear_Gear == 1.0: self.linear_Gear = 1.0 / 3
            elif self.linear_Gear == 1.0 / 3: self.linear_Gear = 2.0 / 3
            elif self.linear_Gear == 2.0 / 3: self.linear_Gear = 1
        if joy_data.buttons[14] == 1:
            if self.angular_Gear == 1.0: self.angular_Gear = 1.0 / 4
            elif self.angular_Gear == 1.0 / 4: self.angular_Gear = 1.0 / 2
            elif self.angular_Gear == 1.0 / 2: self.angular_Gear = 3.0 / 4
            elif self.angular_Gear == 3.0 / 4: self.angular_Gear = 1.0

    def user_pc(self, joy_data):
        # ... (same as before)

        pass  # Cut for brevity – no changes needed

    def filter_data(self, value):
        if abs(value) < 0.2: value = 0
        return value

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
