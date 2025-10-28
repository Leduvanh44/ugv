#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <Eigen/Dense>
#include "adap_pid.h"

using namespace Eigen;

ThetaEstimator::ThetaEstimator() {
    ros::NodeHandle nh;
    theta_est_dot_pub = nh.advertise<std_msgs::Float64MultiArray>("theta_est_dot_topic", 1000);
    resetPara();
}

void ThetaEstimator::resetPara() {
    e(0) = 0;
    e(1) = 0;
    e_dot(0) = 0;
    e_dot(1) = 0;
    n(0) = 0;
    n(1) = 0;
    theta_est(0) = 0;
    theta_est(1) = 0;
    theta_est(2) = 0;
    theta_est(3) = 0;
    theta_est(4) = 0;
    theta_est(5) = 0;
  }

void ThetaEstimator::computeThetaEstDot() {
      if (e.size() == 0 || e_dot.size() == 0 || n.size() == 0 || x.size() == 0 || L2f_h.size() == 0 || theta_est.size() == 0) {
          return;
      }

      double L = 0.1;
      VectorXd X(4);
      X << e(0), e_dot(0), e(1), e_dot(1);

      MatrixXd C(2, 4);
      C << 0.5, 1, 0, 0,
            0, 0, 1, 0.5;
      VectorXd E1 = C * X;

      double w11 = -x(3) * cos(x(2));
      double w12 = -pow(x(4), 2) * cos(x(2));
      double w13 = -x(3) * x(4) * L * sin(x(2));
      double w14 = x(4) * L * sin(x(2));
      double phi_1 = n(0) - L2f_h(0) - w11 * theta_est(0) - w12 * theta_est(1) - w13 * theta_est(2) - w14 * theta_est(3);

      double w21 = -x(3) * sin(x(2));
      double w22 = -pow(x(4), 2) * sin(x(2));
      double w23 = -x(3) * x(4) * L * cos(x(2));
      double w24 = x(4) * L * cos(x(2));
      double phi_2 = n(1) - L2f_h(1) - w21 * theta_est(0) - w22 * theta_est(1) - w23 * theta_est(2) - w24 * theta_est(3);

      double w15 = (phi_1 * pow(cos(x(2)), 2) + phi_2 * sin(x(2)) * cos(x(2))) / theta_est(4);
      double w16 = (phi_1 * pow(sin(x(2)), 2) - phi_2 * sin(x(2)) * cos(x(2))) / theta_est(5);
      double w25 = (phi_2 * pow(sin(x(2)), 2) + phi_1 * sin(x(2)) * cos(x(2))) / theta_est(4);
      double w26 = (phi_2 * pow(cos(x(2)), 2) - phi_1 * sin(x(2)) * cos(x(2))) / theta_est(5);

      MatrixXd W(2, 6);
      W << w11, w12, w13, w14, w15, w16,
            w21, w22, w23, w24, w25, w26;

      VectorXd A(6);
      A << 1, 1, 1, 1, 1, 1;
      A *= 0.1;
      MatrixXd T = A.asDiagonal();

      VectorXd theta_est_dot = T * W.transpose() * E1;

      std_msgs::Float64MultiArray theta_est_dot_msg;
      for (int i = 0; i < theta_est_dot.size(); ++i) {
          theta_est_dot_msg.data.push_back(theta_est_dot(i));
      }
      theta_est_dot_pub.publish(theta_est_dot_msg);
}

L2f_hFunction::L2f_hFunction() {
      ros::NodeHandle nh;
      ros::Publisher l2f_hpub = nh.advertise<std_msgs::Float64MultiArray>("L2f_h_topic", 1000);
      resetPara();
}

void L2f_hFunction::resetPara() {
  q << 0,0,0;
  v << 0,0;
}

void L2f_hFunction::computeL2f_h() {
    double L  = 0.1;
    MatrixXd Jh_q_dot(2, 3);
    Jh_q_dot << 0, 0, -v(1)*sin(q(3))-v(2)*L*cos(q(3)),
                0, 0, v(1)*cos(q(3))-v(2)*L*sin(q(3));
    MatrixXd S(3, 2);
    S <<  cos(q(3)), 0,
          sin(q(3)), 0,
          0, 1;
    L2f_h = Jh_q_dot*S*v;
    std_msgs::Float64MultiArray l2f_h_msg;
      for (int i = 0; i < L2f_h.size(); ++i) {
          l2f_h_msg.data.push_back(L2f_h(i));
      }
      l2f_hpub.publish(l2f_h_msg);
}


void Derivative::derivative() {
  output = (cur - pre)/dt;
}