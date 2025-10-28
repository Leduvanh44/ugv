#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include "std_msgs/Float32.h"
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <cmath>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <utils/Odometry.h>
#include <utils/Position_avoid_obstacles.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

using namespace std;

float width = 0.5 ;
float hight = 0.75;

float CurrX_outdoor, CurrY_outdoor ;
float CurrX, CurrY ;

float CurrOrient_outdoor ;

float min_front  ;
float min_front_left  ;
float min_front_right ;
float _min;

float range_front[1000] ;
float range_front_left[1000] ;
float range_front_right[1000];

int location_obstacle ;
int min_front_element;
float angle_min_front;
float angle_min_front_left;
float angle_min_front_right;

int min_front_left_element;
int min_front_right_element;

float angle_avoid;
float angle_add ;
float angle_new_waypoint;
float distance_avoid;

float pos_x, pos_y ;
float x_add, y_add ;
bool _trueObs;

float new_waypointX_outdoor, new_waypointY_outdoor;

