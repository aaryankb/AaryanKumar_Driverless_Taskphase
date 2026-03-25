import rclpy
from rt2_msgs.msg import RT2String

def main(args=None):
    rclpy.init(args=args)
    node = rclpy.create_node('node1_str_pub')
    pub = node.create_publisher(RT2String, 'input_string', 10)
    msg = RT2String()

    try:
        while rclpy.ok():
            user_input = input("Enter a string: ")
            msg.data = user_input
            pub.publish(msg)
            node.get_logger().info(f'node1 published: {msg.data}')
            rclpy.spin_once(node, timeout_sec=0.1) 
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()