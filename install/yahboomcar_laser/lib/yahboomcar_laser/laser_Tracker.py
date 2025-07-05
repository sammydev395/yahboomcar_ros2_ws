#!/usr/bin/env python3
# coding:utf-8
import math
import numpy as np
from common import *
from std_msgs.msg import Bool
from sensor_msgs.msg import LaserScan
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from rcl_interfaces.msg import ParameterDescriptor, ParameterType
from rcl_interfaces.msg import SetParametersResult

RAD2DEG = 180 / math.pi

class LaserTracker(Node):
    def __init__(self):
        super().__init__('laser_Tracker')
        
        # Declare parameters
        self.declare_parameter('switch', False)
        self.declare_parameter('laserAngle', 90)
        self.declare_parameter('priorityAngle', 30)
        self.declare_parameter('ResponseDist', 1.0)
        self.declare_parameter('lin_Kp', 1.5)
        self.declare_parameter('lin_Ki', 0.0)
        self.declare_parameter('lin_Kd', 2.0)
        self.declare_parameter('ang_Kp', 1.5)
        self.declare_parameter('ang_Ki', 0.0)
        self.declare_parameter('ang_Kd', 5.0)
        
        # Get parameters
        self.switch = self.get_parameter('switch').value
        self.laserAngle = self.get_parameter('laserAngle').value
        self.priorityAngle = self.get_parameter('priorityAngle').value
        self.ResponseDist = self.get_parameter('ResponseDist').value
        
        # Initialize variables
        self.Moving = False
        self.Buzzer_state = False
        self.ros_ctrl = ROSCtrl(self)
        self.lin_pid = SinglePID(
            self.get_parameter('lin_Kp').value,
            self.get_parameter('lin_Ki').value,
            self.get_parameter('lin_Kd').value
        )
        self.ang_pid = SinglePID(
            self.get_parameter('ang_Kp').value,
            self.get_parameter('ang_Ki').value,
            self.get_parameter('ang_Kd').value
        )
        
        # Add parameter callback
        self.add_on_set_parameters_callback(self.parameters_callback)
        
        # Create QoS profile
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        )
        
        # Create publishers and subscribers
        self.pub_Buzzer = self.create_publisher(Bool, '/Buzzer', qos_profile)
        self.sub_laser = self.create_subscription(
            LaserScan,
            '/scan',
            self.registerScan,
            qos_profile
        )
        
        # Create timer
        self.timer = self.create_timer(0.05, self.timer_callback)  # 20Hz
        
        self.get_logger().info('Laser Tracker node initialized')

    def parameters_callback(self, params):
        for param in params:
            if param.name == 'switch':
                self.switch = param.value
            elif param.name == 'laserAngle':
                self.laserAngle = param.value
            elif param.name == 'priorityAngle':
                self.priorityAngle = param.value
            elif param.name == 'ResponseDist':
                self.ResponseDist = param.value
            elif param.name == 'lin_Kp':
                self.lin_pid.Set_pid(param.value, self.lin_pid.Ki, self.lin_pid.Kd)
            elif param.name == 'lin_Ki':
                self.lin_pid.Set_pid(self.lin_pid.Kp, param.value, self.lin_pid.Kd)
            elif param.name == 'lin_Kd':
                self.lin_pid.Set_pid(self.lin_pid.Kp, self.lin_pid.Ki, param.value)
            elif param.name == 'ang_Kp':
                self.ang_pid.Set_pid(param.value, self.ang_pid.Ki, self.ang_pid.Kd)
            elif param.name == 'ang_Ki':
                self.ang_pid.Set_pid(self.ang_pid.Kp, param.value, self.ang_pid.Kd)
            elif param.name == 'ang_Kd':
                self.ang_pid.Set_pid(self.ang_pid.Kp, self.ang_pid.Ki, param.value)
        return SetParametersResult(successful=True)

    def registerScan(self, scan_data):
        if not isinstance(scan_data, LaserScan): return
        
        ranges = np.array(scan_data.ranges)
        offset = 0.4
        frontDistList = []
        frontDistIDList = []
        minDistList = []
        minDistIDList = []
        
        for i in range(len(ranges)):
            angle = (scan_data.angle_min + scan_data.angle_increment * i) * RAD2DEG
            
            if abs(angle) < self.priorityAngle:
                if ranges[i] < (self.ResponseDist + offset) and ranges[i] != 0.0:
                    frontDistList.append(ranges[i])
                    frontDistIDList.append(angle)
            elif abs(angle) > self.priorityAngle and abs(angle) < self.laserAngle and ranges[i] != 0.0:
                minDistList.append(ranges[i])
                minDistIDList.append(angle)
        
        if len(frontDistIDList) != 0:
            minDist = min(frontDistList)
            minDistID = frontDistIDList[frontDistList.index(minDist)]
        else:
            minDist = min(minDistList)
            minDistID = minDistIDList[minDistList.index(minDist)]
        
        if self.ros_ctrl.Joy_active or self.switch == True:
            if self.Moving == True:
                self.ros_ctrl.pub_vel.publish(Twist())
                self.Moving = not self.Moving
            return
            
        self.Moving = True
        if minDist <= self.ResponseDist:
            if self.Buzzer_state == False:
                b = Bool()
                b.data = True
                self.pub_Buzzer.publish(b)
                self.Buzzer_state = True
        else:
            if self.Buzzer_state == True:
                self.pub_Buzzer.publish(Bool())
                self.Buzzer_state = False
                
        velocity = Twist()
        if abs(minDist - self.ResponseDist) < 0.1: minDist = self.ResponseDist
        velocity.linear.x = -self.lin_pid.pid_compute(self.ResponseDist, minDist)
        ang_pid_compute = self.ang_pid.pid_compute((180 - abs(minDistID)) / 72, 0)
        if minDistID > 0: velocity.angular.z = ang_pid_compute
        else: velocity.angular.z = -ang_pid_compute
        if ang_pid_compute < 0.2: velocity.angular.z = 0
        if abs(minDistID) < 10: velocity.angular.z = 0
        self.ros_ctrl.pub_vel.publish(velocity)

def main(args=None):
    rclpy.init(args=args)
    node = LaserTracker()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
