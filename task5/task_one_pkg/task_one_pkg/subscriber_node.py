import rclpy
from rclpy.node import Node
from task_one_interfaces.msg import TaskOne

class TaskOneSubscriber(Node):
    def __init__(self):
        super().__init__('task_one_subscriber')
        self.subscription = self.create_subscription(
            TaskOne,
            '/taskone',
            self.listener_callback,
            10)
        self.get_logger().info('Subscriber Node started. Waiting for data...')

    def listener_callback(self, msg):
        # Formula: v = omega * r
        speed = msg.ang_vel * msg.radius
        self.get_logger().info(f'Received - angVel: {msg.ang_vel}, radius: {msg.radius}')
        print(f"Calculated Longitudinal Speed: {speed} m/s")

def main(args=None):
    rclpy.init(args=args)
    node = TaskOneSubscriber()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
