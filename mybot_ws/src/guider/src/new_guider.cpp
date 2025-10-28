#include "new_guider.h"
#include "adap_pid.h"

newGuider::newGuider() {
    ros::NodeHandle nh;
    subOdom = nh.subscribe("odom_1", 10, &newGuider::onOdomCallBack, this);
    subHeading = nh.subscribe("odom_2", 10, &newGuider::onHeadingCallBack, this);
    lastControlUpdateTime = ros::Time::now();
}
newGuider::~newGuider()
{
    if (ros::isStarted())
    {
        ros::shutdown();
        ros::waitForShutdown();
    }
}

void newGuider::onOdomCallBack(const Odometry::ConstPtr &msg) {
    currX = msg->position.x;
    currY = msg->position.y;
}

void newGuider::onHeadingCallBack(const Odometry::ConstPtr &msg) {
    currHeading = msg->heading;
    ROS_INFO("currHeading %f",currHeading);
}



void newGuider::onControlLoop(const ros::TimerEvent& event) {
    double dt = (event.current_real - lastControlUpdateTime).toSec();
    int K1 = 120;
    int K2 = 120;
    pre_currX = currX;
    pre_currY = currY;
    pre_heading = currHeading;
    lastControlUpdateTime = event.current_real;
    ThetaEstimator thetaEs;
    thetaEs.e(0) = 12;
    
    thetaEs.computeThetaEstDot()
    thetaest = thetaEs.theta_est;
    theta += thetaest * dt;
}

int main(int argc, char **agrv)
{
    ros::init(argc, agrv, "nguider_node");
    newGuider nguide;
    ros::spin();
    return 0;
}
