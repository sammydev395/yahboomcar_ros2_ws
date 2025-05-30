#!/usr/bin/env python3
# encoding: utf-8
import sys
import math
import time
import rclpy
from rclpy.node import Node
import random
import threading
from math import pi
from time import sleep
from sensor_msgs.msg import Imu, MagneticField, JointState
from Rosmaster_Lib import Rosmaster
from geometry_msgs.msg import Twist
from std_msgs.msg import String, Float32, Int32, Bool

class YahboomcarDriver(Node):
    def __init__(self):
        super().__init__('driver_node')
        self.RA2DE = 180 / pi
        self.car = Rosmaster()
        self.car.set_car_type(1)
        self.last_update_time = 0
        self.imu_link = self.declare_parameter('imu_link', 'imu_link').value
        self.Prefix = self.declare_parameter('prefix', '').value
        self.xlinear_limit = self.declare_parameter('xlinear_speed_limit', 1.0).value
        self.ylinear_limit = self.declare_parameter('ylinear_speed_limit', 1.0).value
        self.angular_limit = self.declare_parameter('angular_speed_limit', 5.0).value
        self.sub_cmd_vel = self.create_subscription(Twist, 'cmd_vel', self.cmd_vel_callback, 100)
        self.sub_RGBLight = self.create_subscription(Int32, 'RGBLight', self.RGBLightcallback, 100)
        self.sub_Buzzer = self.create_subscription(Bool, 'Buzzer', self.Buzzercallback, 100)
        self.EdiPublisher = self.create_publisher(Float32, 'edition', 100)
        self.volPublisher = self.create_publisher(Float32, 'voltage', 100)
        self.staPublisher = self.create_publisher(JointState, 'joint_states', 100)
        self.velPublisher = self.create_publisher(Twist, '/pub_vel', 100)
        self.imuPublisher = self.create_publisher(Imu, '/pub_imu', 100)
        self.magPublisher = self.create_publisher(MagneticField, '/pub_mag', 100)
        self._shutdown = False
        self.car.create_receive_threading()
        self.pub_thread = threading.Thread(target=self.pub_data)
        self.pub_thread.daemon = True
        self.pub_thread.start()
        self.get_logger().info('Yahboomcar driver node started.')

    def destroy_node(self):
        self._shutdown = True
        super().destroy_node()

    def joint_states_update(self):
        state = JointState()
        state.header.stamp = self.get_clock().now().to_msg()
        state.header.frame_id = "joint_states"
        if len(self.Prefix) == 0:
            state.name = ["front_right_joint", "front_left_joint",
                          "back_right_joint", "back_left_joint"]
        else:
            state.name = [self.Prefix + "/front_right_joint", self.Prefix + "/front_left_joint",
                          self.Prefix + "/back_right_joint", self.Prefix + "/back_left_joint"]
        i = random.uniform(-3.14, 3.14)
        state.position = [i, i, i, i]
        self.staPublisher.publish(state)

    def pub_data(self):
        while rclpy.ok() and not self._shutdown:
            sleep(0.05)
            imu = Imu()
            twist = Twist()
            battery = Float32()
            edition = Float32()
            mag = MagneticField()
            edition.data = self.car.get_version()
            battery.data = self.car.get_battery_voltage()
            ax, ay, az = self.car.get_accelerometer_data()
            gx, gy, gz = self.car.get_gyroscope_data()
            mx, my, mz = self.car.get_magnetometer_data()
            vx, vy, angular = self.car.get_motion_data()
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
        self.joint_states_update()

if __name__ == '__main__':
    rclpy.init()
    node = YahboomcarDriver()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
