import launch
import os

import launch_ros.actions

from ament_index_python.packages import get_package_prefix

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
        # Add more nodes here if needed
    ])

if __name__ == '__main__':
    #workspace_directory = os.getenv('ROS_WORKSPACE', os.getcwd()) 
    #print(os.path.join(workspace_directory, "meta_package","config","params_urg.yaml"))
    generate_launch_description()