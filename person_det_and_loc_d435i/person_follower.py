import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Twist

class PersonFollower(Node):
    def __init__(self):
        super().__init__('person_follower')
        self.subscription = self.create_subscription(
            Float32MultiArray,
            'person_position',
            self.listener_callback,
            10)
        self.publisher_ = self.create_publisher(Twist, 'cmd_vel', 10)
        self.target_distance = 1000.0  # Desired distance from the person in mm

    def listener_callback(self, msg):
        x, y, z = msg.data
        twist = Twist()

        if z > self.target_distance:
            twist.linear.x = 0.2  # Move forward
        elif z < self.target_distance:
            twist.linear.x = -0.2  # Move backward

        if abs(x) > 50:  # If the person is more than 50 mm away from the center
            twist.angular.z = -0.002 * x  # Adjust this value to suit your robot's turning radius

        self.publisher_.publish(twist)
        self.get_logger().info(f'Moving towards person at ({x}, {y}, {z})')

def main(args=None):
    rclpy.init(args=args)
    person_follower = PersonFollower()
    rclpy.spin(person_follower)
    person_follower.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

