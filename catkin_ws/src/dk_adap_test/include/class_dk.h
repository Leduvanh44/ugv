#ifndef CLASS_DK_H
#define CLASS_DK_H

#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <Eigen/Dense>
#include <time.h>
#include <vector>
#include <dk_adap_test/ref.h>
#include <geometry_msgs/Point.h>
#include <cmath>
#include <std_msgs/Int32.h>


using namespace Eigen;

class ThetaEstimator {
public:
    ThetaEstimator();
    VectorXd e = VectorXd(2);
    VectorXd e_dot = VectorXd(2);
    VectorXd n = VectorXd(2);
    VectorXd x = VectorXd(5);
    VectorXd L2f_h = VectorXd(2);
    void resetPara();
    VectorXd computeThetaEst();
private:
    VectorXd theta_est = VectorXd(6);
    struct timespec last_time;
};

class L2f_hFunction {
public:
    L2f_hFunction();
    VectorXd q = VectorXd(3);
    VectorXd v = VectorXd(2);
    VectorXd L2f_h = VectorXd(2);
    VectorXd computeL2f_h();
    void resetPara();   
};

class NonelinearSFeedback {
public: 
    NonelinearSFeedback();
    double x0, y0, phi, vr, wr;
    VectorXd theta_est = VectorXd(6);
    VectorXd n = VectorXd(2);
    MatrixXd A = MatrixXd(2,2);
    MatrixXd B = MatrixXd(2,2);
    MatrixXd C = MatrixXd(2,2);
    MatrixXd D = MatrixXd(2,2);
    void setParameter();
    VectorXd computeUdk();
private:
    VectorXd x = VectorXd(2);
};

class StraightLOS
{
public:
    StraightLOS();
    ros::NodeHandle nh_;
    ros::Subscriber subWaypoint;
    ros::Publisher pubID;
    std::vector<double> alpha_P;
    std::vector<double> s;
    int pointId;
    unsigned long numPoints;
    double alongTrackError;
    double crossTrackError;
    double desiredHeading;
    double maxDelta;
    double minDelta;
    double radius;
    std::vector<float> waypoint_outdoor_x_;
    std::vector<float> waypoint_outdoor_y_;
    std::vector<double> velocities;   
    std::vector<double> accelerations; 
    std::vector<geometry_msgs::Point> waypoints;
    // float waypoint_outdoor_x[3] = {0, 42.25433, 87.84402};
    // float waypoint_outdoor_y[3] = {0, 26.23109, -48.04603};
    float waypoint_outdoor_x[5] = {26.86, 50.21339, 9.07133 , -38.74266, 0.17555};
    float waypoint_outdoor_y[5] = {47.887, 90.48877, 111.24359, 29.31716,  0.91594};

    void refCallback(const dk_adap_test::ref::ConstPtr& msg);
    void runLOS(const double &odomX, const double &odomY);
    void setupPubSub();
    void setLOS();
    // void setupLOS();
    void resetLOS();
};

#endif