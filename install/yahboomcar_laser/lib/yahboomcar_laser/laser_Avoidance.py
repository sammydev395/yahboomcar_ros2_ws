#!/usr/bin/env python3
# coding:utf-8
import math
import numpy as np
import time
from common import *
from time import sleep
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from rcl_interfaces.msg import ParameterDescriptor, ParameterType
from rcl_interfaces.msg import SetParametersResult

RAD2DEG = 180 / math.pi

class LaserAvoid(Node):
    def __init__(self):
        super().__init__('laser_Avoidance')
        
        # Declare parameters
        self.declare_parameter('switch', False)
        self.declare_parameter('linear', 0.3)
        self.declare_parameter('angular', 0.6)
        self.declare_parameter('LaserAngle', 30)
        self.declare_parameter('ResponseDist', 0.40)
        
        # Get parameters
        self.switch = self.get_parameter('switch').value
        self.linear = self.get_parameter('linear').value
        self.angular = self.get_parameter('angular').value
        self.LaserAngle = self.get_parameter('LaserAngle').value
        self.ResponseDist = self.get_parameter('ResponseDist').value
        
        # Add parameter callback
        self.add_on_set_parameters_callback(self.parameters_callback)
        
        # Initialize variables
        self.Moving = False
        self.Right_warning = 0
        self.Left_warning = 0
        self.front_warning = 0
        self.ObstacleValidAngle = 4  # valid
        
        # Create ROS2 objects
        self.ros_ctrl = ROSCtrl(self)
        
        # Create QoS profile
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        )
        
        # Create subscribers
        self.sub_laser = self.create_subscription(
            LaserScan,
            '/scan',
            self.registerScan,
            qos_profile
        )
        
        # Create timer
        self.timer = self.create_timer(0.05, self.timer_callback)  # 20Hz
        
        self.get_logger().info('Laser Avoidance node initialized')

    def parameters_callback(self, params):
        for param in params:
            if param.name == 'switch':
                self.switch = param.value
            elif param.name == 'linear':
                self.linear = param.value
            elif param.name == 'angular':
                self.angular = param.value
            elif param.name == 'LaserAngle':
                self.LaserAngle = param.value
            elif param.name == 'ResponseDist':
                self.ResponseDist = param.value
        return SetParametersResult(successful=True)

    def registerScan(self, scan_data):
        if not isinstance(scan_data, LaserScan): return
        
        ranges = np.array(scan_data.ranges)
        self.Right_warning = 0
        self.Left_warning = 0
        self.front_warning = 0
        
        for i in range(len(ranges)):
            angle = (scan_data.angle_min + scan_data.angle_increment * i) * RAD2DEG
            
            if -10 > angle > -10-self.LaserAngle:
                if ranges[i] < self.ResponseDist: 
                    self.Right_warning += 1
            if 10+self.LaserAngle > angle > 10:
                if ranges[i] < self.ResponseDist: 
                    self.Left_warning += 1
            if abs(angle) < 10:
                if ranges[i] <= self.ResponseDist: 
                    self.front_warning += 1

    def timer_callback(self):
        if self.ros_ctrl.Joy_active or self.switch == True:
            if self.Moving == True:
                self.ros_ctrl.pub_vel.publish(Twist())
                self.Moving = not self.Moving
            return
            
        self.Moving = True
        valid_num = int(self.ObstacleValidAngle/(0.0174533 * RAD2DEG))  # angle_increment is typically ~0.0174533
        twist = Twist()
        
        if self.front_warning > valid_num and self.Left_warning > valid_num and self.Right_warning > valid_num:
            self.get_logger().info('1, there are obstacles in the left and right, turn right')
            twist.linear.x = -0.15
            twist.angular.z = -self.angular
            self.ros_ctrl.pub_vel.publish(twist)
            time.sleep(0.2)
        elif self.front_warning > valid_num and self.Left_warning <= valid_num and self.Right_warning > valid_num:
            self.get_logger().info('2, there is an obstacle in the middle right, turn left')
            twist.linear.x = 0
            twist.angular.z = self.angular
            self.ros_ctrl.pub_vel.publish(twist)
            time.sleep(0.2)
            if self.Left_warning > valid_num and self.Right_warning <= valid_num:
                self.get_logger().info('3, there is an obstacle on the left, turn right')
                twist.linear.x = 0
                twist.angular.z = -self.angular
                self.ros_ctrl.pub_vel.publish(twist)
                time.sleep(0.5)
        elif self.front_warning > valid_num and self.Left_warning > valid_num and self.Right_warning <= valid_num:
            self.get_logger().info('4. There is an obstacle in the middle left, turn right')
            twist.linear.x = 0
            twist.angular.z = -self.angular
            self.ros_ctrl.pub_vel.publish(twist)
            time.sleep(0.2)
            if self.Left_warning <= valid_num and self.Right_warning > valid_num:
                self.get_logger().info('5, there is an obstacle on the left, turn left')
                twist.linear.x = 0
                twist.angular.z = self.angular
                self.ros_ctrl.pub_vel.publish(twist)
                time.sleep(0.5)
        elif self.front_warning > valid_num and self.Left_warning < valid_num and self.Right_warning < valid_num:
            self.get_logger().info('6, there is an obstacle in the middle, turn left')
            twist.linear.x = 0
            twist.angular.z = self.angular
            self.ros_ctrl.pub_vel.publish(twist)
            time.sleep(0.2)
        elif self.front_warning < valid_num and self.Left_warning > valid_num and self.Right_warning > valid_num:
            self.get_logger().info('7. There are obstacles on the left and right, turn right')
            twist.linear.x = 0
            twist.angular.z = -self.angular
            self.ros_ctrl.pub_vel.publish(twist)
            time.sleep(0.4)
        elif self.front_warning < valid_num and self.Left_warning > valid_num and self.Right_warning <= valid_num:
            self.get_logger().info('8, there is an obstacle on the left, turn right')
            twist.linear.x = 0
            twist.angular.z = -self.angular
            self.ros_ctrl.pub_vel.publish(twist)
            time.sleep(0.2)
        elif self.front_warning < valid_num and self.Left_warning <= valid_num and self.Right_warning > valid_num:
            self.get_logger().info('9, there is an obstacle on the right, turn left')
            twist.linear.x = 0
            twist.angular.z = self.angular
            self.ros_ctrl.pub_vel.publish(twist)
            time.sleep(0.2)
        elif self.front_warning <= valid_num and self.Left_warning <= valid_num and self.Right_warning <= valid_num:
            self.get_logger().info('10, no obstacles, go forward')
            twist.linear.x = self.linear
            twist.angular.z = 0
            self.ros_ctrl.pub_vel.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    node = LaserAvoid()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
