#include <outdoor.h>

void CallbackCurrPosition(const utils::Odometry &pos){
  CurrX_outdoor = pos.position.x;
  CurrY_outdoor = pos.position.y ;
}

void CallbackCurrOdom(const utils::Odometry &odom){
    double yaw = odom.YPY.z;
    CurrOrient_outdoor = abs(yaw*180/M_PI);
    ROS_INFO_STREAM("Orient_z = " << CurrOrient_outdoor);
}

void CallrangeLaser(const sensor_msgs::LaserScan &laser){
    min_front = 30;
    min_front_left =  30;
    min_front_right =  30;

  for (int  i = 462 ; i < 616 ; i++)
  {
    range_front[i] = laser.ranges[i];
        if ( min_front > range_front[i])
        {
             min_front = range_front[i];
             min_front_element = i ;             
        }
  }

  for (int j = 617 ; j < 770 ; j++)
  {
    range_front_left[j] = laser.ranges[j];
        if( min_front_left > range_front_left[j])
        {
              min_front_left = range_front_left[j];
              min_front_left_element = j;
        }
  
  }
  for (int k = 308 ; k < 461 ; k++)
  {
    range_front_right[k] = laser.ranges[k];
        if( min_front_right > range_front_right[k])
        {
              min_front_right = range_front_right[k];
              min_front_right_element = k ;
        }
  }

  if(min_front < min_front_left && min_front < min_front_right && min_front <= 2*hight){
      location_obstacle = 1 ;
      _min = min_front;
      _trueObs = true;
  }
  else if(min_front_left < min_front && min_front_left < min_front_right && min_front_left <= 2*hight){
      location_obstacle = 2 ;
      _min = min_front_left ;
      _trueObs = true;
  }
  else if (min_front_right < min_front && min_front_right < min_front_left && min_front_right <= 2*hight){ 
      location_obstacle = 3 ;
      _min = min_front_right ;
      _trueObs = true;
  }
  else{
      _trueObs = false ;
      }

  if(location_obstacle == 1 ){
      angle_min_front = (abs(min_front_element-540)*0.25)*M_PI/180;
      angle_add = abs(atan(1.5*width/min_front));
      angle_avoid = angle_min_front + angle_add;
      distance_avoid = sqrt(pow(min_front,2)+ pow(1.5*width,2));
      if(min_front_element > 540){
      ROS_INFO("Obstacle in front_left -> Avoid in Right");
      angle_new_waypoint = abs(90-CurrOrient_outdoor-angle_avoid);
        x_add = -distance_avoid*cos(angle_avoid);
        y_add = distance_avoid*sin(angle_avoid); 
      }
      if(min_front_element < 540){
      angle_new_waypoint = abs(CurrOrient_outdoor-angle_avoid);
      ROS_INFO("Obstacle in front_right -> Avoid in Left");
        x_add = distance_avoid*cos(angle_avoid);
        y_add = distance_avoid*sin(angle_avoid);
      }
  }
  else if (location_obstacle == 2 ){
      ROS_INFO("Obstacle in left -> Avoid in right");
      angle_min_front_left = (abs(min_front_left_element-540)*0.25)*M_PI/180;
      angle_add = abs(atan(1.5*width/min_front_left));
      angle_avoid = abs(angle_add - angle_min_front_left) ;
      distance_avoid = sqrt(pow(min_front_left,2)+ pow(1.5*width,2));
      angle_new_waypoint = abs(90-CurrOrient_outdoor-angle_avoid);
      x_add = -distance_avoid*cos(angle_avoid);
      y_add = distance_avoid*sin(angle_avoid); 
     
  }
  else if (location_obstacle == 3){  
      ROS_INFO("Obstacle in right -> Avoid in Left");
      angle_min_front_right = (abs(min_front_right_element-540)*0.25)*M_PI/180;
      angle_add = abs(atan(1.5*width/min_front_right));
      angle_avoid = abs(angle_add - angle_min_front_right);
      distance_avoid = sqrt(pow(min_front_right,2)+ pow(1.5*width,2));
      angle_new_waypoint = abs(CurrOrient_outdoor-angle_avoid);
      x_add = distance_avoid*cos(angle_avoid);
      y_add = distance_avoid*sin(angle_avoid); 
      }


    CurrX = CurrX_outdoor;
    CurrX = CurrY_outdoor;
    
    new_waypointX_outdoor = CurrX + x_add ;
    new_waypointY_outdoor = CurrY + y_add ;
     ROS_INFO("%.1f %.1f\n " ,new_waypointX_outdoor , new_waypointY_outdoor);    
}

//..................................................................................
int main(int argc, char** argv){
    ros::init(argc, argv, "obstacle_node");

    ros::NodeHandle n;
    ros::Subscriber scan = n.subscribe("/horizontal_laser_2d", 1, CallrangeLaser);
    ros::Subscriber sub_pos = n.subscribe("/odom_1", 1, CallbackCurrPosition);
    ros::Subscriber sub_odom = n.subscribe("/odom_2", 1, CallbackCurrOdom);
    ros::Publisher pub_pos_avoid =n.advertise<utils::Position_avoid_obstacles>("/position_avoid", 50);

    ros::Rate r(20.0);
    while(n.ok()){
        utils::Position_avoid_obstacles _pose ;
        _pose.position_avoid_x = new_waypointX_outdoor ;
        _pose.position_avoid_y = - new_waypointY_outdoor ;
        _pose.obstacles = _trueObs ;

        pub_pos_avoid.publish(_pose);

        ros::spinOnce();   
        r.sleep();
    }
    return 0 ;
}


