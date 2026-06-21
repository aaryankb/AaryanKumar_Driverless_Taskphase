import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from ackermann_msgs.msg import AckermannDriveStamped
import numpy as np
from scipy.optimize import minimize

class mpc(Node):
    def __init__(self):
        super().__init__('mpc')

        
        self.drive_publisher = self.create_publisher(AckermannDriveStamped, '/cmd', 10)
        self.odometry_sub = self.create_subscription(Odometry, '/ground_truth/odom', self.odom_callback, 10)
        
       
        self.dt = 0.05
        self.N_steps = 4  
        self.wheelbase = 1.58       
        self.max_steer_limit = 0.52 
        self.v_desired = 8.0   
        

        self.W_cte = 500.0     
        self.W_theta = 1200.0   
        self.W_v = 9.0   #6.0 
        self.W_dsteer = 125.0  

        
        self.car_x = None
        self.car_y = None
        self.car_heading = None
        self.current_speed = 0.0

        # --- LAP TIMER VARIABLES ---
        self.last_closest_index = 0
        self.lap_start_time = None
        self.current_time = 0.0
        # ---------------------------

       
        self.raw_waypoints = np.array([
            [4.0, 0.5], [6.0997, 0.46012], [8.958765, 0.63346], [12.904501, 0.544205],
            [16.50963, 0.91065], [20.142315, 2.02678], [23.03038, 3.01845], [25.72875, 4.1209],
            [27.0522, 3.85195], [29.24365, 3.03225], [30.2343, 2.1597], [31.7488, 0.110775],
            [32.04075, -1.341955], [31.85275, -4.60783], [30.93425, -7.440205], [30.10215, -9.54865],
            [28.42945, -11.91997], [26.17815, -13.647795], [23.266765, -15.095735], [20.758225, -16.539845],
            [16.424795, -18.711165], [12.720585, -20.563345], [9.160635, -22.593], [6.340465, -24.4171],
            [3.443855, -25.2316], [2.01236, -24.977], [-0.24815, -23.59835], [-1.13825, -22.7739],
            [-3.03645, -20.334455], [-3.38745, -16.96707], [-3.54785, -15.76419], [-3.280045, -12.895075],
            [-2.86465, -10.3], [-2.56595, -7.25021], [-2.59435, -4.270505], [-1.47000, -1.7200],
            [-0.699999, -0.6400], [0.52, -0.26]
        ])
        self.num_wp = len(self.raw_waypoints)

        self.initial_guess = np.array([[1.0, 0.0]] * self.N_steps).flatten()

        self.control_timer = self.create_timer(self.dt, self.control_loop)

    def get_yaw_from_quaternion(self, q):
        siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        return np.arctan2(siny_cosp, cosy_cosp)  

    def calculate_cte(self, x, y, wp1, wp2):
        numerator = abs((wp2[1] - wp1[1])*x - (wp2[0] - wp1[0])*y + wp2[0]*wp1[1] - wp2[1]*wp1[0])
        denominator = np.sqrt((wp2[1] - wp1[1])**2 + (wp2[0] - wp1[0])**2) + 1e-6
        return numerator / denominator

    def cost_function(self, controls, start_state, wp1, wp2, theta_ref):
        cost = 0.0
        x, y, theta, v = start_state
        controls = controls.reshape((self.N_steps, 2))
        
        last_steer = 0.0 
        
        for t in range(self.N_steps):
            a = controls[t, 0]
            omega = controls[t, 1]
            
            cte = self.calculate_cte(x, y, wp1, wp2)
            e_theta = theta - theta_ref
            
            e_theta = (e_theta + np.pi) % (2.0 * np.pi) - np.pi
            e_v = v - self.v_desired
            
            
            cost += (self.W_cte * cte**2) + (self.W_theta * e_theta**2) + (self.W_v * e_v**2) + (self.W_dsteer * (omega - last_steer)**2)


            x = x + v * np.cos(theta) * self.dt
            y = y + v * np.sin(theta) * self.dt
            theta = theta + omega * self.dt
            v = v + a * self.dt
            
            last_steer = omega 
            
        return cost

    def odom_callback(self, msg):
        # Cache the current sim time for the lap timer
        self.current_time = msg.header.stamp.sec + (msg.header.stamp.nanosec * 1e-9)
        
        self.current_speed = msg.twist.twist.linear.x 
        self.car_x = msg.pose.pose.position.x
        self.car_y = msg.pose.pose.position.y
        self.car_heading = self.get_yaw_from_quaternion(msg.pose.pose.orientation)

    def control_loop(self):
        if self.car_x is None or self.car_y is None or self.car_heading is None:
            return

        
        dists = np.sum((self.raw_waypoints - np.array([self.car_x, self.car_y]))**2, axis=1)
        closest_index = int(np.argmin(dists))

        # --- LAP TIMER LOGIC ---
        prev_idx = self.last_closest_index
        self.last_closest_index = closest_index

        if prev_idx > (self.num_wp - 5) and self.last_closest_index < 5:
            if self.lap_start_time is None:
                self.lap_start_time = self.current_time
                self.get_logger().info("started")
            else:
                lap_time = self.current_time - self.lap_start_time
                if lap_time > 5.0: 
                    self.get_logger().info(f"LAP TIME: {lap_time:.2f} seconds")
                    self.lap_start_time = self.current_time
        # -----------------------
        
        wp_closest = self.raw_waypoints[closest_index]
        dx_wp = wp_closest[0] - self.car_x
        dy_wp = wp_closest[1] - self.car_y
        
        # If the closest waypoint sits behind the vehicle bumper, advance target tracking segment forward
        if (dx_wp * np.cos(self.car_heading) + dy_wp * np.sin(self.car_heading)) < 4:
            target_index = (closest_index + 1) % self.num_wp
        else:
            target_index = closest_index
        
        wp1 = self.raw_waypoints[target_index]
        wp2 = self.raw_waypoints[(target_index + 1) % self.num_wp]

        dy = wp2[1] - wp1[1]
        dx = wp2[0] - wp1[0]
        theta_ref = np.arctan2(dy, dx)

        live_initial_state = np.array([self.car_x, self.car_y, self.car_heading, self.current_speed])

        
        bounds = [(-10.0, 3.0), (-5.0, 5.0)] * self.N_steps

        
        result = minimize(
            self.cost_function,
            self.initial_guess,
            args=(live_initial_state, wp1, wp2, theta_ref),
            
            bounds=bounds,
            
        )

        
        optimal_controls = result.x.reshape((self.N_steps, 2))
        target_accel = optimal_controls[0, 0]       
        target_yaw_rate = optimal_controls[0, 1]   

        
        next_guess = np.roll(result.x, -2)
        next_guess[-2:] = result.x[-2:] 
        self.initial_guess = next_guess

        
        v_calc = max(abs(self.current_speed), 0.5) 
        target_steering = np.arctan2(target_yaw_rate * self.wheelbase, v_calc)
        target_steering = np.clip(target_steering, -self.max_steer_limit, self.max_steer_limit)

        
        drive_msg = AckermannDriveStamped()
        drive_msg.header.stamp = self.get_clock().now().to_msg()
        drive_msg.header.frame_id = 'base_link'
        drive_msg.drive.steering_angle = float(target_steering)
        drive_msg.drive.acceleration = float(target_accel)
        self.drive_publisher.publish(drive_msg)

def main(args=None):
    rclpy.init(args=args)
    node = mpc()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()





'''
        self.dt = 0.1
        self.N_steps = 5  
        self.wheelbase = 1.58       
        self.max_steer_limit = 0.52 
        self.v_desired = 8.0   # Slow target speed for visual tracking debugging
        
        # FIXED WEIGHTS: Added heavy damping to completely smooth out the steering wheel
        self.W_cte = 400.0     # MASSIVE PRIORITY: Glue car to the centerline
        self.W_theta = 400.0   # Moderate priority: Match line heading
        self.W_v = 5.0        # Baseline priority: Maintain 2.0 m/s
        self.W_dsteer = 250.0  # DAMPING: Heavily penalize snapping the wheel rapidly


'''


'''

        self.dt = 0.1
        self.N_steps = 5  
        self.wheelbase = 1.58       
        self.max_steer_limit = 0.52 
        self.v_desired = 9.0   # Slow target speed for visual tracking debugging
        
        # FIXED WEIGHTS: Added heavy damping to completely smooth out the steering wheel
        self.W_cte = 500.0     # MASSIVE PRIORITY: Glue car to the centerline
        self.W_theta = 420.0   # Moderate priority: Match line heading
        self.W_v = 5.0        # Baseline priority: Maintain 2.0 m/s
        self.W_dsteer = 250.0  # DAMPING: Heavily penalize snapping the wheel rapidly






'''





'''


self.dt = 0.05
        self.N_steps = 5  
        self.wheelbase = 1.58       
        self.max_steer_limit = 0.52 
        self.v_desired = 9.0   # Slow target speed for visual tracking debugging
        
        # FIXED WEIGHTS: Added heavy damping to completely smooth out the steering wheel
        self.W_cte = 1600.0     # MASSIVE PRIORITY: Glue car to the centerline
        self.W_theta = 1000.0   # Moderate priority: Match line heading
        self.W_v = 5.0        # Baseline priority: Maintain 2.0 m/s
        self.W_dsteer = 200.0  # DAMPING: Heavily penalize snapping the wheel rapidly




'''

'''
self.W_cte = 1600.0     # MASSIVE PRIORITY: Glue car to the centerline
        self.W_theta = 1000.0   # Moderate priority: Match line heading
        self.W_v = 5.0        # Baseline priority: Maintain 2.0 m/s
        self.W_dsteer = 200.0  # DAMPING: Heavily penalize snapping the wheel rapidly

        # Live Real-World Odometry Cache
        self.car_x = None
        self.car_y = None
        self.car_heading = None
        self.current_speed = 0.0


'''
