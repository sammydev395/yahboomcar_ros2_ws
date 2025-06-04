#!/usr/bin/env python3
# encoding: utf-8
# Copyright (c) 2011, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#    * Neither the name of the Willow Garage, Inc. nor the names of its
#      contributors may be used to endorse or promote products derived from
#       this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES LOSS OF USE, DATA, OR PROFITS OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

import sys
import select
import termios
import tty
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

msg = """
Control Your SLAM-Bot!
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .

q/z : increase/decrease max speeds by 10%
w/x : increase/decrease only linear speed by 10%
e/c : increase/decrease only angular speed by 10%
t/T : x and y speed switch
s/S : stop keyboard control
space key, k : force stop
anything else : stop smoothly

CTRL-C to quit
"""

moveBindings = {
    'i': (1, 0),
    'o': (1, -1),
    'j': (0, 1),
    'l': (0, -1),
    'u': (1, 1),
    ',': (-1, 0),
    '.': (-1, 1),
    'm': (-1, -1),
    'I': (1, 0),
    'O': (1, -1),
    'J': (0, 1),
    'L': (0, -1),
    'U': (1, 1),
    'M': (-1, -1),
}

speedBindings = {
    'Q': (1.1, 1.1),
    'Z': (.9, .9),
    'W': (1.1, 1),
    'X': (.9, 1),
    'E': (1, 1.1),
    'C': (1, .9),
    'q': (1.1, 1.1),
    'z': (.9, .9),
    'w': (1.1, 1),
    'x': (.9, 1),
    'e': (1, 1.1),
    'c': (1, .9),
}

def getKey():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist: key = sys.stdin.read(1)
    else: key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def vels(speed, turn):
    return "currently:\tspeed %s\tturn %s " % (speed, turn)

class KeyboardControl(Node):
    def __init__(self):
        super().__init__('keyboard_ctrl')
        
        # Declare parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('linear_speed_limit', 1.0),
                ('angular_speed_limit', 5.0),
            ]
        )
        
        # Get parameters
        self.linear_limit = self.get_parameter('linear_speed_limit').value
        self.angular_limit = self.get_parameter('angular_speed_limit').value
        
        # Create publisher
        self.pub = self.create_publisher(Twist, 'cmd_vel', 1)
        
        # Initialize variables
        self.xspeed_switch = True
        self.speed = 0.2
        self.turn = 1.0
        self.x = 0
        self.th = 0
        self.status = 0
        self.stop = False
        self.count = 0
        
        # Create timer for publishing
        self.create_timer(0.1, self.timer_callback)
        
        self.get_logger().info('Keyboard control node started')
        print(msg)
        print(vels(self.speed, self.turn))

    def timer_callback(self):
        key = getKey()
        if key == "t" or key == "T":
            self.xspeed_switch = not self.xspeed_switch
        elif key == "s" or key == "S":
            self.get_logger().info(f"stop keyboard control: {not self.stop}")
            self.stop = not self.stop
            
        if key in moveBindings.keys():
            self.x = moveBindings[key][0]
            self.th = moveBindings[key][1]
            self.count = 0
        elif key in speedBindings.keys():
            self.speed = self.speed * speedBindings[key][0]
            self.turn = self.turn * speedBindings[key][1]
            self.count = 0
            
            if self.speed > self.linear_limit:
                self.speed = self.linear_limit
            if self.turn > self.angular_limit:
                self.turn = self.angular_limit
                
            print(vels(self.speed, self.turn))
            if (self.status == 14):
                print(msg)
            self.status = (self.status + 1) % 15
        elif key == ' ':
            (self.x, self.th) = (0, 0)
        else:
            self.count = self.count + 1
            if self.count > 4:
                (self.x, self.th) = (0, 0)
            if (key == '\x03'):
                rclpy.shutdown()
                return
                
        twist = Twist()
        if self.xspeed_switch:
            twist.linear.x = self.speed * self.x
        else:
            twist.linear.y = self.speed * self.x
        twist.angular.z = self.turn * self.th
        
        if not self.stop:
            self.pub.publish(twist)

def main():
    settings = termios.tcgetattr(sys.stdin)
    rclpy.init()
    node = KeyboardControl()
    
    try:
        rclpy.spin(node)
    except Exception as e:
        print(e)
    finally:
        # Clean up
        twist = Twist()
        node.pub.publish(twist)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
