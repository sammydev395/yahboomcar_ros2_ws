#include "yahboomcar_bringup/base.h"
#include <tf2/LinearMath/Quaternion.h>

RobotBase::RobotBase() : Node("odometry_publisher") {
    // Declare parameters
    this->declare_parameter("linear_scale_x", 1.0);
    this->declare_parameter("linear_scale_y", 1.0);
    this->declare_parameter("odom_frame", "odom");
    this->declare_parameter("base_footprint_frame", "base_footprint");

    // Get parameters
    linear_scale_x_ = this->get_parameter("linear_scale_x").as_double();
    linear_scale_y_ = this->get_parameter("linear_scale_y").as_double();
    odom_frame_ = this->get_parameter("odom_frame").as_string();
    base_footprint_frame_ = this->get_parameter("base_footprint_frame").as_string();

    // Initialize variables
    linear_velocity_x_ = 0.0;
    linear_velocity_y_ = 0.0;
    angular_velocity_z_ = 0.0;
    last_vel_time_ = this->now();
    vel_dt_ = 0.0;
    x_pos_ = 0.0;
    y_pos_ = 0.0;
    heading_ = 0.0;

    // Create publishers and subscribers
    odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("/pub_odom", 50);
    velocity_subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "/sub_vel", 50, std::bind(&RobotBase::velCallback, this, std::placeholders::_1));
    odom_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    RCLCPP_INFO(this->get_logger(), "Odometry publisher node started");
}

void RobotBase::velCallback(const geometry_msgs::msg::Twist::SharedPtr twist) {
    rclcpp::Time current_time = this->now();
    linear_velocity_x_ = twist->linear.x * linear_scale_x_;
    linear_velocity_y_ = twist->linear.y * linear_scale_y_;
    angular_velocity_z_ = twist->angular.z;
    vel_dt_ = (current_time - last_vel_time_).seconds();
    last_vel_time_ = current_time;

    // Compute odometry in a typical way given the velocities of the robot
    double delta_heading = angular_velocity_z_ * vel_dt_; // radians
    double delta_x = (linear_velocity_x_ * cos(heading_) - linear_velocity_y_ * sin(heading_)) * vel_dt_; // m
    double delta_y = (linear_velocity_x_ * sin(heading_) + linear_velocity_y_ * cos(heading_)) * vel_dt_; // m

    // Calculate current position of the robot
    x_pos_ += delta_x;
    y_pos_ += delta_y;
    heading_ += delta_heading;

    // Create and publish odometry message
    auto odom = std::make_unique<nav_msgs::msg::Odometry>();
    odom->header.stamp = current_time;
    odom->header.frame_id = odom_frame_;
    odom->child_frame_id = base_footprint_frame_;

    // Set position
    odom->pose.pose.position.x = x_pos_;
    odom->pose.pose.position.y = y_pos_;
    odom->pose.pose.position.z = 0.0;

    // Set orientation
    tf2::Quaternion q;
    q.setRPY(0, 0, heading_);
    odom->pose.pose.orientation.x = q.x();
    odom->pose.pose.orientation.y = q.y();
    odom->pose.pose.orientation.z = q.z();
    odom->pose.pose.orientation.w = q.w();

    // Set covariance
    odom->pose.covariance[0] = 0.001;
    odom->pose.covariance[7] = 0.001;
    odom->pose.covariance[35] = 0.001;

    // Set velocities
    odom->twist.twist.linear.x = linear_velocity_x_;
    odom->twist.twist.linear.y = linear_velocity_y_;
    odom->twist.twist.linear.z = 0.0;
    odom->twist.twist.angular.x = 0.0;
    odom->twist.twist.angular.y = 0.0;
    odom->twist.twist.angular.z = angular_velocity_z_;

    // Set twist covariance
    odom->twist.covariance[0] = 0.0001;
    odom->twist.covariance[7] = 0.0001;
    odom->twist.covariance[35] = 0.0001;

    // Publish odometry message
    odom_publisher_->publish(std::move(odom));

    // Publish transform
    geometry_msgs::msg::TransformStamped transform;
    transform.header.stamp = current_time;
    transform.header.frame_id = odom_frame_;
    transform.child_frame_id = base_footprint_frame_;
    transform.transform.translation.x = x_pos_;
    transform.transform.translation.y = y_pos_;
    transform.transform.translation.z = 0.0;
    transform.transform.rotation = odom->pose.pose.orientation;
    odom_broadcaster_->sendTransform(transform);
}
