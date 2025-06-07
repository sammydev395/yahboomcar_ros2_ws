import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from rclpy.qos import qos_profile_sensor_data

def joy_cb(msg):
    print("Joy message received:", msg)

rclpy.init()
node = Node('joy_test')
sub = node.create_subscription(Joy, 'joy', joy_cb, qos_profile_sensor_data)
rclpy.spin(node)