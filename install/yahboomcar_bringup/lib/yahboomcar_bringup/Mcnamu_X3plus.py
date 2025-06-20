#!/usr/bin/env python3
# encoding: utf-8
import sys
import math
import time
import rclpy
from rclpy.node import Node
import random
import threading
import numpy as np
from math import pi
from time import sleep
from yahboomcar_msgs.msg import ArmJoint
from yahboomcar_msgs.srv import RobotArmArray
from Rosmaster_Lib import Rosmaster
from geometry_msgs.msg import Twist
from std_msgs.msg import String, Float32, Int32, Bool
from sensor_msgs.msg import Imu, MagneticField, JointState
import tf2_ros
from geometry_msgs.msg import TransformStamped

class YahboomcarDriver(Node):
    def __init__(self):
        super().__init__('driver_node')
        self.RA2DE = 180 / pi
        self.car = Rosmaster()
        self.car.set_car_type(2)
        self.last_update_time = 1
        self.pos = [0, 0, 0, 0]
        self.imu_link = self.declare_parameter('imu_link', 'imu_link').value
        self.Prefix = self.declare_parameter('prefix', '').value
        self.xlinear_limit = self.declare_parameter('xlinear_speed_limit', 1.0).value
        self.ylinear_limit = self.declare_parameter('ylinear_speed_limit', 1.0).value
        self.angular_limit = self.declare_parameter('angular_speed_limit', 5.0).value
        self.sub_cmd_vel = self.create_subscription(Twist, 'cmd_vel', self.cmd_vel_callback, 100)
        self.sub_RGBLight = self.create_subscription(Int32, 'RGBLight', self.RGBLightcallback, 100)
        self.sub_Buzzer = self.create_subscription(Bool, 'Buzzer', self.Buzzercallback, 100)
        self.sub_Arm = self.create_subscription(ArmJoint, 'TargetAngle', self.Armcallback, 1000)
        self.ArmPubUpdate = self.create_publisher(ArmJoint, 'ArmAngleUpdate', 1000)
        self.EdiPublisher = self.create_publisher(Float32, 'edition', 100)
        self.volPublisher = self.create_publisher(Float32, 'voltage', 100)
        self.staPublisher = self.create_publisher(JointState, 'joint_states', 100)
        self.velPublisher = self.create_publisher(Twist, '/pub_vel', 100)
        self.imuPublisher = self.create_publisher(Imu, '/pub_imu', 100)
        self.magPublisher = self.create_publisher(MagneticField, '/pub_mag', 100)
        self.srv_armAngle = self.create_service(RobotArmArray, 'CurrentAngle', self.srv_Armcallback)
        self._shutdown = False
        self.car.create_receive_threading()
        self.car.set_car_motion(0, 0, 0)
        self.joints = [90, 145, 0, 45, 90, 30]
        self.car.set_uart_servo_angle_array(self.joints, 1000)
        self.pub_thread = threading.Thread(target=self.pub_data)
        self.pub_thread.daemon = True
        self.pub_thread.start()
        self.get_logger().info('Yahboomcar X3plus driver node started.')
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        self.last_arm_command_time = 0
        self.min_command_interval = 0.05  # 50ms minimum between commands

    def safe_float(self, x, fallback=0.0):
        try:
            return float(x)
        except (ValueError, TypeError):
            return fallback

    def pub_data(self):
        while rclpy.ok() and not self._shutdown:
            sleep(0.05)
            imu = Imu()
            twist = Twist()
            battery = Float32()
            edition = Float32()
            mag = MagneticField()
            version = self.car.get_version()
            try:
                edition.data = float(version)
            except (ValueError, TypeError):
                self.get_logger().error(f"Invalid version format: {version}")
                edition.data = 0.0
            battery.data = self.car.get_battery_voltage()
            ax, ay, az = [self.safe_float(v) for v in self.car.get_accelerometer_data()]
            gx, gy, gz = [self.safe_float(v) for v in self.car.get_gyroscope_data()]
            mx, my, mz = [self.safe_float(v) for v in self.car.get_magnetometer_data()]
            vx, vy, angular = [self.safe_float(v) for v in self.car.get_motion_data()]
            imu.header.stamp = self.get_clock().now().to_msg()
            imu.header.frame_id = self.imu_link
            imu.linear_acceleration.x = ax
            imu.linear_acceleration.y = ay
            imu.linear_acceleration.z = az
            imu.angular_velocity.x = gx
            imu.angular_velocity.y = gy
            imu.angular_velocity.z = gz
            mag.header.stamp = self.get_clock().now().to_msg()
            mag.header.frame_id = self.imu_link
            mag.magnetic_field.x = mx
            mag.magnetic_field.y = my
            mag.magnetic_field.z = mz
            twist.linear.x = vx
            twist.linear.y = vy
            twist.angular.z = angular
            self.velPublisher.publish(twist)
            self.imuPublisher.publish(imu)
            self.magPublisher.publish(mag)
            self.volPublisher.publish(battery)
            self.EdiPublisher.publish(edition)
            self.joints_states_update()

    def Armcallback(self, msg):
        if not isinstance(msg, ArmJoint): return
        
        # Add debouncing
        current_time = time.time()
        if current_time - self.last_arm_command_time < self.min_command_interval:
            return  # Skip if too soon
        self.last_arm_command_time = current_time
        
        arm_joint = ArmJoint()
        
        if hasattr(msg, 'joints') and len(msg.joints) != 0:
            # Handle array of joints - send individually like backend
            arm_joint.joints = self.joints
            for i, angle in enumerate(msg.joints):
                servo_id = i + 1
                # Apply angle conversion like backend (for joints 2-4)
                if 1 < servo_id < 5:
                    converted_angle = 180 - angle
                else:
                    converted_angle = angle
                # Single call per joint with proper delay
                self.car.set_uart_servo_angle(servo_id, converted_angle, msg.run_time)
                self.joints[i] = angle
                sleep(0.02)  # 20ms delay between joints like backend
            self.ArmPubUpdate.publish(arm_joint)
        else:
            # Handle single joint
            arm_joint.id = msg.id
            arm_joint.angle = msg.angle
            # Apply angle conversion like backend (for joints 2-4)
            if 1 < msg.id < 5:
                converted_angle = 180 - msg.angle
            else:
                converted_angle = msg.angle
            # Single call with proper delay
            self.car.set_uart_servo_angle(msg.id, converted_angle, msg.run_time)
            self.joints[msg.id - 1] = msg.angle
            self.ArmPubUpdate.publish(arm_joint)
            sleep(0.02)  # 20ms delay like backend
        
        self.joints_states_update()

    def srv_Armcallback(self, request, response):
        joints = self.car.get_uart_servo_angle_array()
        if joints is None or len(joints) != 6:
            self.get_logger().warn("Failed to read joint angles, returning last known or safe default.")
            response.angles = [float(j) for j in getattr(self, 'joints', [90, 145, 0, 45, 90, 30])]
        else:
            response.angles = [float(j) for j in joints]
            self.joints = joints
        return response

    def RGBLightcallback(self, msg):
        if not isinstance(msg, Int32): return
        for i in range(3):
            self.car.set_colorful_effect(msg.data, 6, parm=1)
            sleep(0.01)

    def Buzzercallback(self, msg):
        if not isinstance(msg, Bool): return
        if msg.data:
            for i in range(3):
                self.car.set_beep(1)
                sleep(0.01)
        else:
            for i in range(3):
                self.car.set_beep(0)
                sleep(0.01)

    def cmd_vel_callback(self, msg):
        if not isinstance(msg, Twist): return
        vx = msg.linear.x
        vy = msg.linear.y
        angular = msg.angular.z
        self.car.set_car_motion(vx, vy, angular)

    def joints_states_update(self):
        state = JointState()
        state.header.stamp = self.get_clock().now().to_msg()
        state.header.frame_id = "joint_states"
        if len(self.Prefix) == 0:
            state.name = ["arm_joint1", "arm_joint2", "arm_joint3", "arm_joint4", "arm_joint5", "grip_joint"]
        else:
            state.name = [self.Prefix + "/arm_joint1", self.Prefix + "/arm_joint2",
                          self.Prefix + "/arm_joint3", self.Prefix + "/arm_joint4",
                          self.Prefix + "/arm_joint5", self.Prefix + "/grip_joint"]
        joints = self.joints[:]
        joints[5] = np.interp(joints[5], [30, 180], [0, 90])
        mid = np.array([90, 90, 90, 90, 90, 90])
        array = np.array(np.array(joints) - mid)
        DEG2RAD = np.array([pi / 180])
        position_src = list(np.dot(array.reshape(-1, 1), DEG2RAD))
        state.position = position_src
        self.staPublisher.publish(state)

    def destroy_node(self):
        self._shutdown = True
        self.car.set_car_motion(0, 0, 0)
        super().destroy_node()

if __name__ == '__main__':
    rclpy.init()
    node = YahboomcarDriver()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

