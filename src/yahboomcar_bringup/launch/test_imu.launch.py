import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, EnvironmentVariable
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    use_rviz = LaunchConfiguration('use_rviz')
    robot_type = LaunchConfiguration('robot_type')
    yahboomcar_bringup_pkg = get_package_share_directory('yahboomcar_bringup')

    declare_use_rviz = DeclareLaunchArgument('use_rviz', default_value='true')
    declare_robot_type = DeclareLaunchArgument('robot_type', default_value=EnvironmentVariable('ROBOT_TYPE', default_value='X3plus'))

    nodes = []

    # Low-level driver node for X3
    nodes.append(Node(
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
        condition=lambda context: robot_type.perform(context) == 'X3'
    ))

    # Odometry publisher
    nodes.append(Node(
        package='yahboomcar_bringup',
        executable='base_node',
        name='odometry_publisher',
        parameters=[
            {'odom_frame': 'odom'},
            {'base_footprint_frame': 'base_footprint'},
            {'linear_scale_x': 1.1},
            {'linear_scale_y': 1.0}
        ],
        remappings=[
            ('/sub_vel', '/vel_raw'),
            ('/pub_odom', '/odom_raw')
        ]
    ))

    # IMU filter node
    nodes.append(Node(
        package='imu_filter_madgwick',
        executable='imu_filter_node',
        name='imu_filter_madgwick',
        output='screen',
        parameters=[
            {'fixed_frame': 'base_link'},
            {'use_mag': False},
            {'publish_tf': False},
            {'use_magnetic_field_msg': False},
            {'world_frame': 'enu'},
            {'orientation_stddev': 0.05},
            {'angular_scale': 1.0}
        ],
        remappings=[
            ('/sub_imu', '/imu/imu_raw'),
            ('/sub_mag', '/mag/mag_raw'),
            ('/pub_imu', '/imu/imu_data'),
            ('/pub_mag', '/mag/mag_field')
        ]
    ))

    # RViz node
    nodes.append(Node(
        package='rviz2',
        executable='rviz2',
        name='odom_rviz',
        arguments=['-d', os.path.join(yahboomcar_bringup_pkg, 'rviz', 'test_imu.rviz')],
        output='screen',
        condition=lambda context: use_rviz.perform(context).lower() == 'true'
    ))

    return LaunchDescription([
        declare_use_rviz,
        declare_robot_type,
        *nodes
    ]) 