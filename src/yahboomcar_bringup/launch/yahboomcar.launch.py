import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, EnvironmentVariable
from launch.conditions import LaunchConfigurationEquals
from launch_ros.actions import Node

def generate_launch_description():
    robot_type = LaunchConfiguration('robot_type')
    declare_robot_type = DeclareLaunchArgument('robot_type', default_value=EnvironmentVariable('ROBOT_TYPE', default_value='X3plus'))

    # X3 robot node
    x3_node = Node(
        package='yahboomcar_bringup',
        executable='Mcnamu_driver.py',
        name='driver_node',
        output='screen',
        parameters=[
            {'xlinear_speed_limit': 1.0},
            {'ylinear_speed_limit': 1.0},
            {'angular_speed_limit': 5.0},
            {'imu_link': 'imu_link'}
        ],
        remappings=[
            ('/pub_vel', '/vel_raw'),
            ('/pub_imu', '/imu/imu_raw'),
            ('/pub_mag', '/mag/mag_raw')
        ],
        condition=LaunchConfigurationEquals('robot_type', 'X3')
    )

    # X3plus robot node
    x3plus_node = Node(
        package='yahboomcar_bringup',
        executable='Mcnamu_X3plus.py',
        name='driver_node',
        output='screen',
        parameters=[
            {'xlinear_speed_limit': 0.7},
            {'ylinear_speed_limit': 0.7},
            {'angular_speed_limit': 3.2},
            {'imu_link': 'imu_link'}
        ],
        remappings=[
            ('/pub_vel', '/vel_raw'),
            ('/pub_imu', '/imu/imu_raw'),
            ('/pub_mag', '/mag/mag_raw')
        ],
        condition=LaunchConfigurationEquals('robot_type', 'X3plus')
    )

    return LaunchDescription([
        declare_robot_type,
        x3_node,
        x3plus_node
    ]) 