import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from irobot_create_msgs.action import AudioNoteSequence
from irobot_create_msgs.msg import AudioNoteVector, AudioNote
from rclpy.callback_groups import ReentrantCallbackGroup

class AudioNoteSequenceServer(Node):
    def __init__(self):
        super().__init__('audio_note_sequence_server')
        self._action_server = ActionServer(
            self,
            AudioNoteSequence,
            'audio_note_sequence',
            self.execute_callback,
            callback_group=ReentrantCallbackGroup()
        )
        self.get_logger().info('AudioNoteSequence action server has been started')

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')
        feedback_msg = AudioNoteSequence.Feedback()
        feedback_msg.iterations_played = 0
        feedback_msg.current_runtime.sec = 0
        feedback_msg.current_runtime.nanosec = 0

        for i in range(goal_handle.request.iterations):
            feedback_msg.iterations_played += 1
            feedback_msg.current_runtime.sec += goal_handle.request.note_sequence.notes[0].max_runtime.sec
            feedback_msg.current_runtime.nanosec += goal_handle.request.note_sequence.notes[0].max_runtime.nanosec
            goal_handle.publish_feedback(feedback_msg)
            self.get_logger().info(f'Playing note: {goal_handle.request.note_sequence.notes[0].frequency} Hz for {goal_handle.request.note_sequence.notes[0].max_runtime.sec} seconds')

        goal_handle.succeed()
        result = AudioNoteSequence.Result()
        result.complete = True
        result.iterations_played = feedback_msg.iterations_played
        result.runtime = feedback_msg.current_runtime

        return result

def main(args=None):
    rclpy.init(args=args)
    audio_note_sequence_server = AudioNoteSequenceServer()
    rclpy.spin(audio_note_sequence_server)

if __name__ == '__main__':
    main()

