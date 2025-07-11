from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Declare launch arguments
    declare_frame_id = DeclareLaunchArgument(
        'frame_id',
        default_value='odom',
        description='Frame ID for octomap'
    )
    
    declare_use_rviz = DeclareLaunchArgument(
        'use_rviz',
        default_value='true',
        description='Whether to use RViz'
    )
    
    declare_use_viewer = DeclareLaunchArgument(
        'use_viewer',
        default_value='false',
        description='Whether to use the pointcloud viewer'
    )
    
    declare_local_frame_id = DeclareLaunchArgument(
        'local_frame_id',
        default_value='camera',
        description='Local frame ID for pointcloud mapping'
    )
    
    declare_global_frame_id = DeclareLaunchArgument(
        'global_frame_id',
        default_value='world',
        description='Global frame ID for pointcloud mapping'
    )

    # Static transform publisher for odom to world
    odom_to_world_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='odom_to_world_tf',
        arguments=['0', '0', '0', '1.57', '3.14', '1.57', 'odom', 'world'],
        output='screen'
    )

    # Pointcloud mapping node
    pointcloud_mapping_node = Node(
        package='yahboomcar_slam',
        executable='pointcloud_mapping',
        name='pointcloud_mapping',
        output='screen',
        parameters=[{
            'topicColor': '/ORB_SLAM2/RGB/Image',
            'topicDepth': '/ORB_SLAM2/Depth/Image',
            'topicTcw': '/ORB_SLAM2/CameraPose',
            'local_frame_id': LaunchConfiguration('local_frame_id'),
            'global_frame_id': LaunchConfiguration('global_frame_id'),
            'node_path': PathJoinSubstitution([
                FindPackageShare('yahboomcar_slam')
            ]),
            'fx': 615.50506,
            'fy': 623.69024,
            'cx': 365.84388,
            'cy': 238.778,
            'resolution': 0.01,
            'depthfactor': 1.0,
            'queueSize': 10,
            'buseExact': 0,
            'use_viewer': LaunchConfiguration('use_viewer')
        }]
    )

    # Octomap server node
    octomap_server_node = Node(
        package='octomap_server',
        executable='octomap_server_node',
        name='octomap_server',
        parameters=[{
            'resolution': 0.12,
            'frame_id': LaunchConfiguration('frame_id'),
            'sensor_model/max_range': 100.0,
            'latch': True,
            'pointcloud_max_z': 2,
            'pointcloud_min_z': -100
        }],
        remappings=[
            ('/cloud_in', '/camera/depth/points')
        ]
    )

    # RViz launch
    rviz_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('yahboomcar_slam'),
                'launch',
                'view_orb_octomap.launch.py'
            ])
        ]),
        condition=IfCondition(LaunchConfiguration('use_rviz'))
    )

    return LaunchDescription([
        declare_frame_id,
        declare_use_rviz,
        declare_use_viewer,
        declare_local_frame_id,
        declare_global_frame_id,
        odom_to_world_tf,
        pointcloud_mapping_node,
        octomap_server_node,
        rviz_launch
    ]) 