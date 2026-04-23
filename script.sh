#!/bin/bash

cleanup() {
    echo "Cleaning up..."
    docker rm -f isr-cobot-test 2>/dev/null
    pkill -f joystick_test.py 2>/dev/null
    pkill -f "http.server 8080" 2>/dev/null
    exit 0
}

trap cleanup SIGINT SIGTERM

docker rm -f isr-cobot-test 2>/dev/null

pkill -f joystick_test.py 2>/dev/null
python joystick_test.py &

python3 -m http.server 8080 &

sleep 3

xhost +local:*

docker run --name isr-cobot-test \
    --network=host \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix/:/tmp/.X11-unix/ \
    --volume="/home/$USER/cobot_drive":"/workspace":rw \
    --device=/dev/input/js0:/dev/input/js0 \
    --device=/dev/ttyUSB1:/dev/ttyUSB1 \
    --device=/dev/ttyUSB0:/dev/ttyUSB0 \
    --device=/dev/ttyACM0:/dev/ttyACM0 \
    isr-cobot \
    bash -c "colcon build && source install/setup.bash && ros2 launch meta_package launch_pipeline.py" &

DOCKER_PID=$!

# Wait for docker to finish, but remain interruptible
wait $DOCKER_PID