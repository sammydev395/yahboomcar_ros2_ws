import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    yahboomcar_bringup_pkg = get_package_share_directory('yahboomcar_bringup')
    return LaunchDescription([
        # Include yahboomcar.launch.py (assume it has been migrated)
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(yahboomcar_bringup_pkg, 'launch', 'yahboomcar.launch.py')
            )
        ),
        Node(
            package='imu_calib',
            executable='do_calib',
            name='do_calib',
            output='screen',
            parameters=[{'output_file': os.path.join(yahboomcar_bringup_pkg, 'param', 'imu_calib.yaml')}],
            remappings=[
                ('/sub_imu', '/imu/imu_raw')
            ]
        )
    ]) 