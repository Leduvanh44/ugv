
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include "std_msgs/Float32.h"
#include "utils/Odometry.h"
#include <utils/WaypointList.h>
#include <utils/mode_indoor.h>
#include <utils/Complete.h>
#include <utils/goal_indoor.h>
// #include <utils/goal_indoor.h>

using namespace std;

string set_goal_indoor;
uint8_t mode = 0;

float x_current ;
float y_current ;

float x_A = -105.913137418;
float y_A =  -16.3348325537;

float x_B =  -108.752610599;
float y_B =  -25.1239448417;

float lat_end_waypoint_set = 107746128.000000000 ;
float lon_end_waypoint_set = 1066596032.000000000;

float lat_end_waypoint;
float lon_end_waypoint;

bool complete ;
bool complete_indoor ;
bool set_complete_indoor;

float goal_end_set;

void CallbackWaypoint(const utils::WaypointList &waypoint){
    lat_end_waypoint = waypoint.waypoints.back().x_lat;
    lon_end_waypoint = waypoint.waypoints.back().y_long;
}

void CallbackOdometry(const utils::Odometry &od)
{
    x_current = od.position.x ;
    y_current = od.position.y ;

}

void CallbackComplete(const utils::Complete &com){
    complete = com.complete ;
    complete_indoor = com.complete_indoor ;

}

void Switch_mode(){

    if(lat_end_waypoint == lat_end_waypoint_set && lon_end_waypoint == lon_end_waypoint_set){
        ROS_INFO_STREAM("true waypoint");
        if( x_current < x_A && x_current > x_B){
            if(y_current < y_A && y_current > y_B){
                ROS_INFO_STREAM("true xy");
                if( complete_indoor == true ){
                ROS_INFO_STREAM("switch_indoor!!");
                sleep(10);
                system("roslaunch cartographer_ros test_local.launch ");
                }
            }
        }
    }
}

void CallbackGoalindoor(const utils::goal_indoor & goal){
    goal_end_set = goal.way_x_2 ;
}

//..................................................................................
int main(int argc, char** argv){
  ros::init(argc, argv, "switch_mode_node");

  ros::NodeHandle n;
 
	ros::Subscriber model = n.subscribe("/odom_1", 1, CallbackOdometry);
    ros::Subscriber waypoint = n.subscribe("/mission/item_list", 1, CallbackWaypoint);
    ros::Publisher pub_mode = n.advertise<utils::mode_indoor>("/mode_indoor", 50);
    ros::Subscriber sub_complete = n.subscribe("/Complete", 1, CallbackComplete);
    ros::Subscriber way_in = n.subscribe("/goal_indoor", 1, CallbackGoalindoor);

  ros::Rate r(20.0);
  while(n.ok()){
    Switch_mode();
    ros::spinOnce();      
        if(lat_end_waypoint == lat_end_waypoint_set && lon_end_waypoint == lon_end_waypoint_set){
            if( x_current < x_A && x_current > x_B){
                if(y_current < y_A && y_current > y_B){
                    if( complete_indoor == true && goal_end_set != 0.3){   
                        mode = 1.0; 
                        set_complete_indoor = true;
                    }
                }
            }
    }
        else {
            mode = 0.0 ;
            set_complete_indoor = false;
        }
        utils::mode_indoor _mode;  
        _mode.mode_indoor = mode ;
        _mode.set_complete_indoor = set_complete_indoor ;
        pub_mode.publish(_mode);


    r.sleep();
  }
}
