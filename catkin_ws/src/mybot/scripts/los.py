#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
import math

rospy.init_node('adaptive_los_trajectory_controller')

cmd_vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)

current_x = 0.0
current_y = 0.0
current_theta = 0.0

LINEAR_SPEED = 0.75
ANGULAR_SPEED = 1.5
GOAL_RADIUS = 0.3
LOOKAHEAD_DISTANCE = 0.1
MAX_LINEAR_SPEED = 1
MAX_ANGULAR_SPEED = 1.5

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

def control_adaptive_los(current_x, current_y, current_theta, goal_x, goal_y, next_goal_x=None, next_goal_y=None, next_next_goal_x=None, next_next_goal_y=None):
    x_fake, y_fake = get_lookahead_point(current_x, current_y, current_theta, LOOKAHEAD_DISTANCE)
    twist = Twist()
    target_heading = get_heading(x_fake, y_fake, goal_x, goal_y)

    heading_error = target_heading - current_theta    
    if heading_error > math.pi:
        heading_error -= 2 * math.pi
    elif heading_error < -math.pi:
        heading_error += 2 * math.pi
    heading_error = max(min(heading_error, math.pi / 2), -math.pi / 2)
    twist.angular.z = min(max(ANGULAR_SPEED * heading_error, -MAX_ANGULAR_SPEED), MAX_ANGULAR_SPEED)
    if abs(heading_error) > math.pi / 4:
        twist.linear.x = min(MAX_LINEAR_SPEED / 2, LINEAR_SPEED * distance(current_x, current_y, goal_x, goal_y))
    else:
        twist.linear.x = min(MAX_LINEAR_SPEED, LINEAR_SPEED * distance(current_x, current_y, goal_x, goal_y))
    return twist

def control_los(current_x, current_y, current_theta, goal_x, goal_y):
    twist = Twist()
    target_heading = get_heading(current_x, current_y, goal_x, goal_y)
    heading_error = target_heading - current_theta
    
    if heading_error > math.pi:
        heading_error -= 2 * math.pi
    elif heading_error < -math.pi:
        heading_error += 2 * math.pi

    heading_error = max(min(heading_error, math.pi / 2), -math.pi / 2)
    twist.angular.z = min(max(ANGULAR_SPEED * heading_error, -MAX_ANGULAR_SPEED), MAX_ANGULAR_SPEED)

    distance_to_goal = distance(current_x, current_y, goal_x, goal_y)
    twist.linear.x = min(MAX_LINEAR_SPEED, LINEAR_SPEED * distance_to_goal)
    
    return twist

def interpolate_waypoints(waypoints, resolution=0.5, remove_old_waypoints=False):
    new_waypoints = []
    
    for i in range(len(waypoints) - 1):
        start_x, start_y = waypoints[i]
        end_x, end_y = waypoints[i + 1]
        
        dist = distance(start_x, start_y, end_x, end_y)
        num_points = int(dist / resolution)
        
        for j in range(num_points):
            ratio = j / float(num_points)
            interp_x = start_x + ratio * (end_x - start_x)
            interp_y = start_y + ratio * (end_y - start_y)
            new_waypoints.append((interp_x, interp_y))
    
    new_waypoints.append(waypoints[-1]) 

    if remove_old_waypoints:
        waypoints = [waypoints[0]] + new_waypoints[1:-1] + [waypoints[-1]]
    
    rospy.loginfo("Generated waypoints:")
    for i, waypoint in enumerate(waypoints if remove_old_waypoints else new_waypoints):
        rospy.loginfo("Waypoint {}: x = {}, y = {}".format(i, waypoint[0], waypoint[1]))
    
    return new_waypoints if not remove_old_waypoints else waypoints

waypoints = interpolate_waypoints(waypoints, resolution=2, remove_old_waypoints=True)

rate = rospy.Rate(10)

rospy.Subscriber('/odom', Odometry, odom_callback)

while not rospy.is_shutdown():
    goal_x, goal_y = waypoints[current_waypoint_index]
    goal_xn, goal_yn = waypoints[current_waypoint_index + 1]
    goal_xnn, goal_ynn = waypoints[current_waypoint_index + 2]

    dist = distance(current_x, current_y, goal_x, goal_y)
    
    twist = Twist()
    
    if dist > GOAL_RADIUS:
        twist = control_adaptive_los(current_x, current_y, current_theta, goal_x, goal_y, goal_xn, goal_yn, goal_xnn, goal_ynn)
    else:
        rospy.loginfo("Reached waypoint {}".format(waypoints[current_waypoint_index]))
        # twist.linear.x = 0
        # twist.angular.z = 0
        current_waypoint_index = (current_waypoint_index + 1) % len(waypoints)
    
    cmd_vel_pub.publish(twist)
    rate.sleep()
