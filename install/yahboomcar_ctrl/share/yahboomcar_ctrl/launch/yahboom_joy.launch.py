from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, EnvironmentVariable
from launch_ros.actions import Node

def generate_launch_description():
    # Declare the launch arguments
    robot_type = LaunchConfiguration('robot_type')
    
    # Set default values based on environment variable
    robot_type_arg = DeclareLaunchArgument(
        'robot_type',
        default_value=EnvironmentVariable('ROBOT_TYPE'),
        description='robot_type [X1,X3,X3plus,R2,X7]'
    )
    
    # Create the joy node
    joy_node = Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        output='screen',
        respawn=False
    )
    
    # Create the yahboom_joy node with parameters
    yahboom_joy_node = Node(
        package='yahboomcar_ctrl',
        executable='yahboom_joy.py',
        name='yahboom_joy',
        output='screen',
        parameters=[{
            'use_sim_time': False,
            'linear_speed_limit': 1.0 if robot_type.perform(None) == 'X3' else 0.7,
            'angular_speed_limit': 5.0 if robot_type.perform(None) == 'X3' else 3.2,
        }]
    )
    
    return LaunchDescription([
        robot_type_arg,
        joy_node,
        yahboom_joy_node
    ])
