#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>

class LaserScanToPCL
{
public:
    LaserScanToPCL()
    {
        laser_scan_sub_ = nh_.subscribe("/scan", 10, &LaserScanToPCL::laserScanCallback, this);
        point_cloud_pub_ = nh_.advertise<pcl::PointCloud<pcl::PointXY>>("laser_scan_point_cloud", 10);
    }

    void laserScanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
    {
        pcl::PointCloud<pcl::PointXY>::Ptr cloud(new pcl::PointCloud<pcl::PointXY>);

        for (size_t i = 0; i < scan->ranges.size(); ++i)
        {
            if (std::isfinite(scan->ranges[i]))
            {
                pcl::PointXY point;
                float angle = scan->angle_min + i * scan->angle_increment;
                point.x = scan->ranges[i] * cos(angle);
                point.y = scan->ranges[i] * sin(angle);
                cloud->points.push_back(point);
            }
        }

        cloud->header.frame_id = scan->header.frame_id;
        cloud->header.stamp = pcl_conversions::toPCL(scan->header).stamp;
        point_cloud_pub_.publish(*cloud);
    }
    

private:
    ros::NodeHandle nh_;
    ros::Subscriber laser_scan_sub_;
    ros::Publisher point_cloud_pub_;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "convert_lidar_node");
    LaserScanToPCL laser_scan_to_pcl;
    ros::spin();
    return 0;
}
