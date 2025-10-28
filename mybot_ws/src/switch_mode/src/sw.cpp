#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include "std_msgs/Float32.h"
#include "utils/Odometry.h"
#include <utils/WaypointList.h>
#include <utils/mode_indoor.h>
#include <utils/Complete.h>
#include <utils/goal_indoor.h>

using namespace std;
float x_C1 = 103;
float y_C1 = 103;
float x_B6 = 104;
float y_B6 = 104;
float x_A1 = 105;
float y_A1 = 105;
double lat_end_waypoint_c1 = 10;
double lat_end_waypoint_b6 = 10;
double lat_end_waypoint_a1 = 10;
double lon_end_waypoint_c1 = 106;
double lon_end_waypoint_b6 = 106;
double lon_end_waypoint_a1 = 106;

uint8_t mode = 0;
float x_cur = 0;
float y_cur = 0;
double lat_end_waypoint = 0;
double lon_end_waypoint = 0;


void CallbackOdometry(const utils::Odometry &msg) {
    x_cur = od.position.x;
    y_cur = od.position.y;
}

void CallbackWaypoint(const utils::WaypointList &waypoint){
    lat_end_waypoint = waypoint.waypoints.back().x_lat;
    lon_end_waypoint = waypoint.waypoints.back().y_long;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "switch_node");

    ros::NodeHandle n;
	ros::Subscriber model = n.subscribe("/odom_1", 1, CallbackOdometry);
    ros::Publisher pub_mode = n.advertise<utils::mode_indoor>("/mode_indoor", 50);
    ros::Publishe pub_goal_indoor_set = n.advertise<utils::goal_indoor>("/goal_indoor", 10);
    ros::Subscriber waypoint = n.subscribe("/mission/item_list", 1, CallbackWaypoint);
    ros::Rate r(20.0);
    
    utils::
    while (n.ok())
    {
        ros::spinOnce();
        if (lat_end_waypoint == lat_end_waypoint_c1 && lon_end_waypoint == lat_end_waypoint_c1) {
            ROS_INFO_STREAM("C1 my friend");
            if (abs(x_cur - x_C1) < 5 && abs(y_cur - y_C1) < 5) {
                mode = 1;

            }
        } 
        else if (lat_end_waypoint == lat_end_waypoint_a1 && lon_end_waypoint == lat_end_waypoint_a1){
            ROS_INFO_STREAM("A2 my friend");
            if (abs(x_cur - x_A1) < 5 && abs(y_cur - y_Ax_A1) < 5) {
                mode = 1;

            }        
        }

        else if (lat_end_waypoint == lat_end_waypoint_b6 && lon_end_waypoint == lat_end_waypoint_b6) {
            ROS_INFO_STREAM("B6 my friend");
            if (abs(x_cur - x_B6) < 5 && abs(y_cur - y_Bx_B6) < 5) {
                mode = 1;

            }
        } 
        else {
            ROS_INFO_STREAM("No indoor");
            mode = 1;

        }   
    }
    _mode.mode_indoor = mode ;
    pub_mode.publish(_mode);
}