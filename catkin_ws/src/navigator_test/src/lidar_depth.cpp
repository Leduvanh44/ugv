#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/LaserScan.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/conversions.h>
#include <pcl_ros/transforms.h>
#include <tf/transform_listener.h>
#include <pcl/filters/voxel_grid.h>
#include <octomap/octomap.h>
#include <octomap/ColorOcTree.h>
#include <octomap_msgs/Octomap.h>
#include <octomap_msgs/conversions.h>

typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloudRGB;
PointCloudRGB::Ptr lidar_cloud(new PointCloudRGB);
PointCloudRGB::Ptr cam_cloud(new PointCloudRGB);
ros::Publisher merged_pub;
ros::Publisher octomap_pub;
ros::Publisher lidar_pub;
ros::Publisher lidarf_pub;
ros::Publisher cam_pub;
octomap::ColorOcTree* tree;
tf::TransformListener* tf_listener;
tf::StampedTransform transform_odom_to_base;

void mergeAndPublish()
{
    PointCloudRGB::Ptr merged_cloud(new PointCloudRGB);
    *merged_cloud = *lidar_cloud;
    *merged_cloud += *cam_cloud;

    pcl::VoxelGrid<pcl::PointXYZRGB> voxel_grid;
    voxel_grid.setInputCloud(merged_cloud);
    voxel_grid.setLeafSize(0.01f, 0.01f, 0.01f);

    PointCloudRGB::Ptr filtered_cloud(new PointCloudRGB);
    voxel_grid.filter(*filtered_cloud);

    for (auto& point : filtered_cloud->points)
    {
        point.r = 0;
        point.g = 0;
        point.b = 255;
    }

    sensor_msgs::PointCloud2 merged_ros_cloud;
    pcl::toROSMsg(*filtered_cloud, merged_ros_cloud);
    merged_ros_cloud.header.frame_id = "base_link";
    merged_ros_cloud.header.stamp = ros::Time::now();
    merged_pub.publish(merged_ros_cloud);
}

void pointCloudCallback(const sensor_msgs::PointCloud2::ConstPtr& input)
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::fromROSMsg(*input, *cloud);

    for (auto& point : cloud->points)
    {
        float temp_x = point.x;
        float temp_y = point.y;
        float temp_z = point.z;

        point.x = temp_z;  // y -> x
        point.y = -temp_x;  // z -> y
        point.z = -temp_y+0.35;  // x -> z
    }
    for (auto& point : cloud->points)
    {
        point.r = 0;
        point.g = 255;
        point.b = 100;
    }


    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(*cloud, output);
    output.header.frame_id = "base_link";
    output.header.stamp = input->header.stamp;
    cam_pub.publish(output);
}

void laserScanCallback(const sensor_msgs::LaserScan::ConstPtr& scan_msg)
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    for (size_t i = 0; i < scan_msg->ranges.size(); ++i)
    {
        if (std::isfinite(scan_msg->ranges[i]))
        {
            pcl::PointXYZRGB point;
            float angle = scan_msg->angle_min + i * scan_msg->angle_increment;
            point.x = scan_msg->ranges[i] * cos(angle);
            point.y = scan_msg->ranges[i] * sin(angle);
            ROS_INFO_STREAM(point.x << " and " << point.y);
            point.z = 0.0;
            uint8_t r = 255;
            uint8_t g = 0;
            uint8_t b = 0;
            if (scan_msg->ranges[i] < 1.0)
            {
                r = 0;
                g = 0;
                b = 255;
            }
            point.r = r;
            point.g = g;
            point.b = b;
            cloud->points.push_back(point);
        }
    }

    sensor_msgs::PointCloud2 cloud_msg;
    pcl::toROSMsg(*cloud, cloud_msg);
    cloud->header.frame_id = "base_link";
    cloud->header.stamp = pcl_conversions::toPCL(scan_msg->header).stamp;
    lidarf_pub.publish(cloud);
}

void laserScanfCallback(const sensor_msgs::LaserScan::ConstPtr& scan_msg)
{
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    for (size_t i = 0; i < scan_msg->ranges.size(); ++i)
    {
        if (std::isfinite(scan_msg->ranges[i]))
        {
            pcl::PointXYZRGB point;
            float angle = scan_msg->angle_min + i * scan_msg->angle_increment;
            point.x = scan_msg->ranges[i] * cos(angle);
            point.y = scan_msg->ranges[i] * sin(angle);
            ROS_INFO_STREAM(point.x << " and " << point.y);
            point.z = 0.0;

            uint8_t r = 255;
            uint8_t g = 0;
            uint8_t b = 0;
            if (scan_msg->ranges[i] < 1.0)
            {

                r = 0;
                g = 0;
                b = 255;
            }
            point.r = r;
            point.g = g;
            point.b = b;

            cloud->points.push_back(point);
        }
    }

    sensor_msgs::PointCloud2 cloud_msg;
    pcl::toROSMsg(*cloud, cloud_msg);
    cloud->header.frame_id = "base_link";
    cloud->header.stamp = pcl_conversions::toPCL(scan_msg->header).stamp;
    lidar_pub.publish(cloud);
}

void lidarConvertcallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& msg)
{
    *lidar_cloud = *msg;
    if (cam_cloud)
    {
        mergeAndPublish();
    }
}

void camConvertcallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& msg)
{
    *cam_cloud = *msg;
    if (lidar_cloud)
    {
        mergeAndPublish();
    }
}

void mapConvertcallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& msg) {

//     try {
//         tf_listener->lookupTransform("base_link", "odom", ros::Time(0), transform_odom_to_base);
//     } catch (tf::TransformException& ex) {
//         ROS_ERROR("Transform error odom: %s", ex.what());
//         return;
//     }

// for (const auto& point : msg->points) {
//         tf::Vector3 pt(point.x, point.y, point.z);
//         tf::Vector3 transformed_pt = transform_odom_to_base * pt;

//         tree->updateNode(octomap::point3d(transformed_pt.x(), transformed_pt.y(), transformed_pt.z()), true);
//         tree->integrateNodeColor(transformed_pt.x(), transformed_pt.y(), transformed_pt.z(), point.r, point.g, point.b);
//     }
//     tree->updateInnerOccupancy();

//     octomap_msgs::Octomap octomap_msg;
//     octomap_msgs::fullMapToMsg(*tree, octomap_msg);
//     octomap_msg.header.frame_id = "base_link";
//     octomap_msg.header.stamp = ros::Time::now();
//     octomap_pub.publish(octomap_msg);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pointcloud_laserscan_node");
scan
    ros::NodeHandle nh;

    ros::Subscriber pointcloud_sub = nh.subscribe("/camera/depth/points", 1, pointCloudCallback); //depth camera 
    ros::Subscriber laserscan_sub = nh.subscribe("/st_scan", 1, laserScanCallback); //laser_scanf
    ros::Subscriber laserscanf_sub = nh.subscribe("/scan", 1, laserScanfCallback);
    ros::Subscriber lidar_sub = nh.subscribe("/laser_scan", 5, lidarConvertcallback);
    ros::Subscriber depth_sub = nh.subscribe("/depth_cam", 5, camConvertcallback);
    ros::Subscriber merge_sub = nh.subscribe("/m_pointcloud", 5, mapConvertcallback);

    tree = new octomap::ColorOcTree(0.1);
    tf_listener = new tf::TransformListener();
    tf_listener->waitForTransform("base_link", "odom", ros::Time(0), ros::Duration(10.0));

    merged_pub = nh.advertise<sensor_msgs::PointCloud2>("m_pointcloud", 1);
    lidar_pub = nh.advertise<pcl::PointCloud<pcl::PointXYZRGB>>("laser_scan", 10);
    lidarf_pub = nh.advertise<pcl::PointCloud<pcl::PointXYZRGB>>("laser_scanf", 10);
    cam_pub = nh.advertise<pcl::PointCloud<pcl::PointXYZRGB>>("depth_cam", 10);
    octomap_pub = nh.advertise<octomap_msgs::Octomap>("map", 10);

    ros::spin();
    delete tree;
    delete tf_listener;
    return 0;
}
