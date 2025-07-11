from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Declare launch arguments
    declare_bUseViewer = DeclareLaunchArgument(
        'bUseViewer',
        default_value='true',
        description='Whether to use the ORB-SLAM2 viewer'
    )

    # Include camera launch
    camera_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_astra'),
                'launch',
                'astra.launch.py'
            ])
        ])
    )

    # ORB-SLAM2 node
    orb_slam_node = Node(
        package='ros2_orbslam',
        executable='rgbd',
        name='ORB_SLAM2',
        output='screen',
        parameters=[{
            'bUseViewer': LaunchConfiguration('bUseViewer')
        }],
        arguments=[
            '/home/jetson/yahboomcar_ros2_ws/software/orbslam2/ORB_SLAM2-master/Vocabulary/ORBvoc.txt',
            '/home/jetson/yahboomcar_ws/src/ros2-ORB_SLAM2/src/rgbd/TUM1.yaml'
        ],
        remappings=[
            ('/camera/color/image_raw', '/color/image_raw'),
            ('/camera/depth/image_raw', '/depth/image_raw')
        ]
    )

    return LaunchDescription([
        declare_bUseViewer,
        camera_launch,
        orb_slam_node
    ]) 