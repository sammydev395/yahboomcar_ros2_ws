#!/usr/bin/env python3
# encoding: utf-8
""" calibrate_linear.py - Version 1.1 2013-12-20

    Move the robot 1.0 meter to check on the PID parameters of the base controller.

    Created for the Pi Robot Project: http://www.pirobot.org
    Copyright (c) 2012 Patrick Goebel.  All rights reserved.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.5
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details at:
    http://www.gnu.org/licenses/gpl.html
      
"""
from time import time
import rclpy
from rclpy.node import Node
from math import copysign, sqrt, pow
from geometry_msgs.msg import Twist, Point
from transform_utils import quat_to_angle, normalize_angle


class CalibrateLinear(Node):
    def __init__(self):
        super().__init__('calibrate_linear')
        self.rate = self.declare_parameter('rate', 20).value
        self.test_distance = self.declare_parameter('test_distance', 1.0).value
        self.speed = self.declare_parameter('speed', 0.5).value
        self.tolerance = self.declare_parameter('tolerance', 0.03).value
        self.odom_linear_scale_correction = self.declare_parameter('odom_linear_scale_correction', 1.0).value
        self.start_test = self.declare_parameter('start_test', True).value
        self.direction = self.declare_parameter('direction', 1).value
        self.base_frame = self.declare_parameter('base_frame', 'base_footprint').value
        self.odom_frame = self.declare_parameter('odom_frame', 'odom').value
        self.cmd_vel = self.create_publisher(Twist, '/cmd_vel', 5)
        self.timer = self.create_timer(1.0 / self.rate, self.loop)
        self.position = Point()
        self.x_start = 0.0
        self.y_start = 0.0
        self.robot_stop = False
        self.test_running = False
        self.get_logger().info('CalibrateLinear node started.')

    def loop(self):
        if not self.start_test or self.test_running:
            return
        self.test_running = True
        self.get_logger().info('Starting linear calibration test.')
        self.position = self.get_position()
        self.x_start = self.position.x
        self.y_start = self.position.y
        while self.start_test:
            move_cmd = Twist()
            self.position = self.get_position()
            distance = sqrt(pow((self.position.x - self.x_start), 2) + pow((self.position.y - self.y_start), 2))
            distance *= self.odom_linear_scale_correction
            error = distance - self.test_distance
            if not self.start_test or abs(error) < self.tolerance:
                self.start_test = False
                break
            else:
                if self.direction:
                    move_cmd.linear.x = copysign(self.speed, -1 * error)
                else:
                    move_cmd.linear.y = copysign(self.speed, -1 * error)
            self.cmd_vel.publish(move_cmd)
            rclpy.spin_once(self, timeout_sec=1.0 / self.rate)
        self.cmd_vel.publish(Twist())
        self.test_running = False

    def get_position(self):
        # This is a placeholder for tf2 transform lookup in ROS2
        # In a real robot, use tf2_ros.Buffer and tf2_ros.TransformListener
        # Here, we just return Point(0,0,0) for demonstration
        return Point(x=0.0, y=0.0, z=0.0)

    def shutdown(self):
        self.get_logger().info("Stopping the robot...")
        self.cmd_vel.publish(Twist())


if __name__ == '__main__':
    rclpy.init()
    node = CalibrateLinear()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.shutdown()
    node.destroy_node()
    rclpy.shutdown()