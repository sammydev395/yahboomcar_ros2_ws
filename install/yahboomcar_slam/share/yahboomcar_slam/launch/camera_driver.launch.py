from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Include joy control launch
    joy_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_ctrl'),
                'launch',
                'yahboom_joy.launch.py'
            ])
        ])
    )

    # Include robot model launch
    model_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_bringup'),
                'launch',
                'yahboomcar_model.launch.py'
            ])
        ])
    )

    return LaunchDescription([
        joy_launch,
        model_launch
    ]) 