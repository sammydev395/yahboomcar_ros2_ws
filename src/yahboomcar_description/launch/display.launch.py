import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, TextSubstitution
from launch.conditions import LaunchConfigurationEquals
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    ns = LaunchConfiguration('ns')
    format_arg = LaunchConfiguration('format')
    use_gui = LaunchConfiguration('use_gui')
    robot_type = LaunchConfiguration('robot_type')

    description_pkg = get_package_share_directory('yahboomcar_description')

    # Directly build the URDF path
    urdf_path = PathJoinSubstitution([
        description_pkg,
        'urdf',
        TextSubstitution(text='yahboomcar_'),
        robot_type,
        TextSubstitution(text='.urdf')
    ])

    xacro_path = PathJoinSubstitution([
        description_pkg,
        'urdf',
        'yahboomcar_X3plus.urdf.xacro_bk'
    ])
    rviz_config = PathJoinSubstitution([
        description_pkg,
        'rviz',
        'yahboomcar.rviz'
    ])

    return LaunchDescription([
        DeclareLaunchArgument('ns', default_value='robot1'),
        DeclareLaunchArgument('format', default_value='urdf', description='xacro ; urdf'),
        DeclareLaunchArgument('use_gui', default_value='true'),
        DeclareLaunchArgument('robot_type', default_value=os.environ.get('ROBOT_TYPE', 'X3plus'), description='robot_type [X1,X3,X3plus,R2,X7]'),

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': PathJoinSubstitution([
                    description_pkg,
                    'urdf',
                    TextSubstitution(text='yahboomcar_'),
                    robot_type,
                    TextSubstitution(text='.urdf')
                ])
            }],
            condition=LaunchConfigurationEquals('format', 'urdf')
        ),

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': PathJoinSubstitution([
                    description_pkg,
                    'urdf',
                    'yahboomcar_X3plus.urdf.xacro_bk'
                ])
            }],
            condition=LaunchConfigurationEquals('format', 'xacro')
        ),

        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher_gui',
            output='screen',
            condition=LaunchConfigurationEquals('use_gui', 'true')
        ),
        Node(
            package='joint_state_publisher',
            executable='joint_state_publisher',
            name='joint_state_publisher',
            output='screen',
            condition=LaunchConfigurationEquals('use_gui', 'false')
        ),

        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            output='screen'
        ),
    ])
