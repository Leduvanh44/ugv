#!/usr/bin/env python

import rospy
from std_msgs.msg import Float64
import math

# def sin_wave_publisher():
#     rospy.init_node('odom_node', anonymous=True)

#     x_pub = rospy.Publisher('input_x', Float64, queue_size=10)
#     y_pub = rospy.Publisher('input_y', Float64, queue_size=10)
#     rate = rospy.Rate(10)
#     x = 0.0
#     while not rospy.is_shutdown():
#         y =5 * math.sin(x)
#         x_pub.publish(x)
#         y_pub.publish(y)
#         x += 0.05
#         rate.sleep()

# if __name__ == '__main__':
#     try:
#         sin_wave_publisher()
#     except rospy.ROSInterruptException:
#         pass
from dk_adap_test.msg import ref
from geometry_msgs.msg import Point

class ReferencePointsPublisher:
    def __init__(self):
        rospy.init_node('reference_points_publisher')
        self.ref_pub = rospy.Publisher('/reference_points', ref, queue_size=10)
        self.rate = rospy.Rate(1)  # 1 Hz
        self.points = [
            Point(0.0, 0.0, 0.0),
            # Point(1.0, 0.0, 0.0), 
            # Point(2.0, 0.0, 0.0), 
            # Point(3.0, 0.0, 0.0), 
            # Point(4.0, 0.0, 0.0), 
            # Point(5.0, 0.0, 0.0), 
            Point(6.0, 0.0, 0.0), 
            # Point(6.0, 1.0, 0.0), 
            # Point(6.0, 2.0, 0.0), 
            # Point(6.0, 3.0, 0.0), 
            # Point(6.0, 4.0, 0.0), 
            # Point(6.0, 5.0, 0.0), 
            Point(6.0, 6.0, 0.0),
            # Point(5.0, 6.0, 0.0),
            # Point(4.0, 6.0, 0.0), 
            # Point(3.0, 6.0, 0.0), 
            # Point(2.0, 6.0, 0.0),  
            # Point(1.0, 6.0, 0.0),  
            Point(0.0, 6.0, 0.0),
            # Point(0.0, 5.0, 0.0),
            # Point(0.0, 4.0, 0.0),
            # Point(0.0, 3.0, 0.0),
            # Point(0.0, 2.0, 0.0),
            # Point(0.0, 1.0, 0.0),
            Point(0.0, 0.0, 0.0),
            # Point(1.0, 0.0, 0.0), 
            # Point(2.0, 0.0, 0.0), 
            # Point(3.0, 0.0, 0.0), 
            # Point(4.0, 0.0, 0.0), 
            # Point(5.0, 0.0, 0.0), 
            Point(-6.0, 0.0, 0.0), 
            # Point(6.0, 1.0, 0.0), 
            # Point(6.0, 2.0, 0.0), 
            # Point(6.0, 3.0, 0.0), 
            # Point(6.0, 4.0, 0.0), 
            # Point(6.0, 5.0, 0.0), 
            Point(-6.0, -6.0, 0.0), 
            # Point(5.0, 6.0, 0.0),
            # Point(4.0, 6.0, 0.0), 
            # Point(3.0, 6.0, 0.0), 
            # Point(2.0, 6.0, 0.0),  
            # Point(1.0, 6.0, 0.0),  
            Point(0.0, -6.0, 0.0),
            # Point(0.0, 5.0, 0.0),
            # Point(0.0, 4.0, 0.0),
            # Point(0.0, 3.0, 0.0),
            # Point(0.0, 2.0, 0.0),
            # Point(0.0, 1.0, 0.0),
            Point(0.0, 0.0, 0.0)
        ]
    def run(self):
        while not rospy.is_shutdown():
            ref_points_msg = ref()
            ref_points_msg.points = self.points
            self.ref_pub.publish(ref_points_msg)
            rospy.loginfo("Published reference points")
            self.rate.sleep()

if __name__ == '__main__':
    try:
        reference_points_publisher = ReferencePointsPublisher()
        reference_points_publisher.run()
    except rospy.ROSInterruptException:
        pass