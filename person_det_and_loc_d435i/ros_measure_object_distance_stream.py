from array import array
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32MultiArray
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
from realsense_camera import RealsenseCamera
from mask_rcnn import MaskRCNN
from flask import Flask, Response
import threading

app = Flask(__name__)

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

        self.output_frame = None
        self.lock = threading.Lock()
        self.detection_info = "Initializing..."
        self.movement_command = "Awaiting commands..."

        self.get_logger().info("PersonDetectionNode has been initialized")

    def timer_callback(self):
        ret, bgr_frame, depth_frame = self.rs.get_frame_stream()
        if not ret:
            self.get_logger().error("Failed to get frame stream")
            return

        boxes, classes, contours, centers = self.mrcnn.detect_objects_mask(bgr_frame)
        bgr_frame = self.mrcnn.draw_object_mask(bgr_frame)

        person_detected = False
        self.movement_command = "No Move Command"

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

                # Format the movement command with limited precision and clean up the string
                move_cmd = f"Move Command: linear=0.2*z={0.2*z:.2f}, angular=-0.4*x={-0.4*x:.2f}"
                self.movement_command = "".join([c if c.isprintable() else '' for c in move_cmd])

        if person_detected:
            self.detection_info = "Person detected"
        else:
            self.detection_info = "No person detected"

        # Overlay the detection info and movement command on the frame
        cv2.putText(bgr_frame, self.detection_info, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        # Adjust the text size of the second line to be smaller
        cv2.putText(bgr_frame, self.movement_command, (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 0, 0), 2)

        # Publish the image with object masks for visualization
        image_msg = self.bridge.cv2_to_imgmsg(bgr_frame, encoding="bgr8")
        self.image_pub_.publish(image_msg)

        # Display the image with masks using OpenCV
        cv2.imshow("Person Detection", bgr_frame)
        cv2.waitKey(1)  # Wait for 1 ms

        # Update the output frame for streaming
        with self.lock:
            self.output_frame = bgr_frame.copy()

    def generate(self):
        while True:
            with self.lock:
                if self.output_frame is None:
                    continue

                # Encode the frame in JPEG format
                (flag, encoded_image) = cv2.imencode(".jpg", self.output_frame)

                if not flag:
                    continue

            # Yield the output frame in the byte format required by Flask
            yield (b'--frame\r\n'
                   b'Content-Type: image/jpeg\r\n\r\n' + bytearray(encoded_image) + b'\r\n')

@app.route("/video_feed")
def video_feed():
    return Response(person_detection_node.generate(),
                    mimetype="multipart/x-mixed-replace; boundary=frame")

def main(args=None):
    rclpy.init(args=args)
    global person_detection_node
    person_detection_node = PersonDetectionNode()

    # Start Flask server in a separate thread
    flask_thread = threading.Thread(target=lambda: app.run(host="0.0.0.0", port=8080, debug=False, use_reloader=False))
    flask_thread.start()

    rclpy.spin(person_detection_node)
    person_detection_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

