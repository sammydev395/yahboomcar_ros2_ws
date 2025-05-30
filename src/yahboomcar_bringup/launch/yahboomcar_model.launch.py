import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command, EnvironmentVariable
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    use_gui = LaunchConfiguration('use_gui')
    robot_type = LaunchConfiguration('robot_type')
    declare_use_gui = DeclareLaunchArgument('use_gui', default_value='false')
    declare_robot_type = DeclareLaunchArgument('robot_type', default_value=EnvironmentVariable('ROBOT_TYPE', default_value='X3plus'))

    yahboomcar_description_pkg = get_package_share_directory('yahboomcar_description')
    urdf_path = os.path.join(yahboomcar_description_pkg, 'urdf', f'yahboomcar_{robot_type.perform({})}.urdf')

    nodes = []
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
            ('/pub_imu', '/imu/imu_raw'),
            ('/pub_mag', '/mag/mag_raw')
        ],
        condition=lambda context: robot_type.perform(context) == 'X3plus'
    ))
    nodes.append(Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        parameters=[{'robot_description': Command(['xacro ', urdf_path])}]
    ))
    # Static transform publisher for camera/usb_cam
    nodes.append(Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='base_link_to_camera',
        arguments=['0.0484', '0', '0.10403', '-1.57', '0', '-1.57', '/base_link', '/camera', '10'],
        condition=lambda context: robot_type.perform(context) == 'X3'
    ))
    nodes.append(Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='base_link_to_camera',
        arguments=['-0.078645', '0', '0.41955', '0', '0', '0', '/base_link', '/usb_cam', '30'],
        condition=lambda context: robot_type.perform(context) == 'X3plus'
    ))
    return LaunchDescription([
        declare_use_gui,
        declare_robot_type,
        *nodes
    ]) 