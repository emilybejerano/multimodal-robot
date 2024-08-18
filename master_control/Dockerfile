FROM ros:galactic

# Install necessary ROS 2 packages
RUN apt-get update && apt-get install -y \
    ros-galactic-ros-base \
    ros-galactic-launch

# Copy launch files
COPY launch/ /root/ros2_ws/src/master_control/launch/

# Build the workspace
RUN . /opt/ros/galactic/setup.sh && colcon build --packages-select master_control

# Set entrypoint
ENTRYPOINT ["/ros_entrypoint.sh"]
CMD ["ros2", "launch", "master_control", "master_control_launch.py"]
