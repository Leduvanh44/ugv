#!/usr/bin/env python

import rospy
import tf
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Twist, Pose, PoseWithCovariance, TwistWithCovariance
from utils.msg import Odometry as Odom
class ImuOdometry:
    def __init__(self):
        rospy.init_node('imu_odometry_node')
        
        self.odom_pub = rospy.Publisher('/odom', Odometry, queue_size=10)
        self.imu_sub = rospy.Subscriber('/imu/data', Imu, self.imu_callback)
        self.odom_sub = rospy.Subscriber('/odom_2', Odom, self.odom_callback)

        self.current_time = rospy.Time.now()
        self.last_time = rospy.Time.now()

        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.vx = 0.0
        self.vy = 0.0
        self.vz = 0.0
        self.th = 0.0

    def imu_callback(self, data):
        pass

    def odom_callback(self, data):
        self.current_time = rospy.Time.now()
        dt = (self.current_time - self.last_time).to_sec()
        self.last_time = self.current_time  

        orientation = data.orientation
        linear_acceleration = data.linear_acceleration

        roll, pitch, yaw = data.YPY.x, data.YPY.y, data.YPY.z 

        self.vx += linear_acceleration.x * dt
        self.vy += linear_acceleration.y * dt
        self.vz += linear_acceleration.z * dt

        self.x += self.vx * dt
        self.y += self.vy * dt
        self.z += self.vz * dt

        odom = Odometry()
        odom.header.stamp = self.current_time
        odom.header.frame_id = "odom"
        odom.child_frame_id = "base_link"

        odom.pose.pose = Pose()
        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.position.z = self.z
        odom.pose.pose.orientation = Quaternion(orientation.x, orientation.y, orientation.z, orientation.w)


        odom.twist.twist = Twist()
        odom.twist.twist.linear.x = self.vx
        odom.twist.twist.linear.y = self.vy
        odom.twist.twist.linear.z = self.vz
        odom.twist.twist.angular.x = roll
        odom.twist.twist.angular.y = pitch
        odom.twist.twist.angular.z = yaw

        self.odom_pub.publish(odom)

if __name__ == '__main__':
    try:
        imu_odometry = ImuOdometry()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
