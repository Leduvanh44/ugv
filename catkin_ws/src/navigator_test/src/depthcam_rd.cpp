#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl_ros/point_cloud.h>
#include <Eigen/Dense>
#include <pcl/common/transforms.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

ros::Publisher cam_pub;
pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZRGB>);

void lidarCallback(const pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr& cam_cloud)
{
    *cloud_in = *cam_cloud;
    Eigen::Affine3f transform = Eigen::Affine3f::Identity();

    transform.translation() << 0.0, -1, 0.0;
    ROS_INFO_STREAM("Transformation Matrix:\n" << transform.matrix());

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr transformed_cloud(new pcl::PointCloud<pcl::PointXYZRGB>());
    pcl::transformPointCloud(*cloud_in, *transformed_cloud, transform);
    cam_pub.publish(transformed_cloud);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "depthcam_read");
    ros::NodeHandle nh;

    ros::Subscriber lidar_sub = nh.subscribe("base/depth/points", 10, lidarCallback);
    cam_pub = nh.advertise<pcl::PointCloud<pcl::PointXYZRGB>>("check_cloud", 10);
    ros::spin();
    return 0;
}

