#!/bin/bash

# Source ROS2 workspace
source ~/yahboomcar_ros2_ws/install/setup.bash

# Source ORB_SLAM2 setup (if needed)
# source ~/yahboomcar_ros2_ws/software/orbslam2/ORB_SLAM2-master/Examples/ROS/ros2-ORB_SLAM2/install/setup.bash

# Launch the camera ORB SLAM
ros2 launch yahboomcar_slam camera_orb_slam.launch.py "$@" 