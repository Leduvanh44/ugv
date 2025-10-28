#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from math import atan2, sqrt, sin, cos
import numpy as np

LOOKAHEAD_DISTANCE = 0.5
LINEAR_SPEED = 0.5 
WAYPOINT_THRESHOLD = 0.1

waypoints = [(6, 0), (6, 6), (0, 6), (0, 0)]
current_waypoint_index = 0

rospy.init_node('pure_pursuit_controller')

cmd_vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)

def odom_callback(data):
    global current_waypoint_index
    current_x = data.pose.pose.position.x
    current_y = data.pose.pose.position.y
    orientation_q = data.pose.pose.orientation
    current_theta = atan2(2.0 * (orientation_q.w * orientation_q.z + orientation_q.x * orientation_q.y), 
                          1.0 - 2.0 * (orientation_q.y * orientation_q.y + orientation_q.z * orientation_q.z))

    target_x, target_y = waypoints[current_waypoint_index]
    lookahead_point = get_lookahead_point(current_x, current_y, target_x, target_y, LOOKAHEAD_DISTANCE)

    alpha = atan2(lookahead_point[1] - current_y, lookahead_point[0] - current_x) - current_theta
    angular_speed = 2 * LINEAR_SPEED * sin(alpha) / LOOKAHEAD_DISTANCE

    twist = Twist()
    twist.linear.x = LINEAR_SPEED
    twist.angular.z = angular_speed
    cmd_vel_pub.publish(twist)

    if sqrt((current_x - target_x)**2 + (current_y - target_y)**2) < WAYPOINT_THRESHOLD:
        current_waypoint_index += 1
        if current_waypoint_index >= len(waypoints):
            current_waypoint_index = 0 
def get_lookahead_point(current_x, current_y, target_x, target_y, lookahead_distance):
    direction = np.array([target_x - current_x, target_y - current_y])
    norm_direction = direction / np.linalg.norm(direction)
    lookahead_point = np.array([current_x, current_y]) + lookahead_distance * norm_direction
    return lookahead_point

odom_sub = rospy.Subscriber('/odom', Odometry, odom_callback)

rospy.spin()
