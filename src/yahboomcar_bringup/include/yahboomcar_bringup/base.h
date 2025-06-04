#ifndef RIKI_BASE_H
#define RIKI_BASE_H

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <tf2_ros/transform_broadcaster.h>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/twist.hpp>

class RobotBase : public rclcpp::Node {
public:
    RobotBase();

private:
    void velCallback(const geometry_msgs::msg::Twist::SharedPtr twist);
    void publishOdom();

    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr velocity_subscriber_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> odom_broadcaster_;
    
    rclcpp::Time last_vel_time_;
    std::string odom_frame_;
    std::string base_footprint_frame_;
    double linear_scale_x_;
    double linear_scale_y_;
    double vel_dt_;
    double x_pos_;
    double y_pos_;
    double heading_;
    double linear_velocity_x_;
    double linear_velocity_y_;
    double angular_velocity_z_;
};

#endif
