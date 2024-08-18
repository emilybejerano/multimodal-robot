import pyrealsense2 as rs

# Start the RealSense pipeline
pipeline = rs.pipeline()
config = rs.config()

# Enable both color and depth streams
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)

# Start the pipeline
pipeline.start(config)

# Get the depth sensor's depth scale
profile = pipeline.get_active_profile()
depth_sensor = profile.get_device().first_depth_sensor()
depth_scale = depth_sensor.get_depth_scale()
print("Depth Scale is: ", depth_scale)

# Get the intrinsics parameters of the color stream
color_stream = profile.get_stream(rs.stream.color).as_video_stream_profile()
intrinsics = color_stream.get_intrinsics()
print("Color stream intrinsics: ")
print(f"  Width: {intrinsics.width}")
print(f"  Height: {intrinsics.height}")
print(f"  PPX (Principal Point X): {intrinsics.ppx}")
print(f"  PPY (Principal Point Y): {intrinsics.ppy}")
print(f"  FX (Focal Length X): {intrinsics.fx}")
print(f"  FY (Focal Length Y): {intrinsics.fy}")
print(f"  Distortion Model: {intrinsics.model}")
print(f"  Distortion Coefficients: {intrinsics.coeffs}")

# Stop the pipeline
pipeline.stop()

