import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from ackermann_msgs.msg import AckermannDriveStamped
import math

class Stanley(Node):
    def __init__(self):
        super().__init__('simple_stanley')

        self.drive_publisher = self.create_publisher(AckermannDriveStamped, '/cmd', 10)
        self.odometry_subscribtion = self.create_subscription(Odometry, '/ground_truth/odom', self.odom_callback, 10)
        
        self.max_speed = 7
        self.max_lookahead = 30
        self.mu = 1.0
        self.min_speed = 1.5
        self.max_decel = 9  
        
        self.wheelbase = 1.58
        self.last_closest_index = 0
        self.last_time = None        
        self.lap_start_time = None
        self.straight_threshold = 10

        self.p = 0.9
        self.i = 0.01
        self.d = 0.05

        self.i_t = 0
        self.prev_error=0

        self.k = 0.75 
        self.soft_const = 2.0
        self.max_steer = 0.32
        

        self.raw_waypoints = [
            (4, 0.5), 
            (6.0997, 0.46011999999999986), 
            (8.958765, 0.6334599999999995),
            (12.904501, 0.5442049999999998),
            (16.50963, 0.9106499999999986), 
            (20.142315, 2.0267799999999987), 
            (23.03038, 3.0184499999999996), 
            (25.728749999999998, 4.120899999999999),
            (27.0522, 3.8519499999999987), 
            (29.24365, 3.0322499999999994), 
            (30.2343, 2.159699999999999), 
            (31.7488, 0.11077499999999851), 
            (32.04075, -1.3419550000000005), 
            (31.85275, -4.607830000000001), 
            (30.93425, -7.440205000000001), 
            (30.10215, -9.54865), 
            (28.42945, -11.919970000000001), 
            (26.178150000000002, -13.647795), 
            (23.266765, -15.095735000000001), 
            (20.758225, -16.539845), 
            (16.424795, -18.711165), 
            (12.720585, -20.563344999999998), 
            (9.160635, -22.593), 
            (6.340465, -24.4171), 
            (3.4438549999999992, -25.2316), 
            (2.0123599999999993, -24.977),
            (-0.24815000000000076, -23.59835), 
            (-1.1382499999999993, -22.7739),
            (-3.0364499999999985, -20.334455), 
            (-3.387450000000001, -16.96707), 
            (-3.5478500000000004, -15.764190000000001), 
            (-3.2800499999999992, -12.895075), 
            (-2.8646499999999993, -10.3), 
            (-2.565950000000001, -7.250210000000001), 
            (-2.5943500000000004, -4.270505000000001), 
            (-1.4700000000000006, -1.7200000000000006), 
            (-0.6999999999999993, -0.6400000000000006), 
            (0.5199999999999996, -0.26000000000000156)
        ]
        

    def get_yaw_from_quaternion(self, q):
        siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        yaw = math.atan2(siny_cosp, cosy_cosp)
        return yaw  

    def calculate_radius(self, p1, p2, p3):
        a, b, c = math.dist(p1, p2), math.dist(p2, p3), math.dist(p1, p3)
        s = (a + b + c) / 2.0
        area_sq = s * (s - a) * (s - b) * (s - c)
        if area_sq <= 1e-4: return float('inf')
        return (a * b * c) / (4.0 * math.sqrt(area_sq))        
    

    def get_wp(self, x, y, yaw):
        num_waypoints = len(self.raw_waypoints)
        min_dist_sq = float('inf')
        closest_index = 0
    
        for idx in range(num_waypoints): 
            wp_x, wp_y = self.raw_waypoints[idx]
                 
            dist_sq = (wp_x - x)**2 + (wp_y - y)**2
            if dist_sq < min_dist_sq:
                min_dist_sq = dist_sq
                closest_index = idx
            
        self.last_closest_index = closest_index

        wp_x, wp_y = self.raw_waypoints[closest_index]
        dx = wp_x - x
        dy = wp_y - y
    
        heading_x = math.cos(yaw)
        heading_y = math.sin(yaw)
    
        dot_product = (dx * heading_x) + (dy * heading_y)

        if dot_product > 0:
            idx1 = (closest_index - 1) % num_waypoints
            idx2 = closest_index
        else:
           idx1 = closest_index
           idx2 = (closest_index + 1) % num_waypoints
        
        return idx1, idx2



    def odom_callback(self, msg):
        current_time = msg.header.stamp.sec + (msg.header.stamp.nanosec * 1e-9)
        if self.last_time is None:
            self.last_time = current_time
            return
        
        dt = current_time - self.last_time
        if dt <= 0: return  
        self.last_time = current_time
        
        current_speed = msg.twist.twist.linear.x       

        car_x = msg.pose.pose.position.x
        car_y = msg.pose.pose.position.y

        orientation_q = msg.pose.pose.orientation
        car_heading_rad = self.get_yaw_from_quaternion(orientation_q)

        front_axle_x = car_x + (self.wheelbase *math.cos(car_heading_rad))
        front_axle_y = car_y + (self.wheelbase *math.sin(car_heading_rad)) 

  
  
        prev_idx = self.last_closest_index
        idx1, idx2 = self.get_wp(front_axle_x, front_axle_y, car_heading_rad)
        num_wp = len(self.raw_waypoints)


        if prev_idx > (num_wp - 5) and self.last_closest_index < 5:
            if self.lap_start_time is None:
                self.lap_start_time = current_time
                self.get_logger().info("started")
            else:
                lap_time = current_time - self.lap_start_time
                if lap_time > 5.0: 
                    self.get_logger().info(f"LAP TIME: {lap_time:.2f} seconds")
                    self.lap_start_time = current_time



        
        x1, y1 = self.raw_waypoints[idx1]
        x2, y2 = self.raw_waypoints[idx2]

        pdx = x2-x1
        pdy = y2-y1

        target_heading = math.atan2(pdy,pdx)
        heading_err = target_heading  - car_heading_rad

        while heading_err > math.pi:
            heading_err -= 2.0 * math.pi
        while heading_err < -math.pi:
            heading_err += 2.0 * math.pi

        numerator = (pdx * (y1 - front_axle_y)) - (pdy * (x1 - front_axle_x))
        denom = math.sqrt(pdx**2 + pdy**2)
        cte = numerator / denom if denom >1e-4 else 0.0 

        self.soft_const = 10 if current_speed<0.5 else self.soft_const

        target_steering = heading_err + math.atan2((self.k*cte),(current_speed+self.soft_const))
        target_steering = max(-self.max_steer, min(self.max_steer, target_steering))
        

        safe_target_speed = self.max_speed
        accumulated_distance = 0.0
        prev_point = (front_axle_x,front_axle_y)

        for i in range(0, self.max_lookahead):
            look_idx = (idx2 + i) % num_wp
            p_current = self.raw_waypoints[look_idx]

            accumulated_distance += math.dist(prev_point, p_current)
            prev_point = p_current

            pA = self.raw_waypoints[(look_idx - 1) % num_wp]
            pB = p_current
            pC = self.raw_waypoints[(look_idx + 1) % num_wp]

            R = self.calculate_radius(pA, pB, pC)

            if R <20:
                v_corner = math.sqrt(self.mu * 9.81 * R)
                max_entry_speed = math.sqrt(v_corner**2 + (2.0 * self.max_decel * accumulated_distance))

                if max_entry_speed < safe_target_speed:
                    safe_target_speed = max_entry_speed


        min_speed = 0.5 
        target_speed = max(min_speed, safe_target_speed)

        error = target_speed- current_speed

        p_t = self.p * error
        self.i_t=max(min(self.i_t + (error * dt), 2.0), -2.0) 
        d_t = ((error - self.prev_error) / dt)*self.d
        self.prev_error = error

        acc = p_t + (self.i_t* self.i )+ d_t

        drive_msg = AckermannDriveStamped()
        drive_msg.header.stamp = self.get_clock().now().to_msg()
        drive_msg.header.frame_id = 'base_link'
        drive_msg.drive.steering_angle = float(target_steering) 
        drive_msg.drive.acceleration = acc
        
        self.drive_publisher.publish(drive_msg)


def main(args=None):
    rclpy.init(args=args)
    node = Stanley()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
