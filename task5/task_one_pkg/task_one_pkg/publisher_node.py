import rclpy
from rclpy.node import Node
from task_one_interfaces.msg import TaskOne

class TaskOnePublisher(Node):
    def __init__(self):
        super().__init__('task_one_publisher')
        self.publisher_ = self.create_publisher(TaskOne, '/taskone', 10)
        self.get_logger().info('Publisher Node started. Enter data below:')
        self.timer_callback()

    def timer_callback(self):
        while rclpy.ok():
            msg = TaskOne()
            try:
                msg.ang_vel = float(input("Enter Angular Velocity (rad/s): "))
                msg.radius = float(input("Enter Wheel Radius (m): "))
                self.publisher_.publish(msg)
                self.get_logger().info(f'Published: angVel={msg.ang_vel}, radius={msg.radius}')
            except ValueError:
                print("Please enter valid numbers.")

def main(args=None):
    rclpy.init(args=args)
    node = TaskOnePublisher()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
