#include <ros/ros.h>
#include <serial/serial.h>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/Imu.h>
#include <utils/DiffVel.h>
#include <utils/Odometry.h>
#include <cmath>
#include <utils/Encoder.h>
#include <boost/bind.hpp>
#include <boost/algorithm/string.hpp>
#include <utils/tf.h>
#include "std_msgs/String.h"
#include <can.h>
using namespace std;
double normalizeAngle(double angle) {
    angle = fmod(angle, 360.0);  
    if (angle > 180.0) {
        angle -= 360.0; 
    } else if (angle < -180.0) {
        angle += 360.0;
    }
    return angle;
}

void veldiffCallback(const utils::DiffVel::ConstPtr& msg, serial::Serial& serialPort) {
    uint8_t data[8];
    float x = msg->left_vel;
    float y = msg->right_vel;
    memcpy(&data[0], &x, sizeof(float));
    memcpy(&data[4], &y, sizeof(float));
    serialPort.write(data, sizeof(data));
    ROS_INFO_STREAM("Sent velocity data: x=" << x << ", y=" << y);
}

void float_to_array(float numf, uint8_t* array) {
    if (1) {
    int chuc = static_cast<int>(numf);
    float donvi = numf - chuc;
    int tens = chuc / 10;
    int units = chuc % 10;
    long int thapphan = static_cast<long int>(donvi * 10000);
    array[0] = static_cast<uint8_t>(tens) + 0x30;
    array[1] = static_cast<uint8_t>(units) + + 0x30;
    array[2] = 0x2E;
    array[3] = static_cast<uint8_t>(thapphan / 1000)+ 0x30;
    array[4] = static_cast<uint8_t>((thapphan / 100) % 10)+ 0x30;
    array[5] = static_cast<uint8_t>((thapphan / 10) % 10)+ 0x30;
    array[6] = static_cast<uint8_t>(thapphan % 10)+ 0x30;
    }
}
    
void serialCallback(const std::string& data, serial::Serial& serialPort, ros::Publisher& pubOdom, ros::Publisher& pubEncode, ros::Publisher pubdata, ros::Publisher pubImu) {
    std::vector<std::string> dataList;
    std::stringstream ss(data);
    std::string token;
    // ROS_INFO_STREAM("Received "  
    // while (std::getline(ss, token, '#')) <group if="$(arg enable_ahrs)">

    //     dataList.push_back(token);
    // }
    boost::split(dataList,data,boost::is_any_of("#,$"));

    std_msgs::String msg;
    for (const std::string& data : dataList) {
        msg.data = data;
        pubdata.publish(msg);
    }
    for (int i = 0; i < dataList.size();i++) {
        ROS_INFO_STREAM("data" << i << ": " << dataList[i]);
    }
    // ROS_INFO_STREAM("Received "  << dataList[11]  << " bytes " << "so phan tu: " << dataList[0]);

    if (dataList.size() == 13) {
        try{
            imu.linear_acceleration.x = std::stof(dataList[6]) * 9.81;
            imu.linear_acceleration.y = std::stof(dataList[7])* 9.81;
            imu.linear_acceleration.z = std::stof(dataList[8])* 9.81;
            imu.angular_velocity.x = std::stof(dataList[9]) * M_PI / 180;
            imu.angular_velocity.y = std::stof(dataList[10]) * M_PI / 180;
            imu.angular_velocity.z = std::stof(dataList[11]) * M_PI / 180;
            ROS_INFO_STREAM("data: " << std::stod(dataList[4]) << ":" << normalizeAngle(std::stod(dataList[5])) << ":" << std::stod(dataList[1]));
            imu.orientation = get_quaternion_from_RPY(std::stod(dataList[4]), std::stod(dataList[5]) , std::stod(dataList[1]));
            imu.header.frame_id = "imu";
            imu.header.stamp = ros::Time::now();

            encode.left_twist = std::stof(dataList[2]);
            encode.right_twist = std::stof(dataList[3]);

            odom.linear_acceleration.x = std::stof(dataList[6]);
            odom.linear_acceleration.y = std::stof(dataList[7]);
            odom.linear_acceleration.z = std::stof(dataList[8]);
            odom.angular_velocity.x = std::stof(dataList[9]);
            odom.angular_velocity.y = std::stof(dataList[10]);
            odom.angular_velocity.z = std::stof(dataList[11]);
            odom.orientation = get_quaternion_from_RPY(std::stod(dataList[4]), std::stod(dataList[5]), std::stod(dataList[1]));
            // ROS_INFO_STREAM("z: " << odom.orientation.w);
            odom.YPY.x = std::stod(dataList[4]);
            odom.YPY.y = std::stod(dataList[5]);
            odom.YPY.z = std::stod(dataList[1]) * M_PI / 180;
            odom.header.frame_id = "imu";
            odom.header.stamp = ros::Time::now();
            odom.heading = std::stof(dataList[1]) * M_PI / 180;
            // ROS_INFO_STREAM("alo");
        } catch (const std::invalid_argument& e) {
            std::cerr << "Lỗi: " << e.what() << std::endl;
        }
    }
}

void updatePub(const ros::TimerEvent&) {
    pubImu.publish(imu);
    pubOdom.publish(odom);
    pubEncode.publish(encode);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "can_node");
    ros::NodeHandle nh;
    ros::NodeHandle private_nh("~");
    private_nh.getParam("enable_can", can_enabled);
    private_nh.getParam("can_port", can_port);
    private_nh.getParam("can_baud", can_baudrate);
    pubOdom = nh.advertise<utils::Odometry>("odom_2", 10);
    pubdata = nh.advertise<std_msgs::String>("odom_test", 10);
    pubEncode = nh.advertise<utils::Encoder>("diff_motor/real_vel", 10);
    pubImu = nh.advertise<sensor_msgs::Imu>("imu/data", 10);
    loopPub = nh.createTimer(ros::Duration(0.01), updatePub);
    serial::Serial serialPort;
    try {
        serialPort.setPort(can_port);
        serialPort.setBaudrate(can_baudrate);
        serial::Timeout timeout = serial::Timeout::simpleTimeout(1000);
        serialPort.setTimeout(timeout);
        serialPort.open();
    } catch (serial::IOException& e) {
        ROS_ERROR_STREAM("Unable to open serial port: " << e.what());
        return -1;
    }
    if (!serialPort.isOpen()) {
        ROS_ERROR_STREAM("Failed to open serial port.");
        return -1;
    }

    ros::Subscriber sub = nh.subscribe<utils::DiffVel>("/diff_motor/vel", 1000, [&](const utils::DiffVel::ConstPtr& msg) {
        uint8_t data[15];
        uint8_t num[7];
        float x = msg->left_vel;
        float y = msg->right_vel;
        float_to_array(x, num);
        memcpy(&data[0], &num[0], sizeof(num));
        data[7] = 0x2C;
        // data[15] = 0x0D;
        // data[16] = 0x0A;
        float_to_array(y, num);
        memcpy(&data[8], &num[0], sizeof(num));        
        serialPort.write(data, sizeof(data));
        ROS_INFO_STREAM("Sent data to serial port: x=" << x << ", y=" << y);
    });

    try {
        while (ros::ok()) {
            if (serialPort.available()) {
                std::string data = serialPort.readline(100, "$");
                // ROS_INFO_STREAM("dataa:" << data);
                serialCallback(data, serialPort, pubOdom, pubEncode, pubdata, pubImu);
            }
            ros::spinOnce();
        }
    } catch (serial::IOException& e) {
        ROS_ERROR_STREAM("Error reading from serial port: " << e.what());
    }
    serialPort.close();
    return 0;
}
