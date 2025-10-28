#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/registration/ndt.h>
#include <pcl/registration/icp.h>
#include <pcl/registration/gicp.h>
#include <pcl_ros/point_cloud.h>
#include <std_msgs/Float32MultiArray.h>
#include <pcl/kdtree/kdtree.h>
#include <cmath> // Thêm thư viện này để sử dụng sqrt và pow

ros::Publisher quality_pub;
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_original(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_ndt(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_icp(new pcl::PointCloud<pcl::PointXYZRGB>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_gicp(new pcl::PointCloud<pcl::PointXYZRGB>);

void originalCallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& original_cloud)
{
    *cloud_original = *original_cloud;
    // ROS_INFO("scan");
}

void ndtCallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& ndt_cloud)
{
    *cloud_ndt = *ndt_cloud;
    // ROS_INFO("ndt");
}

void icpCallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& icp_cloud)
{
    *cloud_icp = *icp_cloud;
    // ROS_INFO("icp");
}

void gicpCallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& gicp_cloud)
{
    *cloud_gicp = *gicp_cloud;
    // ROS_INFO("gicp");
}

double euclideanDistance(const pcl::PointXYZRGB& a, const pcl::PointXYZRGB& b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2) + std::pow(a.z - b.z, 2));
}

double computeOverlap(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& cloudA, 
                      const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& cloudB) 
{
    pcl::KdTree<pcl::PointXYZRGB>::Ptr kdtree(new pcl::KdTreeFLANN<pcl::PointXYZRGB>());
    kdtree->setInputCloud(cloudB);
    
    int count = 0;

    for (const auto& point : cloudA->points) {
        std::vector<int> pointIdx;
        std::vector<float> pointSqDist;

        if (kdtree->nearestKSearch(point, 1, pointIdx, pointSqDist) > 0) {
            if (pointSqDist[0] < 0.01) { // Tolerance cho độ chồng chéo
                count++;
            }
        }
    }

    return static_cast<double>(count) / cloudA->size();
}

double computeMeanDeviation(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& cloudA, 
                             const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& cloudB)
{
    double total_deviation = 0.0;
    size_t count = 0;

    for (size_t i = 0; i < std::min(cloudA->size(), cloudB->size()); ++i) {
        double distance = euclideanDistance(cloudA->points[i], cloudB->points[i]);
        total_deviation += distance;
        count++;
    }

    return count > 0 ? total_deviation / count : 0.0; // Trả về độ sai lệch trung bình
}

void evaluatePointClouds(const ros::TimerEvent&)
{
    if (!cloud_original->empty() && !cloud_ndt->empty() && !cloud_icp->empty() && !cloud_gicp->empty())
    {
        double ndt_overlap = computeOverlap(cloud_original, cloud_ndt);
        double icp_overlap = computeOverlap(cloud_original, cloud_icp);
        double gicp_overlap = computeOverlap(cloud_original, cloud_gicp);

        double ndt_deviation = computeMeanDeviation(cloud_original, cloud_ndt);
        double icp_deviation = computeMeanDeviation(cloud_original, cloud_icp);
        double gicp_deviation = computeMeanDeviation(cloud_original, cloud_gicp);

        std_msgs::Float32MultiArray quality_metrics;
        quality_metrics.data.push_back(ndt_overlap);
        quality_metrics.data.push_back(icp_overlap);
        quality_metrics.data.push_back(gicp_overlap);
        quality_metrics.data.push_back(ndt_deviation);
        quality_metrics.data.push_back(icp_deviation);
        quality_metrics.data.push_back(gicp_deviation);

        quality_pub.publish(quality_metrics);

        ROS_INFO("Overlap with Original Cloud:");
        ROS_INFO("NDT vs Original: %f", ndt_overlap);
        ROS_INFO("ICP vs Original: %f", icp_overlap);
        ROS_INFO("GICP vs Original: %f", gicp_overlap);

        ROS_INFO("Mean Deviation from Original Cloud:");
        ROS_INFO("NDT Deviation: %f", ndt_deviation);
        ROS_INFO("ICP Deviation: %f", icp_deviation);
        ROS_INFO("GICP Deviation: %f", gicp_deviation);
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pointcloud_quality");
    ros::NodeHandle nh;

    ros::Subscriber original_sub = nh.subscribe("/laser_scan", 10, originalCallback);
    ros::Subscriber ndt_sub = nh.subscribe("/ndt_cloud", 10, ndtCallback);
    ros::Subscriber icp_sub = nh.subscribe("/icp_cloud", 10, icpCallback);
    ros::Subscriber gicp_sub = nh.subscribe("/gicp_cloud", 10, gicpCallback);

    quality_pub = nh.advertise<std_msgs::Float32MultiArray>("quality_metrics", 10);

    ros::Timer timer = nh.createTimer(ros::Duration(0.1), evaluatePointClouds);

    ros::spin();
    return 0;
}
