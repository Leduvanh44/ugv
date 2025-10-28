cmake_minimum_required(VERSION 3.0.2)
project(cmd_vel_converter)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
  utils
  sensor_msgs
)

 generate_messages(
   DEPENDENCIES
   geometry_msgs
   std_msgs
   sensor_msgs
 )

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ./include
  ./src
)

 add_executable(cmd_vel_converter 
    src/cmd_vel_converter.cpp)

 target_link_libraries(cmd_vel_converter
   ${catkin_LIBRARIES}
 )

