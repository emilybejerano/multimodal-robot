# multi-modal human-following-robot
Docker Images in Dockerhub https://hub.docker.com/repository/docker/eg3205/mobilesensing/general
eg3205/mobilesensing:both_images_d435ilocal_with_radar


```
xhost +local:docker
```

```
docker run -it --rm --gpus all --network host --device=/dev/video0 --device=/dev/video1 --device=/dev/video2 --device=/dev/video3 --device=/dev/video4 --device=/dev/video5 --device=/dev/video6 --device=/dev/video7 --device=/dev/video8 --device=/dev/video9 --device=/dev/video10 --device=/dev/video11 --device=/dev/video12 --device=/dev/video13 --device=/dev/ttyUSB0 --device=/dev/ttyUSB1 -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v $HOME/docker-workspace:/docker-workspace eg3205/mobilesensing:both_images_d435ilocal_with_radar
```

```
source /opt/ros/galactic/setup.bash
    source /ws/src/install/setup.bash
```
