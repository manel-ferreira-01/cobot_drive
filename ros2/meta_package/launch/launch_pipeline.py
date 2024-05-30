import launch
import os

import launch_ros.actions
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_prefix, get_package_share_directory

def generate_launch_description():
    
    workspace_directory = os.getenv('ROS_WORKSPACE', os.getcwd())  
    teleop_flag = True 
    
    teleop_joy_pkgs = launch.LaunchDescription([
        launch_ros.actions.Node(
            package='joy_linux',
            executable='joy_linux_node',
            name='joy_linux'),
        
        launch.actions.IncludeLaunchDescription(
            PythonLaunchDescriptionSource(get_package_share_directory('teleop_twist_joy')+'/launch/teleop-launch.py'),
            launch_arguments = {
                'config_filepath':  os.path.join(workspace_directory,"ros2", "meta_package","config","joy.yaml") 
                }.items()
            )
    ])
    
    launch_list = launch.LaunchDescription([
        launch_ros.actions.Node(
            package='cobot_drive',
            executable='cobot_drive_main',
            name='cobot_drive',
            respawn=True
        ),
        launch_ros.actions.Node(
            package='urg_node',
            executable='urg_node_driver',
            name='urg_node',
            output='screen',
            parameters=[ os.path.join(workspace_directory,"ros2", "meta_package","config","params_urg.yaml") ]
        ),
        launch.actions.IncludeLaunchDescription(
        XMLLaunchDescriptionSource(
                [os.path.join(get_package_share_directory('rosbridge_server'), 'launch'),
         '/rosbridge_websocket_launch.xml'])),
        
        launch.actions.IncludeLaunchDescription(
        PythonLaunchDescriptionSource(get_package_share_directory('meta_package')+'/launch/static_tfs.py')),
        ]
    )
    
    if teleop_flag : 
        secondary_actions = teleop_joy_pkgs.entities
        launch_list.entities.extend(secondary_actions)
                
    return launch_list

if __name__ == '__main__':
    #workspace_directory = os.getenv('ROS_WORKSPACE', os.getcwd()) 
    #print(os.path.join(workspace_directory,"ros2", "meta_package","config","params_urg.yaml"))
    generate_launch_description()