import pyrealsense2 as rs
import numpy as np
import cv2  # Ensure that OpenCV is imported

class RealsenseCamera:
    def __init__(self):
        # Configure depth, color, and IR streams
        print("Loading Intel Realsense Camera")
        self.pipeline = rs.pipeline()

        config = rs.config()
        config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
        config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        config.enable_stream(rs.stream.infrared, 640, 480, rs.format.y8, 30)

        # Start streaming
        self.pipeline.start(config)
        align_to = rs.stream.color
        self.align = rs.align(align_to)

    def get_frame_stream(self):
        # Wait for a coherent pair of frames: depth, color, and IR
        frames = self.pipeline.wait_for_frames()
        aligned_frames = self.align.process(frames)
        depth_frame = aligned_frames.get_depth_frame()
        color_frame = aligned_frames.get_color_frame()
        ir_frame = aligned_frames.get_infrared_frame()

        if not depth_frame or not color_frame or not ir_frame:
            # If there is no frame, probably camera not connected, return False
            print("Error, impossible to get the frame, make sure that the Intel Realsense camera is correctly connected")
            return False, None, None, None

        # Apply filter to fill the Holes in the depth image
        spatial = rs.spatial_filter()
        spatial.set_option(rs.option.holes_fill, 3)
        filtered_depth = spatial.process(depth_frame)

        hole_filling = rs.hole_filling_filter()
        filled_depth = hole_filling.process(filtered_depth)

        # Convert images to numpy arrays
        depth_image = np.asanyarray(filled_depth.get_data())
        color_image = np.asanyarray(color_frame.get_data())
        ir_image = np.asanyarray(ir_frame.get_data())

        # Convert IR image to a 3-channel image for display
        ir_image_3channel = cv2.cvtColor(ir_image, cv2.COLOR_GRAY2BGR)

        return True, color_image, depth_image, ir_image_3channel

    def release(self):
        self.pipeline.stop()

