from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Start the turtle node
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim_node',
            output='screen',
            respawn=False
        ),
        # Start the node for obtaining wireless handle information
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen',
            respawn=False
        ),
        # Start the wireless controller node
        Node(
            package='yahboomcar_ctrl',
            executable='twist_joy.py',
            name='twist_joy',
            output='screen',
            parameters=[{
                'use_sim_time': False,
                'linear_speed_limit': 2.0,
                'angular_speed_limit': 2.0
            }]
        )
    ])
