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
        if not msg.point_id:
            self.get_logger().info('No points in the radar scan')
            return

        # Print the message to understand its structure
        self.get_logger().info(f'RadarScan message: {msg}')

        # Calculate the distance and angle for the detected point
        x = msg.x
        y = msg.y
        z = msg.z
        distance = math.sqrt(x**2 + y**2 + z**2)
        angle = math.atan2(y, x) * 180 / math.pi  # Convert radians to degrees
        self.get_logger().info(f'Point: x={x}, y={y}, z={z}, Angle: {angle:.2f} degrees, Distance: {distance:.2f} meters')

def main(args=None):
    rclpy.init(args=args)
    radar_scan_processor = RadarScanProcessor()
    rclpy.spin(radar_scan_processor)
    radar_scan_processor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

