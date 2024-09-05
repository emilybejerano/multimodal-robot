import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist, PoseStamped
from ti_mmwave_ros2_interfaces.msg import RadarScan
from sensor_msgs.msg import PointCloud2
from tf_transformations import euler_from_quaternion
import math

class RobotMover(Node):
    def __init__(self):
        super().__init__('robot_mover')
        self.subscription_radar = self.create_subscription(
            RadarScan,
            '/ti_mmwave/radar_scan',
            self.radar_callback,
            10)
        self.subscription_pointcloud = self.create_subscription(
            PointCloud2,
            '/ti_mmwave/radar_scan_pcl',
            self.pointcloud_callback,
            10)
        self.publisher_cmd_vel = self.create_publisher(Twist, '/cmd_vel', 10)
        self.publisher_goal = self.create_publisher(PoseStamped, '/goal_pose', 10)
        self.target_distance = None
        self.target_angle = None
        self.robot_orientation = None

    def radar_callback(self, msg):
        if msg.point_id < 0:
            self.get_logger().info('No points in the radar scan')
            return

        x = msg.x
        y = msg.y
        z = msg.z
        distance = math.sqrt(x**2 + y**2 + z**2)
        angle = math.atan2(y, x)  # Angle in radians

        self.target_distance = distance
        self.target_angle = angle

        self.get_logger().info(f'Detected target: Distance={distance:.2f} meters, Angle={math.degrees(angle):.2f} degrees')
        self.rotate_towards_target()

    def pointcloud_callback(self, msg):
        # Process point cloud data if necessary
        pass

    def rotate_towards_target(self):
        if self.target_angle is None:
            self.get_logger().info('No target angle to rotate towards')
            return

        twist = Twist()
        twist.angular.z = 0.5 if self.target_angle > 0 else -0.5
        self.publisher_cmd_vel.publish(twist)

        self.create_timer(abs(self.target_angle), self.stop_rotation)

    def stop_rotation(self):
        twist = Twist()
        twist.angular.z = 0.0
        self.publisher_cmd_vel.publish(twist)
        self.move_towards_target()

    def move_towards_target(self):
        if self.target_distance is None:
            self.get_logger().info('No target distance to move towards')
            return

        goal_pose = PoseStamped()
        goal_pose.header.stamp = self.get_clock().now().to_msg()
        goal_pose.header.frame_id = 'base_link'
        goal_pose.pose.position.x = self.target_distance * math.cos(self.target_angle)
        goal_pose.pose.position.y = self.target_distance * math.sin(self.target_angle)
        goal_pose.pose.orientation.w = 1.0

        self.publisher_goal.publish(goal_pose)
        self.get_logger().info(f'Published goal pose: {goal_pose.pose.position.x}, {goal_pose.pose.position.y}')

def main(args=None):
    rclpy.init(args=args)
    robot_mover = RobotMover()
    rclpy.spin(robot_mover)
    robot_mover.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

