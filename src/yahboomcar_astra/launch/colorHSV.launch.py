from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    color_hsv_node = Node(
        package='yahboomcar_astra',
        executable='colorHSV.py',
        name='colorHSV',
        output='screen',
        required=True,
        parameters=[{
            'VideoSwitch': False
        }]
    )

    return LaunchDescription([
        color_hsv_node
    ])
