#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <QByteArray>
#include <QList>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sensor_msgs/NavSatFix.h>
#include <utils/Odometry.h>
#include <utils/DiffVel.h>
#include <utils/Radius.h>
#include <cmath>

double lat, lon, posx, posy;


void onCallbackGPS(const utils::Odometry::ConstPtr& msg) {
    lat = msg->latitude;
    lon = mag->longitude;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "radius_node");
    ros::NodeHandle nh;
    ros::NodeHandle private_nh("~");
    ros::Publisher pubRadius = nh.advertise<utils::Radius>("radius", 10);
    ros::Subscriber sub_odom = nh.subscribe("/odom_1", 10, onCallbackGPS);

    while (ros::ok())
    {

    }
    

}