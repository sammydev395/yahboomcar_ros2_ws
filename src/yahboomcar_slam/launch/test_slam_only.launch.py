from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Declare launch arguments
    declare_bUseViewer = DeclareLaunchArgument(
        'bUseViewer',
        default_value='false',
        description='Whether to use the ORB-SLAM2 viewer'
    )

    # Test node - just to see if yahboomcar_slam package loads
    test_node = Node(
        package='yahboomcar_slam',
        executable='yahboomcar_slam_node',
        name='yahboomcar_slam_test',
        output='screen'
    )

    return LaunchDescription([
        declare_bUseViewer,
        test_node
    ]) 