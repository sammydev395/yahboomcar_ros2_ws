from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, EnvironmentVariable, PathJoinSubstitution
from launch.conditions import LaunchConfigurationEquals
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Declare launch arguments
    declare_bUseViewer = DeclareLaunchArgument(
        'bUseViewer',
        default_value='false',
        description='Whether to use the ORB-SLAM2 viewer'
    )
    
    declare_robot_type = DeclareLaunchArgument(
        'robot_type',
        default_value=EnvironmentVariable('ROBOT_TYPE', default_value='X3plus'),
        description='Robot type [X1,X3,X3plus,R2,X7]'
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

    # Include robot bringup launch
    robot_bringup_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_bringup'),
                'launch',
                'yahboomcar.launch.py'
            ])
        ])
    )

    # Static transform publisher for camera
    camera_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='camera_tf',
        arguments=['0', '0', '0', '1.57', '3.14', '1.57', 'camera_link', 'camera'],
        output='screen'
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
        declare_robot_type,
        camera_launch,
        robot_bringup_launch,
        camera_tf,
        orb_slam_node
    ]) 