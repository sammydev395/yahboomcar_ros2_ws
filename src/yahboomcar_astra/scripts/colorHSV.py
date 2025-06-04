#!/usr/bin/env python
# coding: utf-8
import os
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from rcl_interfaces.msg import ParameterDescriptor
from ament_index_python.packages import get_package_share_directory
import threading
from astra_common import *
from geometry_msgs.msg import Twist
from yahboomcar_msgs.msg import Position
from sensor_msgs.msg import CompressedImage, Image
from cv_bridge import CvBridge
import cv2 as cv
import time


class ColorIdentify(Node):
    def __init__(self):
        super().__init__('colorHSV')
        self.index = 2
        self.Roi_init = ()
        self.hsv_range = ()
        self.circle = (0, 0, 0)
        self.point_pose = (0, 0, 0)
        self.dyn_update = True
        self.Start_state = True
        self.select_flags = False
        self.gTracker_state = False
        self.windows_name = 'frame'
        self.Track_state = 'identify'
        self.color = color_follow()
        self.cols, self.rows = 0, 0
        self.Mouse_XY = (0, 0)
        
        # Declare parameters
        self.declare_parameter('VideoSwitch', False, 
            ParameterDescriptor(description='Video switch parameter'))
        self.VideoSwitch = self.get_parameter('VideoSwitch').value
        
        # Get package path
        self.hsv_text = os.path.join(get_package_share_directory('yahboomcar_astra'), 'scripts', 'colorHSV.text')
        
        # Create QoS profile
        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10
        )
        
        # Create publishers and subscribers
        self.pub_position = self.create_publisher(Position, "/Current_point", qos)
        self.pub_cmdVel = self.create_publisher(Twist, '/cmd_vel', qos)
        
        if not self.VideoSwitch:
            self.bridge = CvBridge()
            self.pub_rgb = self.create_publisher(Image, "/astraTracker/rgb", qos)
            self.sub_img = self.create_subscription(
                Image, 
                "/camera/rgb/image_raw", 
                self.image_topic,
                qos
            )
        
        self.get_logger().info(f"OpenCV Version: {cv.__version__}")

    def image_topic(self, msg):
        if not isinstance(msg, Image): return
        start = time.time()
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        action = cv.waitKey(10) & 0xFF
        rgb_img, binary = self.process(frame, action)
        end = time.time()
        fps = 1 / (end - start)
        text = "FPS : " + str(int(fps))
        cv.putText(rgb_img, text, (30, 30), cv.FONT_HERSHEY_SIMPLEX, 0.6, (100, 200, 200), 1)
        thread_text = "thread : " + str(len(threading.enumerate()))
        cv.putText(rgb_img, thread_text, (30, 50), cv.FONT_HERSHEY_SIMPLEX, 0.6, (100, 200, 200), 1)
        if len(binary) != 0: cv.imshow(self.windows_name, ManyImgs(1, ([rgb_img, binary])))
        else: cv.imshow(self.windows_name, rgb_img)
        self.pub_rgb.publish(self.bridge.cv2_to_imgmsg(rgb_img, "bgr8"))

    def onMouse(self, event, x, y, flags, param):
        if event == 1:
            self.Track_state = 'init'
            self.select_flags = True
            self.Mouse_XY = (x, y)
        if event == 4:
            self.select_flags = False
            self.Track_state = 'mouse'
        if self.select_flags == True:
            self.cols = min(self.Mouse_XY[0], x), min(self.Mouse_XY[1], y)
            self.rows = max(self.Mouse_XY[0], x), max(self.Mouse_XY[1], y)
            self.Roi_init = (self.cols[0], self.cols[1], self.rows[0], self.rows[1])

    def process(self, rgb_img, action):
        rgb_img = cv.resize(rgb_img, (640, 480))
        binary = []
        if action == 32: self.Track_state = 'tracking'
        elif action == ord('i') or action == ord('I'): self.Track_state = "identify"
        elif action == ord('r') or action == ord('R'): self.Reset()
        elif action == ord('q') or action == ord('Q'): self.destroy_node()
        if self.Track_state == 'init':
            cv.namedWindow(self.windows_name, cv.WINDOW_AUTOSIZE)
            cv.setMouseCallback(self.windows_name, self.onMouse, 0)
            if self.select_flags == True:
                cv.line(rgb_img, self.cols, self.rows, (255, 0, 0), 2)
                cv.rectangle(rgb_img, self.cols, self.rows, (0, 255, 0), 2)
                if self.Roi_init[0] != self.Roi_init[2] and self.Roi_init[1] != self.Roi_init[3]:
                    rgb_img, self.hsv_range = self.color.Roi_hsv(rgb_img, self.Roi_init)
                    self.gTracker_state = True
                    self.dyn_update = True
                else: self.Track_state = 'init'
        elif self.Track_state == "identify":
            if os.path.exists(self.hsv_text): self.hsv_range = read_HSV(self.hsv_text)
            else: self.Track_state = 'init'
        if self.Track_state != 'init':
            if len(self.hsv_range) != 0:
                rgb_img, binary, self.circle = self.color.object_follow(rgb_img, self.hsv_range)
                if self.dyn_update == True:
                    write_HSV(self.hsv_text, self.hsv_range)
                    self.dyn_update = False
        if self.Track_state == 'tracking':
            self.Start_state = True
            if self.circle[2] != 0: threading.Thread(
                target=self.execute, args=(self.circle[0], self.circle[1], self.circle[2])).start()
            if self.point_pose[0] != 0 and self.point_pose[1] != 0: threading.Thread(
                target=self.execute, args=(self.point_pose[0], self.point_pose[1], self.point_pose[2])).start()
        else:
            if self.Start_state == True:
                self.pub_cmdVel.publish(Twist())
                self.Start_state = False
        return rgb_img, binary

    def execute(self, x, y, z):
        position = Position()
        position.angleX = x
        position.angleY = y
        position.distance = z
        self.pub_position.publish(position)

    def Reset(self):
        self.hsv_range = ()
        self.circle = (0, 0, 0)
        self.Mouse_XY = (0, 0)
        self.Track_state = 'init'
        for i in range(3): self.pub_position.publish(Position())
        self.get_logger().info("init succes!!!")


def main(args=None):
    rclpy.init(args=args)
    astra_tracker = ColorIdentify()
    
    if not astra_tracker.VideoSwitch:
        rclpy.spin(astra_tracker)
    else:
        capture = cv.VideoCapture(1)
        cv_edition = cv.__version__
        if cv_edition[0]=='3': capture.set(cv.CAP_PROP_FOURCC, cv.VideoWriter_fourcc(*'XVID'))
        else: capture.set(cv.CAP_PROP_FOURCC, cv.VideoWriter.fourcc('M', 'J', 'P', 'G'))
        capture.set(cv.CAP_PROP_FRAME_WIDTH, 640)
        capture.set(cv.CAP_PROP_FRAME_HEIGHT, 480)
        
        try:
            while capture.isOpened() and rclpy.ok():
                start = time.time()
                ret, frame = capture.read()
                action = cv.waitKey(10) & 0xFF
                frame, binary = astra_tracker.process(frame, action)
                end = time.time()
                fps = 1 / (end - start)
                text = "FPS : " + str(int(fps))
                cv.putText(frame, text, (30, 30), cv.FONT_HERSHEY_SIMPLEX, 0.6, (100, 200, 200), 1)
                if len(binary) != 0: cv.imshow('frame', ManyImgs(1, ([frame, binary])))
                else: cv.imshow('frame', frame)
                if action == ord('q') or action == 113: break
                rclpy.spin_once(astra_tracker, timeout_sec=0.1)
        finally:
            capture.release()
            cv.destroyAllWindows()
            astra_tracker.destroy_node()
            rclpy.shutdown()


if __name__ == '__main__':
    main()


