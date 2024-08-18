FROM ros:galactic

# Install ROS 2 dependencies
RUN apt-get update && apt-get install -y \
    ros-galactic-geometry-msgs \
    ros-galactic-nav2-msgs \
    ros-galactic-rclpy

# Copy control node source code
COPY src/ /root/ros2_ws/src/control_container/src/

# Build the workspace
RUN . /opt/ros/galactic/setup.sh && colcon build --packages-select control_container

# Set entrypoint
ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["ros2", "run", "control_container", "control_node"]
