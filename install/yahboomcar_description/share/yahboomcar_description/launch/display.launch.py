import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration, Command, PathJoinSubstitution
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    ns = LaunchConfiguration('ns')
    format_arg = LaunchConfiguration('format')
    use_gui = LaunchConfiguration('use_gui')
    robot_type = LaunchConfiguration('robot_type')

    description_pkg = get_package_share_directory('yahboomcar_description')
    urdf_path = os.path.join(description_pkg, 'urdf', 'yahboomcar_' + robot_type.perform({}) + '.urdf')
    xacro_path = os.path.join(description_pkg, 'urdf', 'yahboomcar_X3plus.urdf.xacro_bk')
    rviz_config = os.path.join(description_pkg, 'rviz', 'yahboomcar.rviz')

    robot_description_content = Command([
        'xacro ',
        urdf_path
    ])
    robot_description_xacro_content = Command([
        'xacro ',
        xacro_path,
        ' ns:=', ns
    ])

    return LaunchDescription([
        DeclareLaunchArgument('ns', default_value='robot1'),
        DeclareLaunchArgument('format', default_value='urdf', description='xacro ; urdf'),
        DeclareLaunchArgument('use_gui', default_value='true'),
        DeclareLaunchArgument('robot_type', default_value=os.environ.get('ROBOT_TYPE', 'X3plus'), description='robot_type [X1,X3,X3plus,R2,X7]'),

        # Choose robot_description based on format
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': robot_description_content
            }],
            condition=lambda context: format_arg.perform(context) == 'urdf'
        ),
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': robot_description_xacro_content
            }],
            condition=lambda context: format_arg.perform(context) == 'xacro'
        ),

        # Joint state publisher
        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher_gui',
            output='screen',
            condition=lambda context: use_gui.perform(context).lower() == 'true'
        ),
        Node(
            package='joint_state_publisher',
            executable='joint_state_publisher',
            name='joint_state_publisher',
            output='screen',
            condition=lambda context: use_gui.perform(context).lower() != 'true'
        ),

        # RViz2
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            output='screen'
        ),
    ]) 