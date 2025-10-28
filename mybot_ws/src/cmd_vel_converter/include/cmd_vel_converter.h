#ifndef CMD_VEL_CONVERTER_H
#define CMD_VEL_CONVERTER_H

#include "ros/ros.h"

#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "geometry_msgs/Twist.h"
#include "std_msgs/Int32.h"
#include "utils/DiffVel.h"
#include "utils/KeyboardCommand.h"
#include <sensor_msgs/Imu.h>
#include "geometry_msgs/Quaternion.h"
#include "sensor_msgs/LaserScan.h"

#define WHEEL_DISTANCE 0.38
#define WHEEL_DIAMETER 0.09
#define THRESCHOLD_90 0.7
#define THRESCHOLD_45 1.0
#define THRESCHOLD_135 1.0

using namespace geometry_msgs;
using namespace utils;
using namespace sensor_msgs;
using namespace std;

class CmdVelConverter
{
public:
  CmdVelConverter();
  ~CmdVelConverter();
private:
  
  struct Pose{
    double x;
    double y;
    double z;
  };
  struct dQuaternion{
    double w;
    double x;
    double y;
    double z;
  };
  struct AVeloc
  {
    double v_left;
    double v_right;
  };
  
  geometry_msgs::Twist twist;
  ros::Publisher pubDiffVellSim;
  ros::Publisher pubDiffVel;
  ros::Subscriber subCmdVel;
  ros::Subscriber subYaw;
  ros::Subscriber subRange ;

  ros::Time cur_time;
  ros::Time last_time;

  double Yaw;
  double dt = 0;
  Pose dp = {0,0,0};
  Quaternion quat;
  AVeloc av;
  float range_left;
  float range_right;
  float range_front[1000];
  float range_front_left[1000];
  float range_front_right[1000];
  float min_front;
  float min_front_left;
  float min_front_right ;

  KeyboardCommand velocsim;
  DiffVel veloc;

  void subCmdVelCallback(const Twist::ConstPtr& CmdVel);
  void subIMUCallback(const Imu::ConstPtr& imu);

};
#endif //CMD_VEL_CONVERTER_H
