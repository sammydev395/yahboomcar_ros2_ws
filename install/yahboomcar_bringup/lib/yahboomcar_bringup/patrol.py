#!/usr/bin/env python3
# coding:utf-8
import math
import numpy as np
from time import sleep
from std_msgs.msg import Bool
from sensor_msgs.msg import LaserScan
from math import radians, copysign, sqrt, pow
from geometry_msgs.msg import Twist, Point, Quaternion
from transform_utils import quat_to_angle, normalize_angle
import rclpy
from rclpy.node import Node
import tf2_ros
from geometry_msgs.msg import TransformStamped

RAD2DEG = 180 / math.pi

class YahboomCarPatrol(Node):
    def __init__(self):
        super().__init__('yahboomcar_patrol')
        self.r = self.create_rate(20)
        self.moving = True
        self.Joy_active = False
        self.command_src = "finish"
        self.warning = 1
        self.SetLoop = False
        self.Linear = 0.5
        self.Angular = 1.0
        self.Length = 1.0
        self.Angle = 360.0
        self.LineScaling = 1.1
        self.RotationScaling = 0.75
        self.LineTolerance = 0.1
        self.RotationTolerance = 0.3
        self.ResponseDist = 0.2
        self.LaserAngle = 20
        self.Command = "finish"
        self.circle_adjust = self.declare_parameter('circle_adjust', 2.0).value
        self.Switch = False
        self.odom_frame = self.declare_parameter('odom_frame', 'odom').value
        self.base_frame = self.declare_parameter('base_frame', 'base_footprint').value
        self.pub_cmdVel = self.create_publisher(Twist, '/cmd_vel', 1)
        self.sub_scan = self.create_subscription(LaserScan, '/scan', self.registerScan, 1)
        self.sub_Joy = self.create_subscription(Bool, '/JoyState', self.JoyStateCallback, 1)
        self.get_logger().info('YahboomCarPatrol node started.')
        self.timer = self.create_timer(0.05, self.process)
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

    def create_rate(self, hz):
        # Helper for ROS2 rate
        return hz

    def dynamic_reconfigure_callback(self, config, level):
        # Not used in ROS2 version, parameters are set via declare_parameter
        pass

    def Triangle(self, index, angle):
        index += 1
        advancing = False
        sleep(0.5)
        if index == 1 or index == 3:
            advancing = self.advancing(self.Length)
        elif index == 2:
            side = sqrt(pow((self.Length), 2) * 2)
            advancing = self.advancing(side)
        sleep(0.5)
        if advancing == True:
            spin = self.Spin(angle)
            if spin == True:
                if index == 1:
                    self.Triangle(index, 135)
                elif index == 2:
                    self.Triangle(index, 90)
                else:
                    self.Command = "finish"
                    return

    def Square(self, index, angle):
        index += 1
        if index == 5:
            self.Command = "finish"
            return
        sleep(0.5)
        advancing = self.advancing(self.Length)
        sleep(0.5)
        if advancing == True:
            spin = self.Spin(angle)
            if spin == True:
                if index == 2:
                    self.Square(index, 90)
                else:
                    self.Square(index, 90)

    def Parallelogram(self, index, angle):
        index += 1
        if index == 5:
            self.Command = "finish"
            return
        sleep(0.5)
        advancing = self.advancing(self.Length)
        sleep(0.5)
        if advancing == True:
            spin = self.Spin(angle)
            if spin == True:
                if index == 2:
                    self.Parallelogram(index, 120)
                else:
                    self.Parallelogram(index, 60)

    def process(self):
        index = 0
        if self.Switch == True:
            if self.Command == "LengthTest":
                advancing = self.advancing(self.Length)
                if advancing == True: self.Command = "finish"
            elif self.Command == "AngleTest":
                spin = self.Spin(self.Angle)
                if spin == True: self.Command = "finish"
            elif self.Command == "Triangle":
                self.Triangle(index, 135)
            elif self.Command == "Square":
                self.Square(index, 90)
            elif self.Command == "Parallelogram":
                self.Parallelogram(index, 120)
            elif self.Command == "Circle":
                spin = self.Spin(360)
                if spin == True: self.Command = "finish"
            if self.Command == "finish":
                self.pub_cmdVel.publish(Twist())
                if self.SetLoop == False:
                    self.Switch = False
                else:
                    self.Command = self.command_src

    def JoyStateCallback(self, msg):
        if not isinstance(msg, Bool): return
        self.Joy_active = msg.data
        if not self.Joy_active: self.pub_cmdVel.publish(Twist())

    def registerScan(self, scan_data):
        if self.ResponseDist == 0: return
        ranges = np.array(scan_data.ranges)
        self.warning = 1
        for i in range(len(ranges)):
            angle = (scan_data.angle_min + scan_data.angle_increment * i) * RAD2DEG
            if abs(angle) < self.LaserAngle :
                if ranges[i] < self.ResponseDist and ranges[i] != 0.0: 
                    self.warning += 1

    def Spin(self, angle):
        target_angle = radians(angle)
        odom_angle = self.get_odom_angle()
        last_angle = odom_angle
        turn_angle = 0
        while True:
            # Simulate ROS2 rate
            sleep(1.0 / 20)
            odom_angle = self.get_odom_angle()
            delta_angle = self.RotationScaling * normalize_angle(odom_angle - last_angle)
            turn_angle += delta_angle
            error = target_angle - turn_angle
            last_angle = odom_angle
            move_cmd = Twist()
            if (abs(error) < self.RotationTolerance) or self.Switch == False:
                self.pub_cmdVel.publish(Twist())
                return True
            if self.Joy_active or self.warning > 10:
                if self.moving == True:
                    self.pub_cmdVel.publish(Twist())
                    self.moving = False
                continue
            else:
                if self.Command == "Circle":
                    length = self.Linear * self.circle_adjust / self.Length
                    move_cmd.linear.x = self.Linear
                    move_cmd.angular.z = copysign(length, error)
                else:
                    move_cmd.angular.z = copysign(self.Angular, error)
                self.pub_cmdVel.publish(move_cmd)
            self.moving = True
        self.pub_cmdVel.publish(Twist())
        return True

    def advancing(self, target_distance):
        position = self.get_position()
        x_start, y_start = position.x, position.y
        while True:
            sleep(1.0 / 20)
            move_cmd = Twist()
            position = self.get_position()
            distance = sqrt(pow((position.x - x_start), 2) + pow((position.y - y_start), 2))
            distance *= self.LineScaling
            error = distance - target_distance
            move_cmd.linear.x = self.Linear
            if abs(error) < self.LineTolerance or not self.Switch: return True
            if self.Joy_active or self.warning > 10:
                if self.moving == True:
                    self.pub_cmdVel.publish(Twist())
                    self.moving = False
                continue
            else: self.pub_cmdVel.publish(move_cmd)
            self.moving = True
        return False

    def get_odom_angle(self):
        try:
            trans = self.tf_buffer.lookup_transform(
                self.odom_frame, self.base_frame, rclpy.time.Time(), timeout=rclpy.duration.Duration(seconds=0.5))
            # Convert quaternion to yaw
            q = trans.transform.rotation
            # Use your quat_to_angle utility or tf_transformations
            return quat_to_angle(q)
        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
            return 0.0

    def get_position(self):
        try:
            trans = self.tf_buffer.lookup_transform(
                self.odom_frame, self.base_frame, rclpy.time.Time(), timeout=rclpy.duration.Duration(seconds=0.5))
            t = trans.transform.translation
            return Point(x=t.x, y=t.y, z=t.z)
        except Exception as e:
            self.get_logger().warn(f"TF lookup failed: {e}")
            return Point(x=0.0, y=0.0, z=0.0)

    def cancel(self):
        self.get_logger().info("Stopping the robot...")
        self.pub_cmdVel.publish(Twist())

if __name__ == '__main__':
    rclpy.init()
    node = YahboomCarPatrol()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.cancel()
    node.destroy_node()
    rclpy.shutdown()
