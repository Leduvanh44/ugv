#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_ros/point_cloud.h>

int main(int argc, char** argv)
{
    // Khởi tạo node ROS
    ros::init(argc, argv, "pcd_read");
    ros::NodeHandle nh;

    // Publisher để xuất bản topic dạng PointCloud2
    ros::Publisher pcd_pub = nh.advertise<sensor_msgs::PointCloud2>("map_3d", 1);

    // Tải file PCD
    pcl::PointCloud<pcl::PointXYZRGB> cloud;
    if (pcl::io::loadPCDFile<pcl::PointXYZRGB>("/home/leduvanh/Documents/RTAB-Map/map_80per.pcd", cloud) == -1) {
        ROS_ERROR("Couldn't read the PCD file");
        return -1;
    }

    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(cloud, output);

    output.header.frame_id = "map";

    ros::Rate loop_rate(1); 
    while (ros::ok()) {
        // Cập nhật thời gian hiện tại cho header
        output.header.stamp = ros::Time::now();

        // Xuất bản PointCloud2
        pcd_pub.publish(output);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
