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
        super().__init__('twist_joy')
        
        # Get parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('linear_speed_limit', 2.0),
                ('angular_speed_limit', 2.0),
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
        self.pub_cmdVel = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.sub_Joy = self.create_subscription(Joy, '/joy', self.buttonCallback, 10)
        
        # Create timer for velocity publishing
        self.create_timer(0.05, self.pub_vel)  # 20Hz
        
        self.get_logger().info('Twist joy node started')

    def pub_vel(self):
        now_time = time.time()
        if now_time - self.Joy_time > 1:
            if self.Joy_state:
                self.pub_cmdVel.publish(Twist())
                self.Joy_state = False
            self.Joy_time = now_time
            
        if self.linear_speed == self.angular_speed == 0:
            if self.Joy_state:
                self.pub_cmdVel.publish(Twist())
                self.Joy_state = False
        else:
            twist = Twist()
            twist.linear.x = self.linear_speed
            twist.angular.z = self.angular_speed
            self.pub_cmdVel.publish(twist)
            self.Joy_state = True

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
