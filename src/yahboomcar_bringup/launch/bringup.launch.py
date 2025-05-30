import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command, EnvironmentVariable
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    use_gui = LaunchConfiguration('use_gui')
    use_rviz = LaunchConfiguration('use_rviz')
    robot_type = LaunchConfiguration('robot_type')

    yahboomcar_description_pkg = get_package_share_directory('yahboomcar_description')
    yahboomcar_bringup_pkg = get_package_share_directory('yahboomcar_bringup')
    urdf_path = os.path.join(yahboomcar_description_pkg, 'urdf', f'yahboomcar_{robot_type.perform({})}.urdf')

    # Arguments
    declare_use_gui = DeclareLaunchArgument('use_gui', default_value='false')
    declare_use_rviz = DeclareLaunchArgument('use_rviz', default_value='false')
    declare_robot_type = DeclareLaunchArgument('robot_type', default_value=EnvironmentVariable('ROBOT_TYPE', default_value='X3plus'))

    # Nodes
    nodes = []

    # Robot description
    nodes.append(Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        parameters=[{'robot_description': Command(['xacro ', urdf_path])}]
    ))

    # Low-level driver node (example for X3plus)
    nodes.append(Node(
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
            ('/pub_imu', '/imu/data_raw'),
            ('/pub_mag', '/mag/mag_raw')
        ],
        condition=lambda context: robot_type.perform(context) == 'X3plus'
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
            {'linear_scale_y': 0.95}
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
            {'angular_scale': 1.03}
        ],
        remappings=[
            ('/sub_imu', '/imu/imu_raw'),
            ('/sub_mag', '/mag/mag_raw'),
            ('/pub_imu', '/imu/imu_data'),
            ('/pub_mag', '/mag/mag_field')
        ]
    ))

    # EKF localization node
    nodes.append(Node(
        package='robot_localization',
        executable='ekf_localization_node',
        name='ekf_localization',
        output='screen',
        parameters=[
            {'odom_frame': '/odom'},
            {'world_frame': '/odom'},
            {'base_link_frame': '/base_footprint'}
        ],
        remappings=[
            ('odometry/filtered', 'odom'),
            ('/imu0', '/imu/data'),
            ('/odom0', 'odom_raw')
        ],
        # Load params from yaml
        parameters=[os.path.join(yahboomcar_bringup_pkg, 'param', 'robot_localization.yaml')]
    ))

    # Joy control node (include)
    # In ROS2, use IncludeLaunchDescription if needed

    # RViz node
    nodes.append(Node(
        package='rviz2',
        executable='rviz2',
        name='odom_rviz',
        arguments=['-d', os.path.join(yahboomcar_bringup_pkg, 'rviz', 'odom.rviz')],
        output='screen',
        condition=lambda context: use_rviz.perform(context).lower() == 'true'
    ))

    return LaunchDescription([
        declare_use_gui,
        declare_use_rviz,
        declare_robot_type,
        *nodes
    ]) 