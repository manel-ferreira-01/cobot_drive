FROM ros:jazzy-ros-base

SHELL [ "/bin/bash" , "-c" ]

RUN echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc && \
    echo "source /workspace/ros2/install/setup.bash" >> ~/.bashrc

RUN apt update && \
    apt install -y libboost-all-dev ros-jazzy-laser-proc ros-jazzy-diagnostic-updater \
    ros-jazzy-urg-c ros-jazzy-urg-node-msgs ros-jazzy-urg* ros-jazzy-rosbridge-suite

WORKDIR /workspace