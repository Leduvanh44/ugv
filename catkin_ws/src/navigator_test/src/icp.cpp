// int main ()
// {
//   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in (new pcl::PointCloud<pcl::PointXYZ>(5,1));
//   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>);

//   // Fill in the CloudIn data
//   for (auto& point : *cloud_in)
//   {
//     point.x = 1024 * rand() / (RAND_MAX + 1.0f);
//     point.y = 1024 * rand() / (RAND_MAX + 1.0f);
//     point.z = 1024 * rand() / (RAND_MAX + 1.0f);
//   }
  
//   std::cout << "Saved " << cloud_in->size () << " data points to input:" << std::endl;
      
//   for (auto& point : *cloud_in)
//     std::cout << point << std::endl;
      
//   *cloud_out = *cloud_in;
  
//   std::cout << "size:" << cloud_out->size() << std::endl;
//   for (auto& point : *cloud_out)
//     point.x += 0.7f;

//   std::cout << "Transformed " << cloud_in->size () << " data points:" << std::endl;
      
//   for (auto& point : *cloud_out)
//     std::cout << point << std::endl;

//   pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
//   icp.setInputSource(cloud_in);
//   icp.setInputTarget(cloud_out);
  
//   pcl::PointCloud<pcl::PointXYZ> Final;
//   icp.align(Final);

//   std::cout << "ICP has " << (icp.hasConverged()?"converged":"not converged") << ", score: " <<
//   icp.getFitnessScore() << std::endl;
//   std::cout << icp.getFinalTransformation() << std::endl;

//  return (0);
// }

#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl_ros/point_cloud.h>

ros::Publisher combined_pub;
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZRGB>);

void mergePointClouds(const ros::TimerEvent&)
{
    if (!cloud_in->empty() && !cloud_out->empty())
    {
        pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> icp;
        icp.setInputSource(cloud_in);
        icp.setInputTarget(cloud_out);
  
        pcl::PointCloud<pcl::PointXYZRGB> Final;
        icp.align(Final);

        if (icp.hasConverged()) {
            ROS_INFO("ICP has converged, score: %f", icp.getFitnessScore());
            // Xuất bản đám mây điểm sau khi ghép
            combined_pub.publish(Final.makeShared());
        } else {
            ROS_WARN("ICP did not converge.");
        }
    }
}

void lidarCallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& lidar_cloud)
{
    *cloud_in = *lidar_cloud;
}

void camCallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& cam_cloud)
{
    *cloud_out = *cam_cloud;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "icp_merge");
    ros::NodeHandle nh;

    ros::Subscriber lidar_sub = nh.subscribe("laser_scan", 10, lidarCallback);
    ros::Subscriber cam_sub = nh.subscribe("laser_scanf", 10, camCallback);
    combined_pub = nh.advertise<pcl::PointCloud<pcl::PointXYZRGB>>("icp_cloud", 10);

    ros::Timer timer = nh.createTimer(ros::Duration(0.1), mergePointClouds);

    ros::spin();
    return 0;
}

