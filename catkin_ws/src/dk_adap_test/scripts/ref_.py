#!/usr/bin/env python

import rospy
from dk_adap_test.msg import ref
from geometry_msgs.msg import Point

class ReferencePointsPublisher:
    def __init__(self):
        rospy.init_node('rp_publisher')
        self.ref_pub = rospy.Publisher('/points', ref, queue_size=10)
        self.rate = rospy.Rate(1) 
        self.dt = 1.0 
        self.resolution = 10
        self.points = [
            Point(1.0, 0.0, 0.0), 
            Point(2.0, 0.0, 0.0), 
            Point(3.0, 0.0, 0.0), 
            Point(4.0, 0.0, 0.0), 
            Point(5.0, 0.0, 0.0), 
            Point(6.0, 0.0, 0.0), 
            Point(6.0, 1.0, 0.0), 
            Point(6.0, 2.0, 0.0), 
            Point(6.0, 3.0, 0.0), 
            Point(6.0, 4.0, 0.0), 
            Point(6.0, 5.0, 0.0), 
            Point(6.0, 6.0, 0.0), 
            Point(5.0, 6.0, 0.0),
            Point(4.0, 6.0, 0.0), 
            Point(3.0, 6.0, 0.0), 
            Point(2.0, 6.0, 0.0),  
            Point(1.0, 6.0, 0.0),  
            Point(0.0, 6.0, 0.0),
            Point(0.0, 5.0, 0.0),
            Point(0.0, 4.0, 0.0),
            Point(0.0, 3.0, 0.0),
            Point(0.0, 2.0, 0.0),
            Point(0.0, 1.0, 0.0),
            Point(0.0, 0.0, 0.0),
            Point(1.0, 0.0, 0.0), 
            Point(2.0, 0.0, 0.0), 
            Point(3.0, 0.0, 0.0), 
            Point(4.0, 0.0, 0.0), 
            Point(5.0, 0.0, 0.0), 
            Point(6.0, 0.0, 0.0), 
            Point(6.0, 1.0, 0.0), 
            Point(6.0, 2.0, 0.0), 
            Point(6.0, 3.0, 0.0), 
            Point(6.0, 4.0, 0.0), 
            Point(6.0, 5.0, 0.0), 
            Point(6.0, 6.0, 0.0), 
            Point(5.0, 6.0, 0.0),
            Point(4.0, 6.0, 0.0), 
            Point(3.0, 6.0, 0.0), 
            Point(2.0, 6.0, 0.0),  
            Point(1.0, 6.0, 0.0),  
            Point(0.0, 6.0, 0.0),
            Point(0.0, 5.0, 0.0),
            Point(0.0, 4.0, 0.0),
            Point(0.0, 3.0, 0.0),
            Point(0.0, 2.0, 0.0),
            Point(0.0, 1.0, 0.0),
            Point(0.0, 0.0, 0.0)
        ]
        self.points = self.interpolate_points()
        self.first_derivatives = self.calculate_first_derivatives()
        self.second_derivatives = self.calculate_second_derivatives()

    def interpolate_points(self):
        interpolated_points = []
        
        for i in range(len(self.points) - 1):
            p1 = self.points[i]
            p2 = self.points[i + 1]
            
            interpolated_points.append(p1)
            
            dx = (p2.x - p1.x) / self.resolution
            dy = (p2.y - p1.y) / self.resolution
            dz = (p2.z - p1.z) / self.resolution
            
            for j in range(1, self.resolution):
                new_x = p1.x + dx * j
                new_y = p1.y + dy * j
                new_z = p1.z + dz * j
                interpolated_points.append(Point(new_x, new_y, new_z))
        
        interpolated_points.append(self.points[-1])
        
        return interpolated_points


    def calculate_first_derivatives(self):
        first_derivatives = []
        first_derivatives.append(Point(0, 0, 0))
        for i in range(len(self.points) - 1):
            p1 = self.points[i]
            p2 = self.points[i + 1]
            dx = (p2.x - p1.x) / self.dt
            dy = (p2.y - p1.y) / self.dt
            dz = (p2.z - p1.z) / self.dt
            first_derivatives.append(Point(dx, dy, dz))
        return first_derivatives

    def calculate_second_derivatives(self):
        second_derivatives = []
        second_derivatives.append(Point(0, 0, 0))
        first_derivs = self.first_derivatives
        for i in range(len(first_derivs) - 1):
            d1 = first_derivs[i]
            d2 = first_derivs[i + 1]
            ddx = (d2.x - d1.x) / self.dt
            ddy = (d2.y - d1.y) / self.dt
            ddz = (d2.z - d1.z) / self.dt
            second_derivatives.append(Point(ddx, ddy, ddz))
        return second_derivatives

    def run(self):
        while not rospy.is_shutdown():
            ref_points_msg = ref()
            ref_points_msg.points = self.points
            ref_points_msg.vel = self.first_derivatives
            ref_points_msg.accel = self.second_derivatives
            ref_points_msg.points 
            self.ref_pub.publish(ref_points_msg)
            rospy.loginfo("Published reference points, {}, {}, {}".format(len(self.points), len(self.first_derivatives), len(self.second_derivatives)))
            self.rate.sleep()

if __name__ == '__main__':
    try:
        reference_points_publisher = ReferencePointsPublisher()
        reference_points_publisher.run()
    except rospy.ROSInterruptException:
        pass
