#include <iostream>
#include <stdio.h>
#include "drive.h"
#include "sys/time.h"
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/transform_broadcaster.h"
#include <tf2/LinearMath/Quaternion.h>
#include <nav_msgs/msg/odometry.hpp>

#include "std_msgs/msg/int32.hpp"
#include "geometry_msgs/msg/twist_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "messages/msg/cobot_raw_status.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"


#define RAD(deg) ((deg) * M_PI / 180.0)

class cobotDriveMain : public rclcpp::Node
{
private:

    //atributes
    rclcpp::Publisher<messages::msg::CobotRawStatus>::SharedPtr cobotRawStatusPublisher;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr cobotOdometryPublisher;

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr drive_sub;

    rclcpp::TimerBase::SharedPtr timer_;

    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

    CobotDrive* cobotDrive;

    //methods
    void cobotDriveCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
    void timerEvent();


public:
    cobotDriveMain() ;
    ~cobotDriveMain() ;


};



