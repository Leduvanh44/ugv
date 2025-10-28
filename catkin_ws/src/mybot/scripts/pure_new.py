#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
import math

rospy.init_node('los_with_prediction_controller')

cmd_vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)

current_x = 0.0
current_y = 0.0
current_theta = 0.0

LINEAR_SPEED = 0.5
LOOKAHEAD_DISTANCE = 1.0
GOAL_RADIUS = 0.2
MAX_LINEAR_SPEED = 0.5
MAX_ANGULAR_SPEED = 1.0
ANGULAR_SPEED = 0.75
waypoints = [(0, 0), (6, 0), (6, 6), (0, 6), (0, 0)]
current_waypoint_index = 0

def odom_callback(msg):
    global current_x, current_y, current_theta

    position = msg.pose.pose.position
    orientation = msg.pose.pose.orientation

    _, _, current_theta = euler_from_quaternion(orientation.x, orientation.y, orientation.z, orientation.w)
    
    current_x = position.x
    current_y = position.y

def euler_from_quaternion(x, y, z, w):
    import tf.transformations as tft
    euler = tft.euler_from_quaternion([x, y, z, w])
    return euler

def distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def get_heading(x1, y1, x2, y2):
    return math.atan2(y2 - y1, x2 - x1)

def get_lookahead_point(current_x, current_y, current_theta, lookahead_distance):
    lookahead_x = current_x + lookahead_distance * math.cos(current_theta)
    lookahead_y = current_y + lookahead_distance * math.sin(current_theta)
    return lookahead_x, lookahead_y

def predict_next_heading(current_x, current_y, goal_x, goal_y, lookahead_distance):
    next_index = (current_waypoint_index + 1) % len(waypoints)
    next_x, next_y = waypoints[next_index]
    
    lookahead_x, lookahead_y = get_lookahead_point(current_x, current_y, current_theta, lookahead_distance)
    predicted_heading = get_heading(lookahead_x, lookahead_y, next_x, next_y)
    
    return predicted_heading

def control_los_with_prediction(current_x, current_y, current_theta, goal_x, goal_y, lookahead_distance):
    twist = Twist()
    
    predicted_heading = predict_next_heading(current_x, current_y, goal_x, goal_y, lookahead_distance)
    
    heading_error = predicted_heading - current_theta
    
    if heading_error > math.pi:
        heading_error -= 2 * math.pi
    elif heading_error < -math.pi:
        heading_error += 2 * math.pi
    
    heading_error = max(min(heading_error, math.pi / 2), -math.pi / 2)
    twist.angular.z = min(max(ANGULAR_SPEED * heading_error, -MAX_ANGULAR_SPEED), MAX_ANGULAR_SPEED)

    distance_to_goal = distance(current_x, current_y, goal_x, goal_y)
    twist.linear.x = min(MAX_LINEAR_SPEED, LINEAR_SPEED * distance_to_goal)
    
    return twist

rate = rospy.Rate(10)

rospy.Subscriber('/odom', Odometry, odom_callback)

while not rospy.is_shutdown():
    goal_x, goal_y = waypoints[current_waypoint_index]
    dist = distance(current_x, current_y, goal_x, goal_y)
    
    twist = Twist()
    
    if dist > GOAL_RADIUS:
        twist = control_los_with_prediction(current_x, current_y, current_theta, goal_x, goal_y, LOOKAHEAD_DISTANCE)
    else:
        rospy.loginfo("Reached waypoint {}".format(waypoints[current_waypoint_index]))
        twist.linear.x = 0
        twist.angular.z = 0
        current_waypoint_index = (current_waypoint_index + 1) % len(waypoints)
    
    cmd_vel_pub.publish(twist)
    rate.sleep()
