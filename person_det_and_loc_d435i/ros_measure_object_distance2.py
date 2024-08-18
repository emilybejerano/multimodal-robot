from array import array
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from realsense_camera import RealsenseCamera
from mask_rcnn import MaskRCNN

class PersonDetectionNode(Node):
    def __init__(self):
        super().__init__('person_detection_node')
        self.publisher_ = self.create_publisher(Float32MultiArray, 'person_position', 10)
        self.image_pub_ = self.create_publisher(Image, 'person_image', 10)
        self.timer = self.create_timer(0.1, self.timer_callback)

        self.bridge = CvBridge()
        self.rs = RealsenseCamera()
        self.mrcnn = MaskRCNN()

        # Intrinsic parameters (replace with your actual values)
        self.fx = 607.4354248046875
        self.fy = 607.5763549804688
        self.ppx = 315.3838195800781
        self.ppy = 241.9356231689453

        self.get_logger().info("PersonDetectionNode has been initialized")

    def timer_callback(self):
        ret, bgr_frame, depth_frame = self.rs.get_frame_stream()
        if not ret:
            self.get_logger().error("Failed to get frame stream")
            return

        boxes, classes, contours, centers = self.mrcnn.detect_objects_mask(bgr_frame)
        bgr_frame = self.mrcnn.draw_object_mask(bgr_frame)

        person_detected = False
        for i, center in enumerate(centers):
            if int(classes[i]) == 0:  # Class ID for 'person' is 0
                person_detected = True
                depth = depth_frame[int(center[1]), int(center[0])]
                if depth == 0:
                    self.get_logger().warning("Depth value is 0, skipping")
                    continue

                x = (center[0] - self.ppx) / self.fx * depth
                y = (center[1] - self.ppy) / self.fy * depth
                z = depth

                msg = Float32MultiArray()
                msg.data = array('f', [x, y, z])
                self.publisher_.publish(msg)
                self.get_logger().info(f'Published person position: {msg.data}')

        if not person_detected:
            self.get_logger().info("No person detected in this frame")

        # Publish the image with object masks for visualization
        image_msg = self.bridge.cv2_to_imgmsg(bgr_frame, encoding="bgr8")
        self.image_pub_.publish(image_msg)

        # Display the image with masks using OpenCV
        cv2.imshow("Person Detection", bgr_frame)
        cv2.waitKey(1)  # Wait for 1 ms

def main(args=None):
    rclpy.init(args=args)
    person_detection_node = PersonDetectionNode()
    rclpy.spin(person_detection_node)
    person_detection_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

