#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from tf.transformations import euler_from_quaternion
import math

class LinearizedController:
    def __init__(self):
        rospy.init_node('linearized_controller')

        self.cmd_vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
        self.odom_sub = rospy.Subscriber('/odom', Odometry, self.odom_callback)

        self.rate = rospy.Rate(2)  # 10 Hz
        self.current_pose = None

        # Define square corners
        self.corners = [(0, 0), (6, 0), (6, 6), (0, 6), (0, 0)]
        self.current_target_index = 0
        self.current_target = self.corners[self.current_target_index]

        # Linearized control parameters
        self.Kp_linear = 0.2
        self.Kp_angular = 0.8

    def odom_callback(self, msg):
        position = msg.pose.pose.position
        orientation = msg.pose.pose.orientation
        _, _, theta = euler_from_quaternion([orientation.x, orientation.y, orientation.z, orientation.w])
        self.current_pose = (position.x, position.y, theta)

    def move_to_target(self):
        if self.current_pose is None:
            return

        twist = Twist()
        px, py, theta = self.current_pose
        tx, ty = self.current_target

        # Calculate distance and angle to target
        distance = math.sqrt((tx - px)**2 + (ty - py)**2)
        angle_to_target = math.atan2(ty - py, tx - px)
        angle_error = angle_to_target - theta
        angle_error = (angle_error + math.pi) % (2 * math.pi) - math.pi  # Normalize to [-pi, pi]

        # Linear control
        twist.linear.x = self.Kp_linear * distance
        # Angular control
        twist.angular.z = self.Kp_angular * angle_error

        # Update target if close enough
        if distance < 0.1:
            self.current_target_index = (self.current_target_index + 1) % len(self.corners)
            self.current_target = self.corners[self.current_target_index]

        self.cmd_vel_pub.publish(twist)

    def run(self):
        while not rospy.is_shutdown():
            self.move_to_target()
            self.rate.sleep()

if __name__ == '__main__':
    controller = LinearizedController()
    try:
        controller.run()
    except rospy.ROSInterruptException:
        pass
