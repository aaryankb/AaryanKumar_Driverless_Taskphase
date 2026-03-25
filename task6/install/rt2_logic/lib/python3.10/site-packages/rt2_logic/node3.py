import rclpy
from rclpy.node import Node
from rt2_msgs.msg import PalCheck, PalFeedback

class PalindromeResponder(Node):
    def __init__(self):
        super().__init__('node3')
        self.subscription = self.create_subscription(PalCheck, 'check_topic', self.check_callback, 10)
        self.publisher_ = self.create_publisher(PalFeedback, 'feedback_topic', 10)

    def check_callback(self, msg):
        status = msg.data
        reply_msg = PalFeedback()
        
        if status == 1:
            reply_msg.data = "Yes"
        else:
            reply_msg.data = "No"
            
        self.publisher_.publish(reply_msg)
        self.get_logger().info(f'Received {status} from Node 2. Conveyed to Node 2: "{reply_msg.data}"')

def main(args=None):
    rclpy.init(args=args)
    node = PalindromeResponder()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()