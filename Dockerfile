# Use your existing Docker image as the base
FROM eg3205/mobilesensing:both_images_d435ilocal_with_radar

# Temporarily remove problematic RealSense repository
RUN sed -i '/realsense-hw-public.s3.amazonaws.com/d' /etc/apt/sources.list.d/*.list || true

# Update package lists and install any additional packages
RUN apt-get update && apt-get install -y \
    bash

# Add the commands to source the ROS setup files
RUN echo "source /opt/ros/galactic/setup.bash" >> ~/.bashrc && \
    echo "source /ws/src/install/setup.bash" >> ~/.bashrc

# Set the working directory
WORKDIR /root/multimodal-robot/person_det_and_loc_d435i

# Copy the entrypoint script into the container
COPY entrypoint.sh /root/multimodal-robot/person_det_and_loc_d435i/entrypoint.sh

# Make the script executable
RUN chmod +x /root/multimodal-robot/person_det_and_loc_d435i/entrypoint.sh

# Set the entrypoint script
ENTRYPOINT ["/root/multimodal-robot/person_det_and_loc_d435i/entrypoint.sh"]

