#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/registration/gicp.h> // Thêm header cho GICP
#include <pcl_ros/point_cloud.h>

ros::Publisher combined_pub;
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZRGB>);

void mergePointClouds(const ros::TimerEvent&)
{
    if (!cloud_in->empty() && !cloud_out->empty())
    {
        pcl::GeneralizedIterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> gicp; // Khởi tạo GICP
        gicp.setInputSource(cloud_in);
        gicp.setInputTarget(cloud_out);
  
        pcl::PointCloud<pcl::PointXYZRGB> Final;
        gicp.align(Final);

        if (gicp.hasConverged()) {
            ROS_INFO("GICP has converged, score: %f", gicp.getFitnessScore());
            // Xuất bản đám mây điểm sau khi ghép
            combined_pub.publish(Final.makeShared());
        } else {
            ROS_WARN("GICP did not converge.");
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
    ros::init(argc, argv, "gicp_merge");
    ros::NodeHandle nh;

    ros::Subscriber lidar_sub = nh.subscribe("laser_scan", 10, lidarCallback);
    ros::Subscriber cam_sub = nh.subscribe("laser_scanf", 10, camCallback);
    combined_pub = nh.advertise<pcl::PointCloud<pcl::PointXYZRGB>>("gicp_cloud", 10);

    ros::Timer timer = nh.createTimer(ros::Duration(0.1), mergePointClouds);

    ros::spin();
    return 0;
}
