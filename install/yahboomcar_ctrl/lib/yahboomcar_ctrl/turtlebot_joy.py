#!/usr/bin/env python3
# encoding: utf-8
import getpass
import threading
import time

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist


class JoyTeleop(Node):
    def __init__(self):
        super().__init__('turtlebot_joy')
        
        # Get parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('linear_speed_limit', 0.3),
                ('angular_speed_limit', 1.0),
            ]
        )
        
        # Initialize variables
        self.user_name = getpass.getuser()
        self.linear_speed = 0
        self.angular_speed = 0
        self.Joy_state = False
        self.velocity = Twist()
        self.Joy_time = time.time()
        
        # Get parameters
        self.linear_speed_limit = self.get_parameter('linear_speed_limit').value
        self.angular_speed_limit = self.get_parameter('angular_speed_limit').value
        
        # Create publisher and subscriber
        self.pub_cmdVel = self.create_publisher(Twist, '/cmd_vel', 10)
        self.sub_Joy = self.create_subscription(Joy, '/joy', self.buttonCallback, 10)
        
        # Create timer for periodic tasks
        self.create_timer(0.05, self.timer_callback)  # 20Hz
        
        self.get_logger().info('Turtlebot joy node started')

    def timer_callback(self):
        # Add any periodic tasks here
        pass

    def buttonCallback(self, joy_data):
        if not isinstance(joy_data, Joy):
            return
            
        self.Joy_time = time.time()
        # self.get_logger().info(f'Joy data: {joy_data}')
        # self.get_logger().info(f'Joy axes: {joy_data.axes}')
        
        if self.user_name == "jetson":
            self.linear_speed = joy_data.axes[1] * self.linear_speed_limit
            self.angular_speed = joy_data.axes[2] * self.angular_speed_limit
        else:
            self.linear_speed = joy_data.axes[1] * self.linear_speed_limit
            self.angular_speed = joy_data.axes[3] * self.angular_speed_limit
            
        twist = Twist()
        twist.linear.x = self.linear_speed
        twist.angular.z = self.angular_speed
        self.pub_cmdVel.publish(twist)


def main():
    rclpy.init()
    node = JoyTeleop()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        node.get_logger().error(f'Exception: {e}')
    finally:
        # Clean up
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
