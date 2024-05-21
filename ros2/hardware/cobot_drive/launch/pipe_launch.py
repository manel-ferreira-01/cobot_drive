import launch

import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        launch_ros.actions.Node(
            package='urg_node',
            executable='urg_node_driver',
            name='urg_node',
            output='screen',
            parameters=['config/params.yaml']
        ),
    ])

if __name__ == '__main__':
    generate_launch_description()