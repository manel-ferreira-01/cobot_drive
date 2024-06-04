FROM ros:iron-ros-base

SHELL [ "/bin/bash" , "-c" ]

RUN echo "source /opt/ros/iron/setup.bash" >> ~/.bashrc && \
    echo "source /workspace/install/setup.bash" >> ~/.bashrc && \
    echo "alias map_saver='ros2 run nav2_map_server map_saver_cli -f /workspace/ros2/meta_package/maps"

RUN apt update && \
    apt install -y libboost-all-dev ros-iron-laser-proc ros-iron-diagnostic-updater \
    ros-iron-urg-c ros-iron-urg-node-msgs ros-iron-urg* ros-iron-rosbridge-suite ros-iron-navigation2 ros-iron-nav2-bringup \
    ros-iron-joy ros-iron-joy-linux ros-iron-teleop-twist-joy


WORKDIR /workspace