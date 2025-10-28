#ifndef ADAP_PID_H
#define ADAP_PID_H

#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <Eigen/Dense>

using namespace Eigen;

class ThetaEstimator {
public:
    ThetaEstimator();

private:
    ros::Publisher theta_est_dot_pub;
    VectorXd e = VectorXd(2);
    VectorXd e_dot = VectorXd(2);
    VectorXd n = VectorXd(2);
    VectorXd x = VectorXd(5);
    VectorXd L2f_h = VectorXd(2);
    VectorXd theta_est = VectorXd(6);

    void resetPara();
    void computeThetaEstDot();
};

class L2f_hFunction {
public:
    L2f_hFunction();

private:
  ros::Publisher l2f_hpub;
  VectorXd q = VectorXd(3);
  VectorXd v = VectorXd(2);
  VectorXd L2f_h = VectorXd(2);

  void computeL2f_h();
  void resetPara();
};

class Derivative {
public:
    Derivative() {
        ros::NodeHandle nh;
    }
private:
    double dt;
    double pre;
    double cur;
    double output;
    void derivative();
};

// class Derivative_2 {
// public:
//     Derivative_2();
// private:
//     double dt;
//     double pre;
//     double cur;
//     double output;
//     void derivative_2();
// };

#endif