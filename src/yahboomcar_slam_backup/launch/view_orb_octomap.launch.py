from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution

def generate_launch_description():
    # RViz node
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=[
            '-d',
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_slam'),
                'rviz',
                'orb_octomap.rviz'
            ])
        ],
        output='screen'
    )

    return LaunchDescription([
        rviz_node
    ]) 