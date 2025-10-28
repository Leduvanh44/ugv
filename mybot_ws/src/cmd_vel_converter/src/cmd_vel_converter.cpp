#include "cmd_vel_converter.h"

CmdVelConverter::CmdVelConverter()
{
  ros::NodeHandle nh;
  pubDiffVellSim = nh.advertise<KeyboardCommand>("diff_motor/keyboard_vel", 50);
  pubDiffVel = nh.advertise<DiffVel>("diff_motor/vel", 10);
  subYaw = nh.subscribe("/imu", 100, &CmdVelConverter::subIMUCallback, this);
  subCmdVel = nh.subscribe("/cmd_vel", 100, &CmdVelConverter::subCmdVelCallback, this);

  cur_time = ros::Time::now();
  last_time = cur_time;
}

CmdVelConverter::~CmdVelConverter()
{
  if (ros::isStarted())
  {
    ros::shutdown();
    ros::waitForShutdown();
  }
}

void CmdVelConverter::subIMUCallback(const Imu::ConstPtr &imu)
{
  quat.w = imu->orientation.w;
  quat.x = imu->orientation.x;
  quat.y = imu->orientation.y;
  quat.z = imu->orientation.z;

  double siny_cosp = 2 * (quat.w * quat.z + quat.x * quat.y);
  double cosy_cosp = 1 - 2 * (quat.y * quat.y + quat.z * quat.z);
  Yaw = atan2(siny_cosp, cosy_cosp);
}

void CmdVelConverter::subCmdVelCallback(const Twist::ConstPtr &CmdVel)
{
  twist.linear = CmdVel->linear;
  twist.angular.z = CmdVel->angular.z;
  cur_time = ros::Time::now();
  dt = (cur_time - last_time).toSec();
  last_time = cur_time;

  double V = twist.linear.x;
  double omega = twist.angular.z;

  double S = 2 * V / WHEEL_DIAMETER;
  double D = omega * WHEEL_DISTANCE / WHEEL_DIAMETER;

  av.v_left = (S - D) / 2;
  av.v_right = (S + D) / 2;

  velocsim.header.stamp = ros::Time::now();
  velocsim.mode = 1.0;

  velocsim.left_vel = av.v_left;
  velocsim.right_vel = av.v_right;

  pubDiffVellSim.publish(velocsim);

  veloc.header.stamp = ros::Time::now();

  veloc.left_vel = av.v_left;
  veloc.right_vel = av.v_right;
  pubDiffVel.publish(veloc);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cmd_vel_converter");
  CmdVelConverter cmd_vel_converter;
  ros::spin();
}
