#!/usr/bin/env python3
# encoding: utf-8
""" calibrate_angular.py - Version 1.1 2013-12-20

    Rotate the robot 360 degrees to check the odometry parameters of the base controller.

    Created for the Pi Robot Project: http://www.pirobot.org
    Copyright (c) 2012 Patrick Goebel.  All rights reserved.

    This program is free software you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation either version 2 of the License, or
    (at your option) any later version.5
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details at:
    
    http://www.gnu.org/licenses/gpl.html
      
"""
from time import time
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, Quaternion
from nav_msgs.msg import Odometry
from math import radians, copysign
from transform_utils import quat_to_angle, normalize_angle
import tf_transformations
from rclpy.qos import QoSProfile


class CalibrateAngular(Node):
    def __init__(self):
        super().__init__('calibrate_angular')
        self.rate = self.declare_parameter('rate', 20).value
        self.test_angle = radians(self.declare_parameter('test_angle', 360.0).value)
        self.speed = self.declare_parameter('speed', 0.5).value
        self.tolerance = radians(self.declare_parameter('tolerance', 1.5).value)
        self.odom_angular_scale_correction = self.declare_parameter('odom_angular_scale_correction', 1.05).value
        self.start_test = self.declare_parameter('start_test', True).value
        self.base_frame = self.declare_parameter('base_frame', 'base_footprint').value
        self.odom_frame = self.declare_parameter('odom_frame', 'odom').value
        self.cmd_vel = self.create_publisher(Twist, '/cmd_vel', 5)
        self.tf_buffer = None
        self.tf_listener = None
        self.timer = self.create_timer(1.0 / self.rate, self.loop)
        self.reverse = 1
        self.test_running = False
        self.get_logger().info('CalibrateAngular node started.')

    def loop(self):
        if not self.start_test or self.test_running:
            return
        self.test_running = True
        self.get_logger().info('Starting angular calibration test.')
        self.odom_angle = self.get_odom_angle()
        last_angle = self.odom_angle
        turn_angle = 0
        test_angle = self.test_angle * self.reverse
        error = test_angle - turn_angle
        self.reverse = -self.reverse
        while abs(error) > self.tolerance and self.start_test:
            start = time()
            move_cmd = Twist()
            move_cmd.angular.z = copysign(self.speed, error)
            self.cmd_vel.publish(move_cmd)
            rclpy.spin_once(self, timeout_sec=1.0 / self.rate)
            self.odom_angle = self.get_odom_angle()
            delta_angle = self.odom_angular_scale_correction * normalize_angle(self.odom_angle - last_angle)
            turn_angle += delta_angle
            error = test_angle - turn_angle
            last_angle = self.odom_angle
            end = time()
            self.get_logger().info(f"time: {start - end}, test_angle: {test_angle}, turn_angle: {turn_angle}")
        self.start_test = False
        self.cmd_vel.publish(Twist())
        self.test_running = False

    def get_odom_angle(self):
        # This is a placeholder for tf2 transform lookup in ROS2
        # In a real robot, use tf2_ros.Buffer and tf2_ros.TransformListener
        # Here, we just return 0.0 for demonstration
        return 0.0

    def shutdown(self):
        self.get_logger().info("Stopping the robot...")
        self.cmd_vel.publish(Twist())

# self.linear_correction  数值越小，直行距离越大。
# self.linear_correction  The smaller the value, the greater the straight distance
# self.angular_correction 数值越小，旋转角度越大。
# self.angular_correction The smaller the value, the greater the rotation angle.

if __name__ == '__main__':
    rclpy.init()
    node = CalibrateAngular()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.shutdown()
    node.destroy_node()
    rclpy.shutdown()
