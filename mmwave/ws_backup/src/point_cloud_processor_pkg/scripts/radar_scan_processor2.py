import rclpy
from rclpy.node import Node
from ti_mmwave_ros2_interfaces.msg import RadarScan
import math

class RadarScanProcessor(Node):
    def __init__(self):
        super().__init__('radar_scan_processor')
        self.subscription = self.create_subscription(
            RadarScan,
            '/ti_mmwave/radar_scan',  # Radar scan topic
            self.radar_scan_callback,
            10)
        self.get_logger().info('RadarScanProcessor node has been started')

    def radar_scan_callback(self, msg):
        # Determine if the message contains a list of points or a single point
        try:
            num_points = len(msg.x)  # Check if msg.x is a list
        except TypeError:
            # If msg.x is not a list, treat it as a single point
            num_points = 1

        if num_points == 0:
            self.get_logger().info('No points in the radar scan')
            return

        # Initialize variables for centroid calculation
        sum_x = 0.0
        sum_y = 0.0
        sum_z = 0.0

        # Sum the coordinates of all points to calculate the centroid
        for i in range(num_points):
            if num_points == 1:
                # Single point case
                x = msg.x
                y = msg.y
                z = msg.z
            else:
                # Multiple points case
                x = msg.x[i]
                y = msg.y[i]
                z = msg.z[i]

            sum_x += x
            sum_y += y
            sum_z += z

        # Calculate the centroid coordinates
        centroid_x = sum_x / num_points
        centroid_y = sum_y / num_points
        centroid_z = sum_z / num_points

        # Calculate the distance and angle from the robot to the centroid
        distance = math.sqrt(centroid_x**2 + centroid_y**2 + centroid_z**2)
        angle = math.atan2(centroid_y, centroid_x) * 180 / math.pi  # Convert radians to degrees

        # Log the centroid position and the calculated distance/angle
        self.get_logger().info(f'Centroid: x={centroid_x:.2f}, y={centroid_y:.2f}, z={centroid_z:.2f}')
        self.get_logger().info(f'Centroid Angle: {angle:.2f} degrees, Centroid Distance: {distance:.2f} meters')

def main(args=None):
    rclpy.init(args=args)
    radar_scan_processor = RadarScanProcessor()
    rclpy.spin(radar_scan_processor)
    radar_scan_processor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

