from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen',
            respawn=False
        ),
        Node(
            package='yahboomcar_ctrl',
            executable='turtlebot_joy.py',
            name='turtlebot_joy',
            output='screen',
            parameters=[{
                'use_sim_time': False,
                'linear_speed_limit': 2.0,
                'angular_speed_limit': 2.0
            }]
        )
    ])
