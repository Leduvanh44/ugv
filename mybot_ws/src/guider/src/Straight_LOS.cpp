#include "straight_LOS.h"

StraightLOS::StraightLOS() {
  ros::NodeHandle nh;
  pubID = nh.advertise<pointID>("/pointID", 10);
  // subWaypoint = nh.subscribe<WaypointList>("/mission/item_list", 10);
}
StraightLOS::~StraightLOS(){
  if(ros::isStarted()){
    ros::shutdown();
    ros::waitForShutdown();
  }
}

void StraightLOS::setLOS()
{
  numPoints = waypoints.size();
  for (int i = 0 ; i < numPoints ; i++){
  }
  if (numPoints > 1)
  {
    alpha_P.resize(numPoints - 1);
    s.resize(numPoints - 1);
    for (unsigned i = 0; i < numPoints - 1; i++)
    {
      double diff_x = waypoints[i + 1].x - waypoints[i].x;
      double diff_y = waypoints[i + 1].y - waypoints[i].y;
      alpha_P[i] = atan2(diff_y, diff_x);
      s[i] = diff_x * cos(alpha_P[i]) + diff_y * sin(alpha_P[i]);
    }
  }
}

void StraightLOS::setupLOS()
{
  int size = sizeof(waypoint_outdoor_x)/sizeof(waypoint_outdoor_x[0]);
  for (int i = 0; i < size; i++)
  {
    waypoints.push_back(BaseLOS::Point(waypoint_outdoor_x[i], waypoint_outdoor_y[i]));
  }
  numPoints = waypoints.size();
  if (numPoints > 1)
  {
    alpha_P.resize(numPoints - 1);
    s.resize(numPoints - 1);
    for (unsigned i = 0; i < numPoints - 1; i++)
    {
      double diff_x = waypoints[i + 1].x - waypoints[i].x;
      double diff_y = waypoints[i + 1].y - waypoints[i].y;
      alpha_P[i] = atan2(diff_y, diff_x);
      s[i] = diff_x * cos(alpha_P[i]) + diff_y * sin(alpha_P[i]);
    }
  }
}

void StraightLOS::resetLOS()
{
  waypoints.clear();
  pointId = 0;
}

bool StraightLOS::runLOS(const double &odomX, const double &odomY)
{
  double c_alpha = cos(alpha_P[pointId]);
  double s_alpha = sin(alpha_P[pointId]);
  double diff_x = odomX - waypoints[pointId].x;
  double diff_y = odomY - waypoints[pointId].y;

  \
  // Calculate the along-track and cross-track errors
  alongTrackError = diff_x * c_alpha + diff_y * s_alpha;
  crossTrackError = -diff_x * s_alpha + diff_y * c_alpha;

  // Find desired heading
  double delta = (maxDelta - minDelta) * exp(-0.3 * (crossTrackError * crossTrackError)) + minDelta;
  desiredHeading = alpha_P[pointId] + atan2(-crossTrackError, delta);
  ROS_INFO("alpha %f",alpha_P[pointId]);
  desiredHeading = atan2(sin(desiredHeading), cos(desiredHeading)); // Lưu ý coi chính xác chưa
  ROS_INFO("desired_heading %f",desiredHeading);

  // if(desiredHeading > M_PI)
  //   desiredHeading = desiredHeading - 2*M_PI;
  // else if (desiredHeading < -M_PI)
  //   desiredHeading = desiredHeading + 2*M_PI;    
  // Head toward the next waypoint. For the nearly final point, discard point-switching scheme
  if (pointId < numPoints - 2)
  {
    if (fabs(s[pointId] - alongTrackError) < radius)
      pointId++;
  }
  else
  {
    if (fabs(s[pointId] - alongTrackError) < 1.0)
      pointId++;
  }
  pointID id;
  id.pointID = pointId;
  pubID.publish(id);

  // Terminate LOS if the final point has been reached
  return pointId < numPoints - 1;
}

