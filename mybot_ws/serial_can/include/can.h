#ifndef CAN_H
#define CAN_H

#include <ros/ros.h>
#include <serial/serial.h>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sensor_msgs/NavSatFix.h>
#include <utils/DiffVel.h>
#include <utils/Odometry.h>
#include <utils/Odometry_gps.h>
#include <utils/geo.h>
#include <cmath>
#include <boost/bind.hpp>
#include "std_msgs/String.h"
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/Imu.h>
#include <utils/Encoder.h>
#include <boost/algorithm/string.hpp>
#include <utils/tf.h>
#include "std_msgs/String.h"

using namespace std;
using namespace utils;
using namespace serial;


bool can_enabled;
std::string can_port;
int can_baudrate;
ros::Publisher pubOdom;
ros::Publisher pubdata;

ros::Publisher pubEncode;
ros::Publisher pubImu;
ros::Timer loopPub;
Odometry odom;
Encoder encode;
sensor_msgs::Imu imu;
#endif // GPSAHRS_RECEIVER_H


