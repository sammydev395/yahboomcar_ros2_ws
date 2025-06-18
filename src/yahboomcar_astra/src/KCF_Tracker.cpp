//
// Created by yahboom on 2021/7/30.
//

#include "yahboomcar_astra/KCF_Tracker.h"

#include <rclcpp/rclcpp.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <rcl_interfaces/msg/set_parameters_result.hpp>

using std::placeholders::_1;

Rect selectRect;
Point origin;
Rect result;
bool select_flag = false;
bool bRenewROI = false;  // the flag to enable the implementation of KCF algorithm for the new chosen ROI
bool bBeginKCF = false;
Mat rgbimage;
Mat depthimage;

const int ACTION_ESC = 27;
const int ACTION_SPACE = 32;

void onMouse(int event, int x, int y, int, void *) {
    if (select_flag) {
        selectRect.x = MIN(origin.x, x);
        selectRect.y = MIN(origin.y, y);
        selectRect.width = abs(x - origin.x);
        selectRect.height = abs(y - origin.y);
        selectRect &= Rect(0, 0, rgbimage.cols, rgbimage.rows);
    }
    if (event == 1) {
        bBeginKCF = false;
        select_flag = true;
        origin = Point(x, y);
        selectRect = Rect(x, y, 0, 0);
    } else if (event == 4) {
        select_flag = false;
        bRenewROI = true;
    }
}

ImageConverter::ImageConverter() : Node("kcf_tracker") {
    this->declare_and_get_parameters();
    this->linear_PID = new PID(this->get_parameter("linear_KP").as_double(),
                               this->get_parameter("linear_KI").as_double(),
                               this->get_parameter("linear_KD").as_double());
    this->angular_PID = new PID(this->get_parameter("angular_KP").as_double(),
                                this->get_parameter("angular_KI").as_double(),
                                this->get_parameter("angular_KD").as_double());
    
    image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/color/image_raw", 1, std::bind(&ImageConverter::imageCb, this, _1));
    depth_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/camera/depth/image_raw", 1, std::bind(&ImageConverter::depthCb, this, _1));
    joy_sub_ = this->create_subscription<std_msgs::msg::Bool>(
        "/JoyState", 1, std::bind(&ImageConverter::joyCb, this, _1));
    image_pub_ = this->create_publisher<sensor_msgs::msg::Image>("/KCF_image", 1);
    pub = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 1);
    pub->publish(geometry_msgs::msg::Twist());
    namedWindow(RGB_WINDOW);
    this->linear_PID->Set_PID(this->get_parameter("linear_KP").as_double(),
                              this->get_parameter("linear_KI").as_double(),
                              this->get_parameter("linear_KD").as_double());
    this->angular_PID->Set_PID(this->get_parameter("angular_KP").as_double(),
                               this->get_parameter("angular_KI").as_double(),
                               this->get_parameter("angular_KD").as_double());
    // Parameter callback
    this->add_on_set_parameters_callback(
        [this](const std::vector<rclcpp::Parameter> &params) {
            for (const auto &param : params) {
                if (param.get_name() == "linear_KP") this->linear_PID->kp = param.as_double();
                if (param.get_name() == "linear_KI") this->linear_PID->ki = param.as_double();
                if (param.get_name() == "linear_KD") this->linear_PID->kd = param.as_double();
                if (param.get_name() == "angular_KP") this->angular_PID->kp = param.as_double();
                if (param.get_name() == "angular_KI") this->angular_PID->ki = param.as_double();
                if (param.get_name() == "angular_KD") this->angular_PID->kd = param.as_double();
                if (param.get_name() == "minDist") this->minDist = param.as_double();
            }
            this->linear_PID->reset();
            this->angular_PID->reset();
            rcl_interfaces::msg::SetParametersResult result;
            result.successful = true;
            return result;
        });
}

ImageConverter::~ImageConverter() {
    delete this->linear_PID;
    delete this->angular_PID;
    destroyWindow(RGB_WINDOW);
}

void ImageConverter::declare_and_get_parameters() {
    this->declare_parameter("linear_KP", 0.9);
    this->declare_parameter("linear_KI", 0.0);
    this->declare_parameter("linear_KD", 0.1);
    this->declare_parameter("angular_KP", 0.5);
    this->declare_parameter("angular_KI", 0.0);
    this->declare_parameter("angular_KD", 0.2);
    this->declare_parameter("minDist", 1.0);
}

void ImageConverter::reset() {
    bRenewROI = false;
    bBeginKCF = false;
    selectRect.x = 0;
    selectRect.y = 0;
    selectRect.width = 0;
    selectRect.height = 0;
    linear_speed = 0;
    rotation_speed = 0;
    enable_get_depth = false;
    this->linear_PID->reset();
    this->angular_PID->reset();
    pub->publish(geometry_msgs::msg::Twist());
}

void ImageConverter::cancel() {
    this->reset();
    rclcpp::sleep_for(std::chrono::milliseconds(500));
    delete this->linear_PID;
    delete this->angular_PID;
    destroyWindow(RGB_WINDOW);
}

void ImageConverter::imageCb(const sensor_msgs::msg::Image::ConstSharedPtr msg) {
    cv_bridge::CvImagePtr cv_ptr;
    try {
        RCLCPP_INFO(this->get_logger(), "imageCb called");
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    } catch (cv_bridge::Exception &e) {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
        return;
    }
    cv_ptr->image.copyTo(rgbimage);
    setMouseCallback(RGB_WINDOW, onMouse, 0);
    if (bRenewROI) {
        if (selectRect.width <= 0 || selectRect.height <= 0) {
            bRenewROI = false;
            return;
        }
        tracker.init(selectRect, rgbimage);
        bBeginKCF = true;
        bRenewROI = false;
        enable_get_depth = false;
    }
    if (bBeginKCF) {
        result = tracker.update(rgbimage);
        rectangle(rgbimage, result, Scalar(0, 255, 255), 1, 8);
        circle(rgbimage, Point(result.x + result.width / 2, result.y + result.height / 2), 3, Scalar(0, 0, 255), -1);
    } else {
        rectangle(rgbimage, selectRect, Scalar(255, 0, 0), 2, 8, 0);
    }
    sensor_msgs::msg::Image::SharedPtr kcf_imagemsg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", rgbimage).toImageMsg();
    image_pub_->publish(*kcf_imagemsg);
    imshow(RGB_WINDOW, rgbimage);
    int action = waitKey(1) & 0xFF;
    if (action == 'q' || action == ACTION_ESC) this->cancel();
    else if (action == 'r') this->reset();
    else if (action == ACTION_SPACE) enable_get_depth = true;
}

void ImageConverter::depthCb(const sensor_msgs::msg::Image::ConstSharedPtr msg) {
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_32FC1);
        cv_ptr->image.copyTo(depthimage);
    } catch (cv_bridge::Exception &e) {
        RCLCPP_ERROR(this->get_logger(), "Could not convert from '%s' to 'TYPE_32FC1'.", msg->encoding.c_str());
    }
    if (enable_get_depth) {
        int center_x = (int)(result.x + result.width / 2);
        int center_y = (int)(result.y + result.height / 2);
        dist_val[0] = depthimage.at<float>(center_y - 5, center_x - 5) / 1000;
        dist_val[1] = depthimage.at<float>(center_y - 5, center_x + 5) / 1000;
        dist_val[2] = depthimage.at<float>(center_y + 5, center_x + 5) / 1000;
        dist_val[3] = depthimage.at<float>(center_y + 5, center_x - 5) / 1000;
        dist_val[4] = depthimage.at<float>(center_y, center_x) / 1000;
        float distance = 0;
        int num_depth_points = 5;
        for (int i = 0; i < 5; i++) {
            if (dist_val[i] > 0.4 && dist_val[i] < 10.0) distance += dist_val[i];
            else num_depth_points--;
        }
        distance /= num_depth_points;
        if (num_depth_points != 0) {
            if (abs(distance - minDist) < 0.1) linear_speed = 0;
            else linear_speed = -linear_PID->compute(minDist, distance);
        }
        rotation_speed = angular_PID->compute(320 / 100.0, center_x / 100.0);
        if (abs(rotation_speed) < 0.1) rotation_speed = 0;
        geometry_msgs::msg::Twist twist;
        twist.linear.x = linear_speed;
        twist.angular.z = rotation_speed;
        pub->publish(twist);
        RCLCPP_INFO(this->get_logger(), "linear = %.3f, angular = %.3f", linear_speed, rotation_speed);
        RCLCPP_INFO(this->get_logger(), "distance = %.3f, center_x = %d", distance, center_x);
    }
    waitKey(1);
}

void ImageConverter::joyCb(const std_msgs::msg::Bool::ConstSharedPtr msg) {
    enable_get_depth = msg->data;
}




