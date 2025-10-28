cmake_minimum_required(VERSION 2.8.3)
project(serial)

## Find catkin and required packages
find_package(catkin REQUIRED)

## Detect platform
if(APPLE)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(FOUNDATION_LIBRARY Foundation)
endif()

if(UNIX AND NOT APPLE)
    # Nếu là Linux, thêm thư viện `rt` và `pthread`
    set(rt_LIBRARIES rt)
    set(pthread_LIBRARIES pthread)
endif()

## Khai báo package ROS để thư viện có thể được sử dụng bởi các package khác
catkin_package(
    INCLUDE_DIRS include
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS
    DEPENDS rt pthread
)

## Include headers
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

## Source files
set(serial_SRCS
    src/serial.cc
    include/serial/serial.h
    include/serial/v8stdint.h
)

## Thêm file nền tảng cụ thể
if(APPLE)
    list(APPEND serial_SRCS src/impl/unix.cc)
    list(APPEND serial_SRCS src/impl/list_ports/list_ports_osx.cc)
elseif(UNIX)
    list(APPEND serial_SRCS src/impl/unix.cc)
    list(APPEND serial_SRCS src/impl/list_ports/list_ports_linux.cc)
else()
    list(APPEND serial_SRCS src/impl/win.cc)
    list(APPEND serial_SRCS src/impl/list_ports/list_ports_win.cc)
endif()

## Tạo thư viện shared (có thể dùng trong package khác)
add_library(${PROJECT_NAME} SHARED ${serial_SRCS})

## Link thư viện cần thiết
if(APPLE)
    target_link_libraries(${PROJECT_NAME} ${FOUNDATION_LIBRARY} ${IOKIT_LIBRARY})
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} rt pthread)
else()
    target_link_libraries(${PROJECT_NAME} setupapi)
endif()

## Cài đặt thư viện và headers để các package khác có thể sử dụng
install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
    RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

install(DIRECTORY include/serial
    DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
)

add_executable(serial_example examples/serial_example.cc)
target_link_libraries(serial_example ${PROJECT_NAME})

## Chạy test nếu có
if(CATKIN_ENABLE_TESTING)
    add_subdirectory(tests)
endif()
