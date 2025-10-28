#ifndef NEW_GUIDER_H
#define NEW_GUIDER_H

#include "adap_pid.h"
#include <utils/WaypointList.h>
#include <sensor_msgs/LaserScan.h>
#include <utils/Odometry.h>
#include <utils/Setpoint.h>
#include <utils/Error.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <utils/CommandLong.h>
#include <utils/ParamGet.h>
#include <utils/ParamSet.h>
#include <utils/SetMode.h>
#include <utils/mode_indoor.h>
#include <utils/Complete.h>
#include <utils/Position_avoid_obstacles.h>
#include <utils/pointID.h>
#include <utils/goal_indoor.h>
#include <utils/heading_plot.h>
#include <utils/CommandInt.h>
#include <utils/CommandLong.h>
#include <utils/ParamGet.h>
#include <utils/ParamSet.h>
#include <utils/Odometry_gps.h> 
#include <utils/DiffVel.h>
#include <utils/obtacles.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

#include "utils/geo.h"
#include "straight_LOS.h"
#include <tf/tf.h>

using namespace utils;

class newGuider
{
public:
    newGuider();
    ~newGuider();
    ros::NodeHandle nh;
    double ned_lat;
    double ned_lon;
    double controlling_period = 0.02;

    double currX;
    double currY;
    double pre_currX;
    double pre_currY;
    double currHeading;
    double pre_heading;


    bool set_com_avoid = true;
    bool com_avoid;

    ros::Subscriber subHeading;
    ros::Subscriber subOdom;

    Derivative diff_x, diff_y, diff_heading;


    ros::Timer loopControl;
    ros::Time lastControlUpdateTime;

    ThetaEstimator thetaEs;
    L2f_hFunction L2h_ffun;
    VectorXd thetaest;
    double desiredSpeed;
    double desiredHeading;
    double speed;
    double heading;
    void onOdomCallBack(const Odometry::ConstPtr &msg);
    void onHeadingCallBack(const Odometry::ConstPtr &msg);
    void onControlLoop(const ros::TimerEvent& event);
};
#endif // NEW_GUIDER_H

