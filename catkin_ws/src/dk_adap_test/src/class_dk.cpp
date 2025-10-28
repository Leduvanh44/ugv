#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>
#include <Eigen/Dense>
#include "class_dk.h"
#include <time.h>

using namespace Eigen;

ThetaEstimator::ThetaEstimator() {
    resetPara();
}

void ThetaEstimator::resetPara() {
      e(0) = 0;
      e(1) = 0;
      e_dot(0) = 0;
      e_dot(1) = 0;
      n(0) = 0;
      n(1) = 0;
      theta_est(0) = 1;
      theta_est(1) = 1;
      theta_est(2) = 1;
      theta_est(3) = 1;
      theta_est(4) = 1;
      theta_est(5) = 1;
      last_time.tv_sec = 0;
      last_time.tv_nsec = 0;
  }

VectorXd ThetaEstimator::computeThetaEst() {
      struct timespec current_time;
      clock_gettime(CLOCK_MONOTONIC, &current_time);
      double dt = (current_time.tv_sec - last_time.tv_sec) + (current_time.tv_nsec - last_time.tv_nsec) / 1e9;
      last_time = current_time;
      if (e.size() == 0 || e_dot.size() == 0 || n.size() == 0 || x.size() == 0 || L2f_h.size() == 0 || theta_est.size() == 0) {
          return theta_est;
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

      // std_msgs::Float64MultiArray theta_est_dot_msg;
      // for (int i = 0; i < theta_est_dot.size(); ++i) {
      //     theta_est_dot_msg.data.push_back(theta_est_dot(i));
      // }
      // theta_est_dot_pub.publish(theta_est_dot_msg);
      theta_est += theta_est_dot * 0.01;
      return theta_est;
}

L2f_hFunction::L2f_hFunction() {
      // ros::Publisher l2f_hpub = nh.advertise<std_msgs::Float64MultiArray>("L2f_h_topic", 1000);
      resetPara();
}

void L2f_hFunction::resetPara() {
  q << 0,0,0;
  v << 0,0;
}

VectorXd L2f_hFunction::computeL2f_h() {
      double L  = 0.1;
      MatrixXd Jh_q_dot(2, 3);
      Jh_q_dot << 0, 0, -v(0)*sin(q(2))-v(1)*L*cos(q(2)),
                  0, 0, v(0)*cos(q(2))-v(1)*L*sin(q(2));
      MatrixXd S(3, 2);
      S <<  cos(q(2)), 0,
            sin(q(2)), 0,
            0, 1;
      L2f_h = Jh_q_dot*S*v;
    return L2f_h;
//     std_msgs::Float64MultiArray l2f_h_msg;
//       for (int i = 0; i < L2f_h.size(); ++i) {
//           l2f_h_msg.data.push_back(L2f_h(i));
//       }
//       l2f_hpub.publish(l2f_h_msg);
}

NonelinearSFeedback::NonelinearSFeedback() {
      setParameter();
}
void NonelinearSFeedback::setParameter() {
      A << 0.9, 0,
            0, 0.9;
      B << 0.1, 0,
            0, 0.1;
      C << 1, 0,
            0, 1;
      D << 0, 0,
            0, 0;
      x << 0, 0;
}

VectorXd NonelinearSFeedback::computeUdk() {
      VectorXd q = VectorXd(3);
      VectorXd v = VectorXd(2);
      q << x0, y0, phi;
      v << vr, wr;
      double L = 0.1;

      MatrixXd Jh_q(2, 3);
      Jh_q << 1, 0, -L * sin(q(2)),
            0, 1, L * cos(q(2));

      MatrixXd Jh_q_dot(2, 3);
      Jh_q_dot << 0, 0, -v(0) * sin(q(2)) - v(1) * L * cos(q(2)),
                  0, 0, v(0) * cos(q(2)) - v(1) * L * sin(q(2));

      MatrixXd S(3, 2);
      S << cos(q(2)), 0,
            sin(q(2)), 0,
            0, 1;

      MatrixXd G(2, 2);
      G << theta_est(4), theta_est(4),
            theta_est(5), -theta_est(5);

      MatrixXd D = Jh_q * S * G;

      VectorXd Q(2);
      Q << -theta_est(0) * v(0) - theta_est(1) * v(1) * v(1),
            theta_est(2) * v(1) * v(0) - theta_est(3) * v(1);

      VectorXd Lq_Lf_h = Jh_q * S * Q;

      VectorXd ua = D.inverse() * (n - Jh_q_dot * S * v - Lq_Lf_h);

      VectorXd xdot(2);
      xdot(0) = A(0,0) * x(0) + A(0,1) * x(1) + B(0,0) * ua(0) + B(0,1) * ua(1);
      xdot(1) = A(1,0) * x(0) + A(1,1) * x(1) + B(1,0) * ua(0) + B(1,1) * ua(1);

      x = x + xdot * 0.1;

        VectorXd y(2);
        y(0) = C(0,0) * x(0) + C(0,1) * x(1) + D(0,0) * ua(0) + D(0,1) * ua(1);
        y(1) = C(1,0) * x(0) + C(1,1) * x(1) + D(1,0) * ua(0) + D(1,1) * ua(1);
      return y;
}

StraightLOS::StraightLOS() {
      maxDelta = 2.0;  
      minDelta = 0.5; 
      radius = 0.5; 
      pointId = 0;   
}

void StraightLOS::setupPubSub(){
      subWaypoint = nh_.subscribe("/points", 10, &StraightLOS::refCallback, this);
      pubID = nh_.advertise<std_msgs::Int32>("/current_point_id", 10);
}

void StraightLOS::setLOS() {
    alpha_P.clear();
    s.clear();

    if (numPoints > 1) {
        alpha_P.resize(numPoints - 1);
        s.resize(numPoints - 1);

        for (unsigned i = 0; i < numPoints - 1; i++) {
            double diff_x = waypoints[i + 1].x - waypoints[i].x;
            double diff_y = waypoints[i + 1].y - waypoints[i].y;
            alpha_P[i] = atan2(diff_y, diff_x);
            s[i] = diff_x * cos(alpha_P[i]) + diff_y * sin(alpha_P[i]);
        }
    }
}

void StraightLOS::runLOS(const double &odomX, const double &odomY) {
      std_msgs::Int32 id;
      id.data = pointId;
      ROS_INFO_STREAM("Point: " << pointId);
      pubID.publish(id);
      if (waypoints.size() == 0) {
            ROS_INFO("adg");
            return;
      }
    double c_alpha = cos(alpha_P[pointId]);
    double s_alpha = sin(alpha_P[pointId]);
    double diff_x = odomX - waypoints[pointId].x;
    double diff_y = odomY - waypoints[pointId].y;

    // Calculate the along-track and cross-track errors
    alongTrackError = diff_x * c_alpha + diff_y * s_alpha;
    crossTrackError = -diff_x * s_alpha + diff_y * c_alpha;

    // Find desired heading
    double delta = (maxDelta - minDelta) * exp(-0.3 * (crossTrackError * crossTrackError)) + minDelta;
    desiredHeading = alpha_P[pointId] + atan2(-crossTrackError, delta);
    desiredHeading = atan2(sin(desiredHeading), cos(desiredHeading)); // Normalize angle
    // Update pointId if necessary
    if (pointId < numPoints - 2) {
        if (fabs(s[pointId] - alongTrackError) < radius)
            pointId++;
    } else {
        if (fabs(s[pointId] - alongTrackError) < 1.0)
            pointId++;
    }
      return pointId < numPoints - 1;
//       return false;
}

void StraightLOS::resetLOS()
{
  waypoints.clear();
  pointId = 0;
}

void StraightLOS::refCallback(const dk_adap_test::ref::ConstPtr& msg) {
    waypoints.clear();
    waypoints = msg->points;
    numPoints = waypoints.size();
//     ROS_INFO_STREAM("numPoints; " << numPoints);
    velocities.clear();
    accelerations.clear();
      if (numPoints > 1) {
            alpha_P.resize(numPoints - 1);
            s.resize(numPoints - 1);

            for (unsigned i = 0; i < numPoints - 1; i++) {
                  double diff_x = waypoints[i + 1].x - waypoints[i].x;
                  double diff_y = waypoints[i + 1].y - waypoints[i].y;
                  alpha_P[i] = atan2(diff_y, diff_x);
                  s[i] = diff_x * cos(alpha_P[i]) + diff_y * sin(alpha_P[i]);
            }
      }
//     if (numPoints > 1) {
//         velocities.resize(numPoints - 1);
//         accelerations.resize(numPoints - 2);

//         for (unsigned i = 0; i < numPoints - 1; i++) {
//             double diff_x = waypoints[i + 1].x - waypoints[i].x;
//             double diff_y = waypoints[i + 1].y - waypoints[i].y;
//             velocities[i] = sqrt(diff_x * diff_x + diff_y * diff_y);
//         }

//         for (unsigned i = 0; i < numPoints - 2; i++) {
//             double diff_v = velocities[i + 1] - velocities[i];
//             accelerations[i] = diff_v;
//         }
//     }

//     setLOS();
}