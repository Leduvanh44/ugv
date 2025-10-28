#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
import sys, select, termios, tty

rospy.init_node('cmd_vel_publisher')

cmd_vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)

MAX_LINEAR_SPEED = 0.5  # m/s
MAX_ANGULAR_SPEED = 1.0  # rad/s

settings = termios.tcgetattr(sys.stdin)

def getKey():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

try:

    print("w/a/s/d")
    print("q=exit")


    while True:
        key = getKey()
        if key == 'w':
            linear_speed = MAX_LINEAR_SPEED
            angular_speed = 0.0
        elif key == 's':
            linear_speed = -MAX_LINEAR_SPEED
            angular_speed = 0.0
        elif key == 'a':
            linear_speed = 0.0
            angular_speed = MAX_ANGULAR_SPEED
        elif key == 'd':
            linear_speed = 0.0
            angular_speed = -MAX_ANGULAR_SPEED
        else:
            linear_speed = 0.0
            angular_speed = 0.0


        twist = Twist()
        twist.linear.x = linear_speed
        twist.angular.z = angular_speed

        cmd_vel_pub.publish(twist)

        if key == 'q':
            break

except Exception as e:
    print(e)

finally:
    # Reset terminal settings
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
