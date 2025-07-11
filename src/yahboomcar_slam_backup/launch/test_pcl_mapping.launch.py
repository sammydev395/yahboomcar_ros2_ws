from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    # Declare launch arguments
    declare_use_viewer = DeclareLaunchArgument(
        'use_viewer',
        default_value='true',
        description='Whether to use the pointcloud viewer'
    )
    
    declare_local_frame_id = DeclareLaunchArgument(
        'local_frame_id',
        default_value='camera_link',
        description='Local frame ID for pointcloud mapping'
    )
    
    declare_global_frame_id = DeclareLaunchArgument(
        'global_frame_id',
        default_value='camera_link',
        description='Global frame ID for pointcloud mapping'
    )

    # Pointcloud mapping node
    pointcloud_mapping_node = Node(
        package='yahboomcar_slam',
        executable='pointcloud_mapping',
        name='pointcloud_mapping',
        output='screen',
        parameters=[{
            'topicColor': '/color/image_raw',
            'topicDepth': '/depth/image_raw',
            'topicTcw': '/tf',
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
            'buseExact': False,
            'use_viewer': LaunchConfiguration('use_viewer')
        }]
    )

    return LaunchDescription([
        declare_use_viewer,
        declare_local_frame_id,
        declare_global_frame_id,
        pointcloud_mapping_node
    ]) 