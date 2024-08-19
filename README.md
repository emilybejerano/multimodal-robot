# multi-modal human-following-robot
Docker Images in Dockerhub https://hub.docker.com/repository/docker/eg3205/mobilesensing/general
eg3205/mobilesensing:both_images_d435ilocal_with_radar

Master container (central control) -- ROS
One docker container for vlm that goes to another for sensing modality then have one more
Separate docker containers for different sensing modalities 



```
xhost +local:docker
```

```
docker pull eg3205/mobilesensing:both_images_d435ilocal_with_radar
```


```
docker run -it --rm --gpus all --network host --device=/dev/video0 --device=/dev/video1 --device=/dev/video2 --device=/dev/video3 --device=/dev/video4 --device=/dev/video5 --device=/dev/video6 --device=/dev/video7 --device=/dev/video8 --device=/dev/video9 --device=/dev/video10 --device=/dev/video11 --device=/dev/video12 --device=/dev/video13 --device=/dev/ttyUSB0 --device=/dev/ttyUSB1 -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix -v $HOME/docker-workspace:/docker-workspace eg3205/mobilesensing:both_images_d435ilocal_with_radar
```

```
source /opt/ros/galactic/setup.bash
    source /ws/src/install/setup.bash
```
```
pip install --ignore-installed Flask
```
```
sudo docker run -it --rm   --runtime nvidia   --network host   --device=/dev/video0   --device=/dev/video1   --device=/dev/video2   --device=/dev/video3   --device=/dev/video4   --device=/dev/video5   --device=/dev/video6   --device=/dev/video7   --device=/dev/video8   --device=/dev/video9   --device=/dev/video10   --device=/dev/video11   --device=/dev/video12   --device=/dev/video13   --device=/dev/ttyUSB0   --device=/dev/ttyUSB1   -e DISPLAY=$DISPLAY   -v /tmp/.X11-unix:/tmp/.X11-unix   -v $HOME/docker-workspace:/docker-workspace   -v /path/to/local/model/files:/data/models   dustynv/nano_llm:r36.2.0   python3 -m nano_llm.chat --api=mlc     --model Efficient-Large-Model/VILA1.5-3b     --max-context-len 256     --max-new-tokens 32
```


project_directory/
│
├── docker-compose.yml
├── master_control/
│   ├── Dockerfile
│   └── launch/
│       └── master_control_launch.py
├── vlm_container/
│   ├── Dockerfile
│   └── src/
│       ├── vlm_node.py
│       └── setup.py
├── lidar_container/
│   ├── Dockerfile
│   └── src/
│       ├── lidar_node.py
│       └── setup.py
├── rgbd_container/
│   ├── Dockerfile
│   └── src/
│       ├── rgbd_node.py
│       └── setup.py
├── mmwave_container/
│   ├── Dockerfile
│   └── src/
│       ├── mmwave_node.py
│       └── setup.py
└── control_container/
    ├── Dockerfile
    └── src/
        ├── control_node.py
        └── setup.py

Start whole thing with 
```
docker-compose up --build
```
this one will automatically start d435i sensing
```
docker run -it --rm --gpus all --network host \
  --device=/dev/video0 \
  --device=/dev/video1 \
  --device=/dev/video2 \
  --device=/dev/video3 \
  --device=/dev/video4 \
  --device=/dev/video5 \
  --device=/dev/video6 \
  --device=/dev/video7 \
  --device=/dev/video8 \
  --device=/dev/video9 \
  --device=/dev/video10 \
  --device=/dev/video11 \
  --device=/dev/video12 \
  --device=/dev/video13 \
  --device=/dev/ttyUSB0 \
  --device=/dev/ttyUSB1 \
  --device=/dev/bus/usb \
  -e DISPLAY=$DISPLAY \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -v $HOME/docker-workspace:/docker-workspace \
  yourusername/d435i_sensing_auto
```
