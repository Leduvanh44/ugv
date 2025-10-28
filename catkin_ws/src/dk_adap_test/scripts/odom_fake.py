#!/usr/bin/env python
import rospy
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist, Pose, Point, Quaternion
from dk_adap_test.msg import ref, state
from std_msgs.msg import Int32
import tf
import math
import random
class FakeOdom:
    def __init__(self):
        rospy.init_node('fake_odom')
        self.odom_pub = rospy.Publisher('/odom', Odometry, queue_size=10)
        self.state_pub = rospy.Publisher('/state', state, queue_size=10)

        self.odom_broadcaster = tf.TransformBroadcaster()
        self.ref_points_sub = rospy.Subscriber('/reference_points', ref, self.ref_points_callback)
        self.rate = rospy.Rate(10)
        self.current_time = rospy.Time.now()
        self.last_time = rospy.Time.now()
        
        self.x = 0.5
        self.y = 0.0
        self.th = 0.0
        self.phi = 0
        self.v = 0.5  # linear velocity
        self.vth = math.pi / 2  # angular velocity
        self.ref_points = []
        self.current_ref_index = 0
        self.tolerance = 0.005
        self.turning = False

    def ref_points_callback(self, msg):
        self.ref_points = msg.points
        if not self.ref_points:
            rospy.logwarn("No reference points received.")
            return

    def check_proximity(self, x, y, point):
        distance = math.sqrt((x - point.x)**2 + (y - point.y)**2)
        self.phi = math.atan2((point.y - y), (point.x - x))
        angular_velocity_z = self.vth
        # y_wtf = y + 0.1 * math.cos(self.phi)
        # x_wtf = x + 0.1 * math.cos(self.phi)
        # rospy.loginfo("x?: {}, y?: {}, {}".format(x_wtf, y_wtf, self.phi))
        # rospy.loginfo("distance: {}, phi: {}, angular_vel: {}".format(distance, phi, angular_velocity_z))
        return distance < self.tolerance

    def run(self):
        while not rospy.is_shutdown():
            self.current_time = rospy.Time.now()
            dt = (self.current_time - self.last_time).to_sec()
            if self.ref_points and self.current_ref_index < len(self.ref_points):
                current_point = self.ref_points[self.current_ref_index]
                
                if self.check_proximity(self.x, self.y, current_point):
                    rospy.loginfo("Reached reference point ID: {}".format(self.current_ref_index))
                    self.current_ref_index += 1
                    self.turning = True
                    # if self.check_proximity(self.x, self.y, Point(0.0, 0.0, 0.0)):
                    #     self.turn_target = (self.th - math.pi / 2) % (2 * math.pi)
                    # else:
                    self.turn_target = (self.th + math.pi / 2) % (2 * math.pi)

            if self.turning:
                if abs(self.th - self.turn_target) < 0.01:
                    self.turning = False
                else:
                    self.th += self.vth * dt
                    self.th = self.th % (2 * math.pi)
            else:
                self.x += self.v * math.cos(self.th) * dt
                self.y += self.v * math.sin(self.th) * dt

            odom = Odometry()
            odom.header.stamp = self.current_time
            odom.header.frame_id = "odom"

            quat = tf.transformations.quaternion_from_euler(0, 0, self.th)
            odom.pose.pose = Pose(Point(self.x, self.y, 0.), Quaternion(*quat))
            odom.child_frame_id = "base_link"
            odom.twist.twist = Twist(Point(self.v * math.cos(self.th), self.v * math.sin(self.th), 0), Point(0, 0, self.vth if self.turning else 0))

            self.odom_pub.publish(odom)
            self.odom_broadcaster.sendTransform(
                (self.x, self.y, 0),
                quat,
                self.current_time,
                "base_link",
                "odom"
            )

            self.last_time = self.current_time
            state_msg = state()
            # noise_x = random.gauss(0, 0.01)
            # noise_y = random.gauss(0, 0.01)
            state_msg.x = self.x
            state_msg.y = self.y
            state_msg.phi = self.x
            state_msg.linear_velocity = self.v
            state_msg.angular_velocity = self.vth
            self.state_pub.publish(state_msg)
            self.rate.sleep()

if __name__ == '__main__':
    try:
        fake_odom = FakeOdom()
        fake_odom.run()
    except rospy.ROSInterruptException:
        pass
