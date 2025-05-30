import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    yahboomcar_bringup_pkg = get_package_share_directory('yahboomcar_bringup')
    ydlidar_ros_driver_pkg = get_package_share_directory('ydlidar_ros_driver')
    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(yahboomcar_bringup_pkg, 'launch', 'bringup.launch.py')
            )
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(ydlidar_ros_driver_pkg, 'launch', 'TG.launch.py')
            )
        ),
        Node(
            package='yahboomcar_bringup',
            executable='patrol.py',
            name='YahboomCarPatrol',
            output='screen',
            parameters=[{'circle_adjust': 2.0}]
        )
    ]) 