#!/usr/bin/env python

import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from geometry_msgs.msg import Pose, Quaternion, Point
import tf
import math

class FakeOdom:
    def __init__(self):
        rospy.init_node('fake_odom')
        
        self.odom_pub = rospy.Publisher('/odom', Odometry, queue_size=10)
        self.cmd_vel_sub = rospy.Subscriber('/cmd_vel', Twist, self.cmd_vel_callback)
        
        self.x = 0.0
        self.y = 0.0
        self.th = 0.0
        
        self.vx = 0.0
        self.vy = 0.0
        self.vth = 0.0
        
        self.last_time = rospy.Time.now()
        
        rospy.loginfo("FakeOdom node initialized and subscribing to /cmd_vel")

    def cmd_vel_callback(self, msg):
        self.vx = msg.linear.x
        self.vy = msg.linear.y
        self.vth = msg.angular.z
        rospy.loginfo("Received cmd_vel: vx = %f, vy = %f, vth = %f", self.vx, self.vy, self.vth)
        
    def update_odometry(self):
        current_time = rospy.Time.now()
        dt = (current_time - self.last_time).to_sec()
        
        delta_x = (self.vx * math.cos(self.th) - self.vy * math.sin(self.th)) * dt
        delta_y = (self.vx * math.sin(self.th) + self.vy * math.cos(self.th)) * dt
        delta_th = self.vth * dt
        
        self.x += delta_x
        self.y += delta_y
        self.th += delta_th
        
        odom_quat = tf.transformations.quaternion_from_euler(0, 0, self.th)
        
        odom = Odometry()
        odom.header.stamp = current_time
        odom.header.frame_id = 'odom'
        
        odom.pose.pose = Pose()
        odom.pose.pose.position = Point(self.x, self.y, 0.0)
        odom.pose.pose.orientation = Quaternion(*odom_quat)
        
        odom.child_frame_id = 'base_link'
        odom.twist.twist.linear.x = self.vx
        odom.twist.twist.linear.y = self.vy
        odom.twist.twist.angular.z = self.vth

        odom.pose.covariance = [0.0] * 36
        odom.twist.covariance = [0.0] * 36
        
        self.odom_pub.publish(odom)
        self.last_time = current_time
        
if __name__ == '__main__':
    fake_odom = FakeOdom()
    
    r = rospy.Rate(50)  # 10 Hz
    while not rospy.is_shutdown():
        fake_odom.update_odometry()
        r.sleep()
