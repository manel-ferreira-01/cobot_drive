FROM ros:iron-ros-base

SHELL [ "/bin/bash" , "-c" ]

RUN echo "source /opt/ros/iron/setup.bash" >> ~/.bashrc && \
    echo "source /workspace/ros2/install/setup.bash" >> ~/.bashrc

RUN apt update && \
    apt install -y libboost-all-dev ros-iron-laser-proc ros-iron-diagnostic-updater \
    ros-iron-urg-c ros-iron-urg-node-msgs ros-iron-urg* ros-iron-rosbridge-suite

WORKDIR /workspace