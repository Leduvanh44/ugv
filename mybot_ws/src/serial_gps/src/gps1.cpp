#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/String.h>
#include <QByteArray>
#include <QList>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sensor_msgs/NavSatFix.h>
#include <utils/Odometry.h>
#include <utils/DiffVel.h>
#include <cmath>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
inline void convert_global_to_local_coords(const double& lat, const double& lon, const double& ref_lat,
                                           const double ref_lon, double& x, double& y) {

    if ((lat == ref_lat) && (lon == ref_lon))
        x = y = 0;

    double lat_rad = lat * M_PI / 180.0;
    double lon_rad = lon * M_PI / 180.0;

    double ref_lon_rad = ref_lon * M_PI / 180.0;
    double ref_lat_rad = ref_lat * M_PI / 180.0;

    // double _y = sin(lon_rad - ref_lon_rad ) * cos(lat_rad);
    // double _x = cos(ref_lat_rad) *sin (lat_rad);
    
    // double bearing = atan2(_y,_x);
    // double a = sin((lat_rad-ref_lat_rad)/2)*sin((lat_rad - ref_lat_rad)/2) + cos(ref_lat_rad)*cos(lat_rad)*sin((lon_rad - ref_lon_rad)/2)*sin((lon_rad-ref_lon_rad)/2);
    // double c = 2*atan2(sqrt(a),sqrt(1-a));
    // double distance = 6371000 * c;

    // double Heading = 2*M_PI-bearing;
    // x = distance*cos(Heading);
    // y = distance*sin(Heading);

  double sin_lat = sin(lat_rad);
  double cos_lat = cos(lat_rad);
  double cos_d_lon = cos(lon_rad - ref_lon_rad);

  double ref_sin_lat = sin(ref_lat_rad);
  double ref_cos_lat = cos(ref_lat_rad);

  double c = acos(ref_sin_lat * sin_lat + ref_cos_lat * cos_lat * cos_d_lon);
  double k = (fabs(c) < std::numeric_limits<double>::epsilon()) ? 1.0 : (c / sin(c));

  x = k * (ref_cos_lat * sin_lat - ref_sin_lat * cos_lat * cos_d_lon) * 6371000;
  y = k * cos_lat * sin(lon_rad - ref_lon_rad) * 6371000;
}
inline double convert_num_5(double dnum) {
    return static_cast<double>(int(dnum*100000))/100000;
}
inline double convert_num_4(double dnum) {
    return static_cast<double>(int(dnum*100000))/100000;
}
inline double convert_num_6(double dnum) {
    return static_cast<double>(int(dnum*1000000))/1000000;
}
inline double CalLat2Deg(double Lat)
  {
    static uint8_t Deg = 0;
    static double Min = 0, Result = 0;
    Deg = Lat / 100;
    Min = Lat - Deg * 100;
    Result = Deg + Min / 60;
    return convert_num_6(Result);
  }
inline double CalLong2Deg(double Long)
{
    static uint16_t Deg = 0;
    static double Min = 0, Result = 0;
    Deg = Long / 100;
    Min = Long - Deg * 100;
    Result = Deg + Min / 60;
    return convert_num_6(Result);
}


void serialCallback(const std::string& data, serial::Serial& serialPort, ros::Publisher& gps_pub,  ros::Publisher& data_pub, ros::Publisher& pubOdom, double ref_lat, double ref_lon) {

    std::vector<std::string> dataList;
    std::stringstream ss(data);
    std::string token;
    while (std::getline(ss, token, ',')) {
        dataList.push_back(token);
    }
    // std_msgs::String msg;
    // for (const std::string& data : dataList) {
    //     msg.data = data;
    //     data_pub.publish(msg);
    // }
    if (dataList[0] == "GGA") {
        ROS_INFO_STREAM("data: " << data);
        ROS_INFO_STREAM("asdfgh: " << " || " << dataList[0]);
        if (dataList.size() <= 30) {
            try {
                double latitude = CalLat2Deg(std::stof(dataList[2]));
                double longtitude = CalLong2Deg(std::stof(dataList[4]));
                double altitude = std::stof(dataList[9]);
                utils::Odometry odomMsg;
                sensor_msgs::NavSatFix gps_msg;
                odomMsg.latitude = latitude;
                odomMsg.longitude = longtitude;
                odomMsg.altitude = altitude;
                gps_msg.latitude = latitude;
                gps_msg.longitude = longtitude;
                gps_msg.altitude = altitude;
                convert_global_to_local_coords(convert_num_5(odomMsg.latitude),convert_num_5(odomMsg.longitude), ref_lat,ref_lon,
                                     odomMsg.position.x, odomMsg.position.y);
                odomMsg.position.z = -odomMsg.altitude;
                double x1 = convert_num_5(odomMsg.position.x);
                double y1 = convert_num_5(odomMsg.position.y);

                gps_pub.publish(gps_msg);
                pubOdom.publish(odomMsg);
                std::ostringstream lat_str;
                lat_str << std::fixed << std::setprecision(5) << x1;
                std::ostringstream long_str;
                long_str << std::fixed << std::setprecision(5) << y1;
                std::ostringstream alt_str;
                alt_str << std::fixed << std::setprecision(3) << altitude;

                ROS_INFO_STREAM("Latitude value: " << lat_str.str());
                ROS_INFO_STREAM("Longtitude value: " << long_str.str());
                ROS_INFO_STREAM("Atitude value: " << alt_str.str());
            } catch (const std::invalid_argument& e) {
                ROS_INFO_STREAM("Invalid argument: " << e.what());
            } catch (const std::out_of_range& e) {
                ROS_INFO_STREAM("Out of range: " << e.what());
            }
        }
        ROS_INFO_STREAM("Received GAA"  << data.size()  << " bytes " << "so phan tu: " << dataList.size());
    }
    else if (dataList[0] == "GL") {
        ROS_INFO_STREAM("data: " << data);
        ROS_INFO_STREAM("asdfgh: " << " || " << dataList[0]);
        if (dataList.size() <= 30) {
            try {
                double latitude = CalLat2Deg(std::stof(dataList[1]));
                double longtitude = CalLong2Deg(std::stof(dataList[3]));
                double altitude = 0;
                utils::Odometry odomMsg;
                sensor_msgs::NavSatFix gps_msg;
                odomMsg.latitude = latitude;
                odomMsg.longitude = longtitude;
                odomMsg.altitude = altitude;
                gps_msg.latitude = latitude;
                gps_msg.longitude = longtitude;
                gps_msg.altitude = altitude;
                convert_global_to_local_coords(convert_num_5(odomMsg.latitude),convert_num_5(odomMsg.longitude), ref_lat,ref_lon,
                                     odomMsg.position.x, odomMsg.position.y);
                odomMsg.position.z = -odomMsg.altitude;
                double x1 = convert_num_5(odomMsg.position.x);
                double y1 = convert_num_5(odomMsg.position.y);

                gps_pub.publish(gps_msg);
                pubOdom.publish(odomMsg);
                std::ostringstream lat_str;
                lat_str << std::fixed << std::setprecision(5) << x1;
                std::ostringstream long_str;
                long_str << std::fixed << std::setprecision(5) << y1;
                std::ostringstream alt_str;
                alt_str << std::fixed << std::setprecision(3) << altitude;

                ROS_INFO_STREAM("Latitude value: " << lat_str.str());
                ROS_INFO_STREAM("Longtitude value: " << long_str.str());
                ROS_INFO_STREAM("Atitude value: " << alt_str.str());
            } catch (const std::invalid_argument& e) {
                ROS_INFO_STREAM("Invalid argument: " << e.what());
            } catch (const std::out_of_range& e) {
                ROS_INFO_STREAM("Out of range: " << e.what());
            }
        }
        ROS_INFO_STREAM("Received GNLL"  << data.size()  << " bytes " << "so phan tu: " << dataList.size());
    }
}

void onCallbackPose(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) {

}

int main(int argc, char** argv) {
    ros::init(argc, argv, "gps_node1");
    ros::NodeHandle nh;
    ros::NodeHandle private_nh("~");
    bool gps_enabled;
    std::string gps_port;
    int gps_baudrate;
    double ref_lon, ref_lat;
    private_nh.getParam("enable_gps", gps_enabled);
    private_nh.getParam("gps_port", gps_port);
    private_nh.getParam("gps_baud", gps_baudrate);
    private_nh.getParam("ref_lat", ref_lat);
    private_nh.getParam("ref_lon", ref_lon);


    serial::Serial serialPort;
    try {
        serialPort.setPort(gps_port);
        serialPort.setBaudrate(115200);
        serial::Timeout timeout = serial::Timeout::simpleTimeout(1000);
        serialPort.setTimeout(timeout);
        ROS_INFO_STREAM("12356");
        serialPort.open();
    } catch (serial::IOException& e) {
        ROS_ERROR_STREAM("Unable to open serial port: " << e.what());
        return -1;
    }


    if (!serialPort.isOpen()) {
        ROS_ERROR_STREAM("Failed to open serial port.");
        return -1;
    }
    ros::Publisher data_pub = nh.advertise<std_msgs::String>("gps_1", 10);
    ros::Publisher gps_pub = nh.advertise<sensor_msgs::NavSatFix>("gps", 100);
    ros::Publisher pubOdom = nh.advertise<utils::Odometry>("odom_1", 10);
    ros::Subscriber sub_pose = nh.subscribe("/amcl_pose", 10, onCallbackPose);
    
    try {
        while (ros::ok()) {
            if (1) {
                std::string data = serialPort.readline(100, "$GN");
                serialCallback(data, serialPort, gps_pub, data_pub, pubOdom, ref_lat, ref_lon);
            }
            ros::spinOnce();
        }
    } catch (serial::IOException& e) {
        ROS_ERROR_STREAM("Error reading from serial port: " << e.what());
    }

    serialPort.close();
    
    return 0;
}
