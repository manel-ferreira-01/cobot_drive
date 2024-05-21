FROM ros:iron-ros-base

SHELL [ "/bin/bash" , "-c" ]

RUN apt update && \
    apt install -y libboost-all-dev ros-iron-laser-proc ros-iron-diagnostic-updater \
    ros-iron-urg-c ros-iron-urg-node-msgs 

WORKDIR /workspace