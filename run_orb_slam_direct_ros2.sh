#!/bin/bash

# Set ORB_SLAM2 environment for ROS2
export ORB_SLAM2_PATH=~/yahboomcar_ros2_ws/software/orbslam2/ORB_SLAM2-master/Examples/ROS/ros2-ORB_SLAM2/install/ros2_orbslam/lib/ros2_orbslam
export LD_LIBRARY_PATH=~/yahboomcar_ros2_ws/software/ORB_SLAM2/lib:$LD_LIBRARY_PATH

# Source ROS2 workspace
source ~/yahboomcar_ros2_ws/install/setup.bash

# Get the orb_slam_type argument (default to mono)
ORB_SLAM_TYPE=${1:-mono}

echo "Starting ORB_SLAM2 ROS2 with type: $ORB_SLAM_TYPE using Astra camera"

# Launch the camera and other nodes first
ros2 launch yahboomcar_slam camera_orb_slam.launch.py orb_slam_type:=$ORB_SLAM_TYPE &
CAMERA_PID=$!

# Wait a moment for camera to start
sleep 3

# Launch ORB_SLAM2 directly based on type
case $ORB_SLAM_TYPE in
    "mono")
        echo "Starting ORB_SLAM2 Mono..."
        $ORB_SLAM2_PATH/mono ~/yahboomcar_ros2_ws/software/ORB_SLAM2/Vocabulary/ORBvoc.txt ~/yahboomcar_ws/src/yahboomcar_slam/param/astra.yaml
        ;;
    "rgbd")
        echo "Starting ORB_SLAM2 RGBD..."
        $ORB_SLAM2_PATH/rgbd ~/yahboomcar_ros2_ws/software/ORB_SLAM2/Vocabulary/ORBvoc.txt ~/yahboomcar_ws/src/yahboomcar_slam/param/astra.yaml
        ;;
    "rgbd_pose")
        echo "Starting ORB_SLAM2 RGBD Pose..."
        $ORB_SLAM2_PATH/rgbd_pose ~/yahboomcar_ros2_ws/software/ORB_SLAM2/Vocabulary/ORBvoc.txt ~/yahboomcar_ws/src/yahboomcar_slam/param/astra.yaml
        ;;
    "stereo")
        echo "Starting ORB_SLAM2 Stereo..."
        $ORB_SLAM2_PATH/stereo ~/yahboomcar_ros2_ws/software/ORB_SLAM2/Vocabulary/ORBvoc.txt ~/yahboomcar_ws/src/yahboomcar_slam/param/astra.yaml
        ;;
    *)
        echo "Unknown ORB_SLAM type: $ORB_SLAM_TYPE"
        echo "Available types: mono, rgbd, rgbd_pose, stereo"
        kill $CAMERA_PID
        exit 1
        ;;
esac

# Cleanup
kill $CAMERA_PID 