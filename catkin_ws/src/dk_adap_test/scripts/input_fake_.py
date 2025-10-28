#!/usr/bin/env python
import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist, Pose, Point, Quaternion
import tf
import math

class FakeOdom:
    def __init__(self):
        rospy.init_node('fake_odom')
        self.odom_pub = rospy.Publisher('/odom', Odometry, queue_size=10)
        self.odom_broadcaster = tf.TransformBroadcaster()
        self.rate = rospy.Rate(10)  # 10 Hz
        self.current_time = rospy.Time.now()
        self.last_time = rospy.Time.now()
        
        self.x = 0.0
        self.y = 0.0
        self.th = 0.0

        self.v = 0.5  # linear velocity
        self.vth = 0.5  # angular velocity
        self.straight_distance = 4.0  # distance to move straight
        self.arc_radius = 1.0  # radius of the circular arc
        self.arc_length = (math.pi / 2) * self.arc_radius  # length of the 1/4 circle
        self.arc_speed = self.v / self.arc_radius  # angular speed to maintain arc radius

        self.state = 0  # 0: move straight, 1: move in a 1/4 circle
        self.state_time = 0.0
        self.arc_start_theta = 0.0
        self.arc_center_x = 0.0
        self.arc_center_y = 0.0

    def run(self):
        while not rospy.is_shutdown():
            self.current_time = rospy.Time.now()
            dt = (self.current_time - self.last_time).to_sec()
            self.state_time += dt

            if self.state == 0:  # Moving straight
                if self.state_time >= self.straight_distance / self.v:
                    self.state = 1
                    self.state_time = 0.0
                    # Start the arc
                    self.arc_center_x = self.x + (self.arc_radius * math.cos(self.th - math.pi / 2))
                    self.arc_center_y = self.y + (self.arc_radius * math.sin(self.th - math.pi / 2))
                    self.arc_start_theta = self.th
                else:
                    # Update position in a straight line
                    self.x += self.v * math.cos(self.th) * dt
                    self.y += self.v * math.sin(self.th) * dt

            else:  # Moving in a 1/4 circle
                if self.state_time >= self.arc_length / (self.v * self.arc_speed):
                    self.state = 0
                    self.state_time = 0.0
                else:
                    # Update position along the arc
                    self.th += self.arc_speed * dt
                    self.th = self.th % (2 * math.pi)
                    self.x = self.arc_center_x + self.arc_radius * math.cos(self.th - (self.arc_start_theta + math.pi / 2))
                    self.y = self.arc_center_y + self.arc_radius * math.sin(self.th - (self.arc_start_theta + math.pi / 2))

            # Create odometry message
            odom = Odometry()
            odom.header.stamp = self.current_time
            odom.header.frame_id = "odom"

            quat = tf.transformations.quaternion_from_euler(0, 0, self.th)
            odom.pose.pose = Pose(Point(self.x, self.y, 0.), Quaternion(*quat))
            odom.child_frame_id = "base_link"
            odom.twist.twist = Twist(Point(self.v * math.cos(self.th), self.v * math.sin(self.th), 0), Point(0, 0, self.arc_speed if self.state == 1 else 0))

            # Publish odometry message
            self.odom_pub.publish(odom)

            # Broadcast transform
            self.odom_broadcaster.sendTransform(
                (self.x, self.y, 0),
                quat,
                self.current_time,
                "base_link",
                "odom"
            )

            self.last_time = self.current_time
            self.rate.sleep()

if __name__ == '__main__':
    try:
        fake_odom = FakeOdom()
        fake_odom.run()
    except rospy.ROSInterruptException:
        pass
