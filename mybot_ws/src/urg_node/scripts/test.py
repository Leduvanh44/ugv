#!/usr/bin/env python

import rospy
import math
from sensor_msgs.msg import LaserScan
from utils.msg import Position_avoid_obstacles, Odometry, obtacles

CurrX_outdoor = 0.0
CurrY_outdoor = 0.0
x_add = 0.0
y_add = 0.0
_trueObs = False
width = 0.5
angle_avoid = 0 

def CallbackCurrPositionoutdoor(data):
    global CurrX_outdoor, CurrY_outdoor
    CurrX_outdoor = data.position.x
    CurrY_outdoor = data.position.y

def CallrangeLaser(laser):
    global x_add, y_add, _trueObs, width, angle_avoid

    distance_threshold = 30
    min_distance = laser.range_max  
    min_index = -1 

    for i in range(len(laser.ranges)):
        if laser.ranges[i] < min_distance:
            min_distance = laser.ranges[i]
            min_index = i

    if min_distance <= distance_threshold:
        _trueObs = True

        angle_min = laser.angle_min + min_index * laser.angle_increment
        angle_avoid = angle_min + math.atan(1.5 * width / min_distance)
        # if angle_avoid * 180 / math.pi > 180 and angle_avoid * 180 / math
        distance_avoid = math.sqrt(min_distance**2 + (1.5 * width)**2)
        rospy.loginfo("Angle: angle_min = {:.2f}, angle_avoid = {:.2f}".format(angle_min * 180 / math.pi, angle_avoid  * 180 / math.pi))

        x_add = distance_avoid * math.cos(angle_avoid)
        y_add = distance_avoid * math.sin(angle_avoid)
    else:
        _trueObs = False
        x_add = 0.0
        y_add = 0.0

    CurrX = CurrX_outdoor
    CurrY = CurrY_outdoor
    new_waypointX_outdoor = CurrX + x_add
    new_waypointY_outdoor = CurrY + y_add

    # rospy.loginfo("New waypoint: X = {:.2f}, Y = {:.2f}".format(new_waypointX_outdoor, new_waypointY_outdoor))

def main():
    rospy.init_node('avoid_obstacle_node', anonymous=True)

    rospy.Subscriber('/odom_1', Odometry, CallbackCurrPositionoutdoor)
    rospy.Subscriber('/scan', LaserScan, CallrangeLaser)
    pub_pos_avoid = rospy.Publisher('/_position_avoid', Position_avoid_obstacles, queue_size=50)
    pub_vel_avoid = rospy.Publisher('/lidar_avoid', obtacles, queue_size=50)

    rate = rospy.Rate(20) 
    while not rospy.is_shutdown():
        position_avoid_msg = Position_avoid_obstacles()
        position_avoid_msg.position_avoid_x = CurrX_outdoor + x_add
        position_avoid_msg.position_avoid_y = CurrY_outdoor + y_add
        position_avoid_msg.obstacles = _trueObs
        pub_pos_avoid.publish(position_avoid_msg)
        vel_avoid_msg = obtacles()
        vel_avoid_msg.lidar = _trueObs
        vel_avoid_msg.angle_avoid_lidar = angle_avoid * 180 / math.pi
        pub_vel_avoid.publish(vel_avoid_msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
