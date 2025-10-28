#include "loop.h"
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

Loop::Loop() : Beta1(2), Beta2(1), K(0), ua_dk(VectorXd(2)) {
    ref_sub_ = nh_.subscribe("/points", 10, &Loop::refCallback, this);
    id_sub_ = nh_.subscribe("/current_point_id", 10, &Loop::idCallback, this);
    state_sub_ = nh_.subscribe("/state", 10, &Loop::stateCallback, this);
    control_pub_ = nh_.advertise<std_msgs::Float64>("control_signal", 10);
    float controlling_period = 0.5;
    loopControl_ = nh_.createTimer(ros::Duration(controlling_period), &Loop::onControlLoop, this);
    los.setupPubSub();
    l2f_.resetPara();
    theta_compute.resetPara();
    dk.setParameter();
    id = 0;
    n_xy << 0, 0;
    ua_dk_prev = Eigen::VectorXd::Zero(2);
}

Loop::~Loop() {

}

void Loop::refCallback(const dk_adap_test::ref::ConstPtr& msg) {
    waypoint_outdoor_x.clear();
    waypoint_outdoor_y.clear();
    waypoints.clear();
    vels.clear();
    accels.clear();
    waypoints = msg->points;
    vels = msg->vel;
    accels = msg->accel;
    ROS_INFO_STREAM("adsf " << waypoints.size() << ", " << vels.size());
    for (const auto& point : msg->points) {
        waypoint_outdoor_x.push_back(point.x);
        waypoint_outdoor_y.push_back(point.y);
        // ROS_INFO("Point(x: %f, y: %f, z: %f)", point.x, point.y);
        // alpha_P = los.alpha_P;    
    }
    
}

void Loop::stateCallback(const dk_adap_test::state::ConstPtr& msg) {
    x_x = msg->x;
    x_y = msg->y;    
    x_phi = msg->phi;
    x_ = x_x + 0.1 * cos(x_phi);
    y_ = x_y + 0.1 * sin(x_phi);
    x_linearVel = msg->linear_velocity;
    x_angularVel = msg->angular_velocity;
    double L  = 0.1;
    MatrixXd Jh_q(2, 3);
    Jh_q << 1, 0, -L * sin(x_phi),
        0, 1, L * cos(x_phi); 
      MatrixXd S(3, 2);
      S << cos(x_phi), 0,
            sin(x_phi), 0,
            0, 1; 
    VectorXd vel = VectorXd(2);
    vel << x_linearVel, x_angularVel;
    y_dot = Jh_q * S * vel;
    // ROS_INFO("ydot(a: %f, a: %f)", y_dot(0), y_dot(1));
}

void Loop::idCallback(const std_msgs::Int32::ConstPtr& msg) {

    id = msg->data;
}

void Loop::onControlLoop(const ros::TimerEvent& event) {
    try {
        los.runLOS(x_x, x_y);
        if(los.alpha_P.size() > 0 && waypoints.size() > 0 && vels.size() > 0) {
            ROS_INFO_STREAM("phi x ^ heading: " << los.alpha_P[id] << ", " << waypoints[id].x);
            ex = Beta2 * (x_ - waypoints[id].x);
            ey = Beta2 * (y_ - waypoints[id].y);
            ex_dot = Beta1 * (y_dot(0) - vels[id].x);
            ey_dot = Beta1 * (y_dot(1) - vels[id].y);
            n_xy(0) = accels[id].x - ex - ex_dot;
            n_xy(1) = accels[id].y - ey - ey_dot;
        }
        
        // ROS_INFO_STREAM("ex: " << ex);
        // ROS_INFO_STREAM("ey: " << ey);
        // ROS_INFO_STREAM("ex_dot: " << ex_dot);
        // ROS_INFO_STREAM("ey_dot: " << ey_dot);
        l2f_.q << x_x, x_y, x_phi;
        l2f_.v << x_linearVel, x_angularVel;
        theta_compute.L2f_h = l2f_.computeL2f_h();
        theta_compute.e << ex, ey;
        theta_compute.e_dot << ex_dot, ey_dot;
        theta_compute.x << x_x, x_y, x_phi, x_linearVel, x_angularVel;
        theta_compute.n << 0, 0;
        dk.theta_est = theta_compute.computeThetaEst();
        dk.n << 0, 0;
        dk.x0 = x_x;
        dk.y0 = x_y;
        dk.phi = x_phi;
        dk.vr = x_linearVel;
        dk.wr = x_angularVel;
        ua_dk = dk.computeUdk();
        ros::Time current_time = ros::Time::now();
        double dt = (current_time - prev_time).toSec();
        if (dt > 0) {
            Eigen::VectorXd ua_dk_dot = (ua_dk - ua_dk_prev) / dt;
            ROS_INFO_STREAM("UA dk derivative: " << ua_dk_dot(0) << ", " << ua_dk_dot(1));
        }
        ua_dk_prev = ua_dk;
        prev_time = current_time;
        ROS_INFO_STREAM("UA dk: " << ua_dk(0) << ", " << ua_dk(1));
    }
    
    catch(const std::exception& e)
    {

    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "controller_node");
    Loop loop;
    ros::spin();
    return 0;
}
