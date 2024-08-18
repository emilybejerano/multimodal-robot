import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, PointCloud2
from geometry_msgs.msg import Twist

class ControlNode(Node):

    def __init__(self):
        super().__init__('control_node')
        
        # Subscriptions
        self.rgbd_subscription = self.create_subscription(
            Image,
            '/camera/rgb/image_raw',
            self.rgbd_callback,
            10)
        
        self.lidar_subscription = self.create_subscription(
            PointCloud2,
            '/lidar/scan',
            self.lidar_callback,
            10)
        
        # Publisher for movement commands
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)

    def rgbd_callback(self, image_data):
        # Process RGB-D data
        self.get_logger().info('Processing RGB-D data')
        self.process_sensor_data()

    def lidar_callback(self, scan_data):
        # Process LiDAR data
        self.get_logger().info('Processing LiDAR data')
        self.process_sensor_data()

    def process_sensor_data(self):
        # Implement logic to determine movement based on sensor data
        # For example, if an object is detected at a certain distance,
        # move the robot forward or rotate it

        twist = Twist()
        twist.linear.x = 0.5  # Example: move forward
        twist.angular.z = 0.0  # Example: no rotation
        self.cmd_vel_publisher.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    control_node = ControlNode()
    rclpy.spin(control_node)
    control_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
