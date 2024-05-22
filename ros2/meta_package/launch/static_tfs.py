
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='static_tf2_broadcaster',
            arguments=['0', '0', '0', '0', '0', '0','1', 'base_footprint', 'laser']
        ),
    ])
