#!/bin/bash

# Start the person detection script
python3 /docker-workspace/person_det_and_loc_d435i/ros_measure_object_distance_all_streams.py &

# Wait for the person detection script to be ready (if needed)
sleep 5

# Start the person follower script
python3 /docker-workspace/person_det_and_loc_d435i/person_follower8.py

# Keep the container running
exec bash

