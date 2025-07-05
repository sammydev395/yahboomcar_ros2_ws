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
                'astrapro.launch.py'
            ])
        ])
    )

    # ORB-SLAM2 node
    orb_slam_node = Node(
        package='ORB_SLAM2',
        executable='RGBD_pose',
        name='ORB_SLAM2',
        output='screen',
        parameters=[{
            'bUseViewer': LaunchConfiguration('bUseViewer')
        }],
        arguments=[
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_slam'),
                'param',
                'ORBvoc.txt'
            ]),
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_slam'),
                'param',
                'astra.yaml'
            ])
        ],
        remappings=[
            ('/camera/depth_registered/image_raw', '/camera/depth/image_raw'),
            ('/camera/rgb/image_raw', '/camera/rgb/image_raw')
        ]
    )

    return LaunchDescription([
        declare_bUseViewer,
        camera_launch,
        orb_slam_node
    ]) 