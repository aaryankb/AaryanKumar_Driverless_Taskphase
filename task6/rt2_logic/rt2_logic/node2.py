import rclpy
from rclpy.node import Node
from rt2_msgs.msg import RT2String, PalCheck, PalFeedback

class PalindromeChecker(Node):
    def __init__(self):
        super().__init__('node2')
        self.subscription = self.create_subscription(RT2String, 'input_string', self.string_callback, 10)
        self.publisher_ = self.create_publisher(PalCheck, 'check_topic', 10)
        self.feedback_sub = self.create_subscription(PalFeedback, 'feedback_topic', self.feedback_callback, 10)

    def string_callback(self, msg):
        s = msg.data
        is_pal = 1 if s == s[::-1] else 0
        
        out_msg = PalCheck()
        out_msg.data = is_pal
        self.publisher_.publish(out_msg)
        self.get_logger().info(f'Node2 has Evaluated "{s}". now sending: {is_pal}')

    def feedback_callback(self, msg):
        self.get_logger().info(f'Node 3 conveyed: {msg.data}')

def main(args=None):
    rclpy.init(args=args)
    node = PalindromeChecker()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()