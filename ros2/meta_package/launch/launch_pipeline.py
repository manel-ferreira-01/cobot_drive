import launch
import os

import launch_ros.actions
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource
from ament_index_python.packages import get_package_prefix, get_package_share_directory

def generate_launch_description():
    
    workspace_directory = os.getenv('ROS_WORKSPACE', os.getcwd())    
    
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='cobot_drive',
            executable='cobot_drive_main',
            name='cobot_drive'
        ),
        launch_ros.actions.Node(
            package='urg_node',
            executable='urg_node_driver',
            name='urg_node',
            output='screen',
            parameters=[ os.path.join(workspace_directory, "meta_package","config","params_urg.yaml") ]
        ),
        launch.actions.IncludeLaunchDescription(
        XMLLaunchDescriptionSource(
                [os.path.join(
         get_package_share_directory('rosbridge_server'), 'launch'),
         '/rosbridge_websocket_launch.xml']))
    ])

if __name__ == '__main__':
    #workspace_directory = os.getenv('ROS_WORKSPACE', os.getcwd()) 
    #print(os.path.join(workspace_directory, "meta_package","config","params_urg.yaml"))
    generate_launch_description()