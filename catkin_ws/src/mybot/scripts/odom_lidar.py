#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Pose2D
from nav_msgs.msg import Odometry
import tf

def callback(msg):
    odom = Odometry()
    current_time = rospy.Time.now()
    odom.header.stamp = current_time
    odom.header.frame_id = "odom"
    odom.child_frame_id = "camera_link"

    x = msg.x
    y = msg.y
    theta = msg.theta  
    
    odom.pose.pose.position.x = x
    odom.pose.pose.position.y = y
    quat = tf.transformations.quaternion_from_euler(0, 0, theta)
    odom.pose.pose.orientation.x = quat[0]
    odom.pose.pose.orientation.y = quat[1]
    odom.pose.pose.orientation.z = quat[2]
    odom.pose.pose.orientation.w = quat[3]
    odom_pub.publish(odom)

    br.sendTransform((x, y, 0),
                     quat,
                     current_time,
                     "camera_link",
                     "odom")

def listener():
    global odom_pub, br
    rospy.init_node('odometry_lidar_node', anonymous=True)
    rospy.Subscriber("/pose2D", Pose2D, callback)
    br = tf.TransformBroadcaster()
    odom_pub = rospy.Publisher("/odom", Odometry, queue_size=10)
    rospy.spin()

if __name__ == '__main__':
    listener()
