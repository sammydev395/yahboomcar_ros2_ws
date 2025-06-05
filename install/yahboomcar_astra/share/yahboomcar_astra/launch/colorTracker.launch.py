from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution, LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Declare launch arguments
    video_switch_arg = DeclareLaunchArgument(
        'VideoSwitch',
        default_value='false',
        description='Video switch parameter'
    )

    # Include other launch files
    yahboom_joy_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_ctrl'),
                'launch',
                'yahboom_joy.launch.py'
            ])
        ])
    )

    orbbec_camera_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('orbbec_camera'),
                'launch',
                'astraproplus.launch.py'
            ])
        ])
    )

    yahboomcar_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_bringup'),
                'launch',
                'yahboomcar.launch.py'
            ])
        ])
    )

    # Color tracker node
    color_tracker_node = Node(
        package='yahboomcar_astra',
        executable='colorTracker_node',
        name='color_tracker',
        output='screen'
    )

    # Color HSV node
    color_hsv_node = Node(
        package='yahboomcar_astra',
        executable='colorHSV_node',
        name='color_hsv',
        output='screen'
    )

    return LaunchDescription([
        video_switch_arg,
        yahboom_joy_launch,
        orbbec_camera_launch,
        yahboomcar_launch,
        color_tracker_node,
        color_hsv_node
    ])
