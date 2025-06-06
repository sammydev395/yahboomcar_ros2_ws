from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

import os
os.environ['AMENT_PREFIX_PATH'] = '/opt/ros/humble:/home/jetson/yahboomcar_ws/install'
os.environ['RVIZ2_PLUGIN_PATH'] = '/opt/ros/humble/share/rviz_default_plugins/pluginlib'

def generate_launch_description():
    # Include other launch files
    orbbec_camera_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_astra'),
                'launch',
                'astra.launch.py'
            ])
        ])
    )

    yahboom_joy_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_ctrl'),
                'launch',
                'yahboom_joy.launch.py'
            ])
        ])
    )

    yahboomcar_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_bringup'),
                'launch',
                'yahboomcar.launch.py'
            ])
        ])
    )

    # Include robot description launch
    yahboomcar_description_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_description'),
                'launch',
                'display.launch.py'
            ])
        ])
    )

    # KCF Tracker node
    kcf_tracker_node = Node(
        package='yahboomcar_astra',
        executable='KCFTracker_node',
        name='KCF_Tracker',
        output='screen'
    )

    return LaunchDescription([
        orbbec_camera_launch,
        yahboom_joy_launch,
        yahboomcar_launch,
        yahboomcar_description_launch,
        kcf_tracker_node
    ])
