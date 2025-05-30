import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    yahboomcar_bringup_pkg = get_package_share_directory('yahboomcar_bringup')
    return LaunchDescription([
        Node(
            package='rviz2',
            executable='rviz2',
            name='odom_rviz',
            arguments=['-d', os.path.join(yahboomcar_bringup_pkg, 'rviz', 'odom.rviz')],
            output='screen',
        )
    ]) 