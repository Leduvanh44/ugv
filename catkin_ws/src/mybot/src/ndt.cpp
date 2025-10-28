#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/registration/ndt.h>
#include <pcl_ros/point_cloud.h>

ros::Publisher combined_pub;
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZRGB>);

void mergePointClouds(const ros::TimerEvent&)
{
    if (!cloud_in->empty() && !cloud_out->empty())
    {
        pcl::NormalDistributionsTransform<pcl::PointXYZRGB, pcl::PointXYZRGB> ndt;
        ndt.setInputSource(cloud_in);
        ndt.setInputTarget(cloud_out);
        
        pcl::PointCloud<pcl::PointXYZRGB> Final;
        // Optional: Set parameters for NDT
        ndt.setTransformationEpsilon(0.01); // Tolerance for convergence
        ndt.setMaximumIterations(50);         // Maximum number of iterations

        ndt.align(Final);

        if (ndt.hasConverged()) {
            ROS_INFO("NDT has converged, score: %f", ndt.getFitnessScore());
            // Xuất bản đám mây điểm sau khi ghép
            combined_pub.publish(Final.makeShared());
        } else {
            ROS_WARN("NDT did not converge.");
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
    ros::init(argc, argv, "ndt_merger");
    ros::NodeHandle nh;

    ros::Subscriber lidar_sub = nh.subscribe("laser_scan", 10, lidarCallback);
    ros::Subscriber cam_sub = nh.subscribe("laser_scanf", 10, camCallback);
    combined_pub = nh.advertise<pcl::PointCloud<pcl::PointXYZRGB>>("ndt_cloud", 10);

    ros::Timer timer = nh.createTimer(ros::Duration(0.1), mergePointClouds);

    ros::spin();
    return 0;
}