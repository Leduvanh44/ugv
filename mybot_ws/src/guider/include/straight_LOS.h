#ifndef  STRAIGHT_LOS_H
#define  STRAIGHT_LOS_H

#include <base_LOS.h>
#include <utils/pointID.h>
#include <ros/ros.h>
#include <utils/WaypointList.h>
using namespace utils;


class StraightLOS : public BaseLOS
{
public:
    StraightLOS();
    ~StraightLOS();

    ros::Publisher pubID;
    ros::Subscriber subWaypoint;
    std::vector<double> alpha_P;
    std::vector<double> s;
    unsigned pointId;
    unsigned long numPoints;
    std::vector<float> waypoint_outdoor_x_;
    std::vector<float> waypoint_outdoor_y_;
    // float waypoint_outdoor_x[3] = {0, 42.25433, 87.84402};
    // float waypoint_outdoor_y[3] = {0, 26.23109, -48.04603};
    float waypoint_outdoor_x[5] = {26.86, 50.21339, 9.07133 , -38.74266, 0.17555};
    float waypoint_outdoor_y[5] = {47.887, 90.48877, 111.24359, 29.31716,  0.91594};

    void setupLOS();
    void setLOS();
    void resetLOS();
    bool runLOS(const double& odomX,const double& odomY);
};
#endif // STRAIGHT_LOS_H
