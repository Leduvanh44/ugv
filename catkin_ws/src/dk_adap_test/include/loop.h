#ifndef LOOP_H
#define LOOP_H

#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int32.h>
#include <Eigen/Dense>
#include <vector>
#include "dk_adap_test/ref.h"
#include "dk_adap_test/state.h"
#include "class_dk.h"
#include <geometry_msgs/Point.h>
using namespace Eigen;

class Loop {
public:
    Loop();
    ~Loop();

    void refCallback(const dk_adap_test::ref::ConstPtr& msg);
    void stateCallback(const dk_adap_test::state::ConstPtr& msg);
    void idCallback(const std_msgs::Int32::ConstPtr& msg);
    void onControlLoop(const ros::TimerEvent& event);

    ros::NodeHandle nh_;
    ros::Subscriber ref_sub_;
    ros::Subscriber state_sub_;
    ros::Subscriber id_sub_;
    ros::Publisher control_pub_;
    ros::Timer loopControl_;

    std::vector<double> waypoint_outdoor_x;
    std::vector<double> waypoint_outdoor_y;

    std::vector<geometry_msgs::Point> waypoints;
    std::vector<geometry_msgs::Point> vels;
    std::vector<geometry_msgs::Point> accels;
    std::vector<double> alpha_P;
    VectorXd y_dot = VectorXd(2);
    VectorXd n_xy = VectorXd(2);

    double Beta1, Beta2, K;
    double yr, yr_dot, yr_2dot, xr, xr_dot, xr_2dot;
    double x_, y_;
    double previous_yr, previous_yr_dot;
    double previous_xr, previous_xr_dot;
    double yodom, yodom_dot, yodom_2dot, xodom, xodom_dot, xodom_2dot;
    double previous_yodom, previous_yodom_dot;
    double previous_xodom, previous_xodom_dot;
    L2f_hFunction l2f_;
    ThetaEstimator theta_compute;
    NonelinearSFeedback dk;
    StraightLOS los;
    double ex, ex_dot, ey, ey_dot;
    VectorXd ua_dk;
    VectorXd ua_dk_prev;
    double x_x, x_y, x_linearVel, x_angularVel, x_phi;
    int id;
    ros::Time previous_time_x;
    ros::Time previous_time_y;
    ros::Time previous_time_xodom;
    ros::Time previous_time_yodom;
    ros::Time prev_time;
};

#endif // LOOP_H
