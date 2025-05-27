#!/usr/bin/env python3
# coding:utf-8
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

class ROSCtrl:
    def __init__(self, node):
        self.node = node
        self.Joy_active = False
        
        # Create QoS profile
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=3
        )
        
        # Create publishers and subscribers
        self.pub_vel = self.node.create_publisher(Twist, '/cmd_vel', qos_profile)
        self.sub_JoyState = self.node.create_subscription(
            Bool,
            '/JoyState',
            self.JoyStateCallback,
            qos_profile
        )

    def JoyStateCallback(self, msg):
        if not isinstance(msg, Bool): return
        self.Joy_active = msg.data

    def cancel(self):
        self.pub_vel.publish(Twist())
        self.node.destroy_publisher(self.pub_vel)
        self.node.destroy_subscription(self.sub_JoyState)
        self.node.get_logger().info("Shutting down this node.")


class SinglePID:
    def __init__(self, P=0.1, I=0.0, D=0.1):
        self.Kp = P
        self.Ki = I
        self.Kd = D
        print("init_pid: ", P, I, D)
        self.pid_reset()

    def Set_pid(self, P, I, D):
        self.Kp = P
        self.Ki = I
        self.Kd = D
        print("set_pid: ", P, I, D)
        self.pid_reset()

    def pid_compute(self, target, current):
        self.error = target - current
        self.intergral += self.error
        self.derivative = self.error - self.prevError
        result = self.Kp * self.error + self.Ki * self.intergral + self.Kd * self.derivative
        self.prevError = self.error
        return result

    def pid_reset(self):
        self.error = 0
        self.intergral = 0
        self.derivative = 0
        self.prevError = 0
