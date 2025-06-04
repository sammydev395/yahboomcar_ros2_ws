#!/usr/bin/env python
# coding: utf-8
import time
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from astra_common import simplePID
from cv_bridge import CvBridge
from std_msgs.msg import Bool
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from yahboomcar_msgs.msg import Position
import cv2 as cv


class ColorTracker(Node):
    def __init__(self):
        super().__init__('color_Tracker')
        self.bridge = CvBridge()
        self.minDist = 1500
        self.Center_x = 0
        self.Center_y = 0
        self.Center_r = 0
        self.Center_prevx = 0
        self.Center_prevr = 0
        self.prev_time = 0
        self.prev_dist = 0
        self.prev_angular = 0
        self.Joy_active = False
        self.Robot_Run = False
        self.dist = []
        self.encoding = ['16UC1', '32FC1']

        # Create QoS profile
        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )

        # Create subscribers and publishers
        self.sub_depth = self.create_subscription(
            Image,
            "/camera/depth/image_raw",
            self.depth_img_Callback,
            qos
        )
        self.sub_JoyState = self.create_subscription(
            Bool,
            '/JoyState',
            self.JoyStateCallback,
            qos
        )
        self.sub_position = self.create_subscription(
            Position,
            "/Current_point",
            self.positionCallback,
            qos
        )
        self.pub_cmdVel = self.create_publisher(Twist, '/cmd_vel', qos)

        # Initialize PID parameters
        self.linear_PID = (3.0, 0.0, 1.0)
        self.angular_PID = (0.5, 0.0, 2.0)
        self.scale = 1000
        self.PID_init()

    def PID_init(self):
        self.linear_pid = simplePID(self.linear_PID[0] / 1000.0, self.linear_PID[1] / 1000.0, self.linear_PID[2] / 1000.0)
        self.angular_pid = simplePID(self.angular_PID[0] / 100.0, self.angular_PID[1] / 100.0, self.angular_PID[2] / 100.0)

    def depth_img_Callback(self, msg):
        if not isinstance(msg, Image): return
        depthFrame = self.bridge.imgmsg_to_cv2(msg, desired_encoding=self.encoding[1])
        self.action = cv.waitKey(1)
        if self.Center_r != 0:
            now_time = time.time()
            if now_time - self.prev_time > 5:
                if self.Center_prevx == self.Center_x and self.Center_prevr == self.Center_r: self.Center_r = 0
                self.prev_time = now_time
            distance = [0, 0, 0, 0, 0]
            if 0 < int(self.Center_y - 3) and int(self.Center_y + 3) < 480 and 0 < int(
                self.Center_x - 3) and int(self.Center_x + 3) < 640:
                distance[0] = depthFrame[int(self.Center_y - 3)][int(self.Center_x - 3)]
                distance[1] = depthFrame[int(self.Center_y + 3)][int(self.Center_x - 3)]
                distance[2] = depthFrame[int(self.Center_y - 3)][int(self.Center_x + 3)]
                distance[3] = depthFrame[int(self.Center_y + 3)][int(self.Center_x + 3)]
                distance[4] = depthFrame[int(self.Center_y)][int(self.Center_x)]
                distance_ = 1000.0
                num_depth_points = 5
                for i in range(5):
                    if 40 < distance[i] < 80000: distance_ += distance[i]
                    else: num_depth_points -= 1
                if num_depth_points == 0: distance_ = self.minDist
                else: distance_ /= num_depth_points
                self.execute(self.Center_x, distance_)
                self.Center_prevx = self.Center_x
                self.Center_prevr = self.Center_r
        else:
            if self.Robot_Run == True:
                self.pub_cmdVel.publish(Twist())
                self.Robot_Run = False
        if self.action == ord('q') or self.action == 113: 
            self.destroy_node()
            rclpy.shutdown()

    def execute(self, point_x, dist):
        if abs(self.prev_dist - dist) > 300:
            self.prev_dist = dist
            return
        if abs(self.prev_angular - point_x) > 300:
            self.prev_angular = point_x
            return
        if self.Joy_active == True: return
        linear_x = self.linear_pid.compute(dist, self.minDist)
        angular_z = self.angular_pid.compute(320, point_x)
        if abs(dist - self.minDist) < 30: linear_x = 0
        if abs(point_x - 320.0) < 30: angular_z = 0
        twist = Twist()
        twist.angular.z = angular_z
        twist.linear.x = linear_x
        self.pub_cmdVel.publish(twist)
        self.Robot_Run = True

    def JoyStateCallback(self, msg):
        if not isinstance(msg, Bool): return
        self.Joy_active = msg.data
        self.pub_cmdVel.publish(Twist())

    def positionCallback(self, msg):
        if not isinstance(msg, Position): return
        self.Center_x = msg.angleX
        self.Center_y = msg.angleY
        self.Center_r = msg.distance


def main(args=None):
    rclpy.init(args=args)
    color_tracker = ColorTracker()
    rclpy.spin(color_tracker)
    color_tracker.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
