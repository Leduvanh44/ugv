#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <nav_msgs/OccupancyGrid.h>
#include <vector>

class PointCloudToOccupancyGrid
{
public:
    PointCloudToOccupancyGrid()
    {
        point_cloud_sub_ = nh_.subscribe("/laser_scan_point_cloud", 1, &PointCloudToOccupancyGrid::pointCloudCallback, this);
        occupancy_grid_pub_ = nh_.advertise<nav_msgs::OccupancyGrid>("map", 1);

        occupancy_grid_.header.frame_id = "map";
        occupancy_grid_.info.resolution = 0.05; 
        occupancy_grid_.info.width = 400; // 20 meters
        occupancy_grid_.info.height = 400; // 20 meters
        occupancy_grid_.info.origin.position.x = -10.0; // Start at -10 meters
        occupancy_grid_.info.origin.position.y = -10.0; // Start at -10 meters
        occupancy_grid_.info.origin.position.z = 0.0;
        occupancy_grid_.info.origin.orientation.w = 1.0;
        occupancy_grid_.data.resize(occupancy_grid_.info.width * occupancy_grid_.info.height, -1);
    }

    void pointCloudCallback(const sensor_msgs::PointCloud2::ConstPtr& cloud_msg)
    {
        pcl::PointCloud<pcl::PointXY> cloud;
        pcl::fromROSMsg(*cloud_msg, cloud);

        // Clear the previous occupancy grid
        std::fill(occupancy_grid_.data.begin(), occupancy_grid_.data.end(), -1);

        for (const auto& point : cloud.points)
        {
            if (std::isfinite(point.x) && std::isfinite(point.y))
            {
                int x_index = static_cast<int>((point.x - occupancy_grid_.info.origin.position.x) / occupancy_grid_.info.resolution);
                int y_index = static_cast<int>((point.y - occupancy_grid_.info.origin.position.y) / occupancy_grid_.info.resolution);

                if (x_index >= 0 && x_index < occupancy_grid_.info.width && y_index >= 0 && y_index < occupancy_grid_.info.height)
                {
                    int index = y_index * occupancy_grid_.info.width + x_index;
                    occupancy_grid_.data[index] = 100; 
                }
            }
        }

        occupancy_grid_.header.stamp = ros::Time::now();
        occupancy_grid_pub_.publish(occupancy_grid_);
    }

private:
    ros::NodeHandle nh_;
    ros::Subscriber point_cloud_sub_;
    ros::Publisher occupancy_grid_pub_;
    nav_msgs::OccupancyGrid occupancy_grid_;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "mapping_node");
    PointCloudToOccupancyGrid point_cloud_to_occupancy_grid;
    ros::spin();
    return 0;
}
