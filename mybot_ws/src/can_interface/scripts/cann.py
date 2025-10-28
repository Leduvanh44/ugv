#!/usr/bin/env python

import rospy
from utils.msg import Encoder
import subprocess

def encoder_callback(msg):
    left_twist = msg.left_twist
    right_twist = msg.right_twist
    data = "1234"
    data = "{:02X}{:02X}".format(int(msg.left_twist), int(msg.right_twist))    
    cansend_command = f"cansend can0 111#{data}"
    try:
        subprocess.run(cansend_command, shell=True, check=True)
        rospy.loginfo(f"Sent CAN message: {data}")
    except subprocess.CalledProcessError as e:
        rospy.logerr(f"Failed to send CAN message: {e}")

if __name__ == '__main__':
    rospy.init_node('can_publisher')
    rospy.Subscriber('diff_motor/real_vel', Encoder, encoder_callback)
    rospy.spin()
