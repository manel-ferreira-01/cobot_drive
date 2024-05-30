
# Cobot_drive
 

ROS2 package to drive the cobot2 from CMU.



## Installation

To install dependecies and setup a ROS2 Enviroment:

    docker build . -t isr-cobot

### Aliases

Add this aliases to ~/.bashrc of host machine:
``` bash
    alias pipeCreate="xhost +local:* && docker run --name isr-cobot-cont \
    -it --network=host \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix/:/tmp/.X11-unix/ \
    --volume="/home/$USER/ist/smart_retail/cobot_drive":"/workspace":rw \
    --device=/dev/ttyUSB1:/dev/ttyUSB1 \
    --device=/dev/ttyUSB0:/dev/ttyUSB0 \
    --device=/dev/ttyACM0:/dev/ttyACM0 \
    isr-cobot \
    bash" # change repo's path accordingly

    alias pipeDelete="docker rm isr-cobot-cont"
    alias pipeNew="xhost +local:* && docker exec -it isr-cobot-cont bash"
    alias pipeRestart="xhost +local:* && docker start -i isr-cobot-cont"

```

## Usage

- Launch container with `pipeCreate`.
- Inside container:
	- `colcon build`
	- `source install/setup.bash`
	- `ros2 launch meta_package launch_pipeline.py `