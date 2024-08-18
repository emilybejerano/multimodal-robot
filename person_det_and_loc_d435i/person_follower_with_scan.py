import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Twist
from irobot_create_msgs.action import AudioNoteSequence
from rclpy.action import ActionClient

class PersonFollower(Node):
    def __init__(self):
        super().__init__('person_follower')
        self.subscription = self.create_subscription(
            Float32MultiArray,
            'person_position',
            self.person_position_callback,
            10)
        self.publisher_ = self.create_publisher(Twist, 'cmd_vel', 10)
        self.sound_client = ActionClient(self, AudioNoteSequence, '/audio_note_sequence')
        self.subscription  # prevent unused variable warning
        self.get_logger().info("PersonFollower has been initialized")
        self.last_position = None
        self.stop_distance = 0.5  # 0.5 meters
        self.sound_playing = False
        self.camera_offset_x = 0.1  # Camera offset in meters
        self.no_person_detected_count = 0
        self.missed_detection_threshold = 10  # Number of missed detections before starting to scan
        self.rotate_speed = 0.3  # Rotation speed when scanning

    def person_position_callback(self, msg):
        if len(msg.data) == 3:
            self.no_person_detected_count = 0  # Reset no-person counter on successful detection
            self.last_position = msg.data
            x, y, z = self.last_position

            # Adjust for camera offset
            x = x + self.camera_offset_x

            # Log the received position
            self.get_logger().info(f"Received person position: x={x}, y={y}, z={z}")

            if z < self.stop_distance:
                self.stop_robot()
                if not self.sound_playing:
                    self.play_sound()
            else:
                self.sound_playing = False
                # Calculate control commands with smoothing
                linear_velocity = 0.2 * z  # Proportional control for forward movement
                angular_velocity = -0.4 * x  # Proportional control for turning

                # Cap velocities for safety
                linear_velocity = max(min(linear_velocity, 0.3), -0.3)
                angular_velocity = max(min(angular_velocity, 0.5), -0.5)

                # Create Twist message
                twist = Twist()
                twist.linear.x = linear_velocity
                twist.angular.z = angular_velocity

                # Publish Twist message
                self.publisher_.publish(twist)
                self.get_logger().info(f"Published command: linear={linear_velocity}, angular={angular_velocity}")
        else:
            self.get_logger().info("No valid person position received")
            self.no_person_detected_count += 1

            if self.no_person_detected_count >= self.missed_detection_threshold:
                self.get_logger().info("Starting scan for person...")
                self.scan_for_person()

    def stop_robot(self):
        twist = Twist()
        twist.linear.x = 0.0
        twist.angular.z = 0.0
        self.publisher_.publish(twist)
        self.get_logger().info("Robot stopped due to proximity.")

    def play_sound(self):
        goal_msg = AudioNoteSequence.Goal()
        goal_msg.iterations = 1
        note = AudioNoteSequence.Note()
        note.note = 60  # Middle C
        note.duration = 1.0  # 1 second
        goal_msg.notes = [note]
        self.sound_client.send_goal_async(goal_msg)
        self.sound_playing = True
        self.get_logger().info("Playing warning sound due to close proximity.")

    def scan_for_person(self):
        twist = Twist()
        twist.angular.z = self.rotate_speed  # Rotate in place
        self.publisher_.publish(twist)
        self.get_logger().info("Scanning for person...")

def main(args=None):
    rclpy.init(args=args)
    person_follower = PersonFollower()
    rclpy.spin(person_follower)
    person_follower.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

