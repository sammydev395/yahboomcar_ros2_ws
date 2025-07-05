/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2016  <copyright holder> <email>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include <chrono>
#include <ctime>
#include <climits>
#include <Eigen/Core>
#include <Eigen/Geometry>  // Eigen 几何模块
#include <opencv2/highgui/highgui.hpp>
#include "PCLMapper.h"
#include <rclcpp/rclcpp.hpp>
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/msg/point_cloud2.hpp>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
////    	cout<<RED<<"compute the intensity of features ..."<<WHITE<<endl;
using namespace std;

namespace Mapping {

/*
 * 
 * @ 设置点云分辨率
 */
    PointCloudMapper::PointCloudMapper()
            : Node("pointcloud_mapper"), it(shared_from_this()) {
        float fx_, fy_, cx_, cy_, resolution_, depthfactor_;
        int queueSize_;
        bool mbuseExact_;

        mbuseCompressed = false;
        lastKeyframeSize = 0;
        mGlobalPointCloudID = 0; //点云ID
        mLastGlobalPointCloudID = 0;
        queueSize = 10;

        std::string topicColor, topicDepth, topicTcw, topicPointCloud;

        topicColor = this->declare_parameter("topicColor", "/RGBD/RGB/Image");
        topicDepth = this->declare_parameter("topicDepth", "/RGBD/Depth/Image");
        topicTcw = this->declare_parameter("topicTcw", "/RGBD/CameraPose");
        local_frame_id = this->declare_parameter("local_frame_id", "camera");
        global_frame_id = this->declare_parameter("global_frame_id", "camera");
        mNodePath = this->declare_parameter("node_path", "./");
        use_viewer = this->declare_parameter("use_viewer", false);
        std::cout << "mNodePath: " << mNodePath << std::endl;

        this->declare_parameter("fx", 517.306408);
        this->declare_parameter("fy", 516.469215);
        this->declare_parameter("cx", 318.643040);
        this->declare_parameter("cy", 255.313989);
        this->declare_parameter("resolution", 0.05);
        this->declare_parameter("depthfactor", 1.0);
        this->declare_parameter("queueSize", 10);
        this->declare_parameter("buseExact", true);

        fx_ = this->get_parameter("fx").as_double();
        fy_ = this->get_parameter("fy").as_double();
        cx_ = this->get_parameter("cx").as_double();
        cy_ = this->get_parameter("cy").as_double();
        resolution_ = this->get_parameter("resolution").as_double();
        depthfactor_ = this->get_parameter("depthfactor").as_double();
        queueSize_ = this->get_parameter("queueSize").as_int();
        mbuseExact_ = this->get_parameter("buseExact").as_bool();

        mbuseExact = mbuseExact_;  //
        queueSize = queueSize_;
        mcx = cx_;
        mcy = cy_;
        mfx = fx_;
        mfy = fy_;
        mresolution = resolution_;
        mDepthMapFactor = depthfactor_;

        image_transport::TransportHints hints(this, mbuseCompressed ? "compressed" : "raw");
        subImageColor = new image_transport::SubscriberFilter(this, topicColor, "raw");
        subImageDepth = new image_transport::SubscriberFilter(this, topicDepth, "raw");
        tcw_sub = new message_filters::Subscriber<geometry_msgs::msg::PoseStamped>(this, topicTcw, rmw_qos_profile_default);
        
        cout << "use_viewer: " << use_viewer << endl;
        cout << "topicColor: " << topicColor << endl;
        cout << "topicDepth: " << topicDepth << endl;
        cout << "topicTcw: " << topicTcw << endl;
        cout << "local_frame_id: " << local_frame_id << endl;
        cout << "global_frame_id: " << global_frame_id << endl;

        cout << "fx: " << mfx << endl;
        cout << "fy: " << mfy << endl;
        cout << "cx: " << mcx << endl;
        cout << "cy: " << mcy << endl;
        cout << "resolution: " << mresolution << endl;
        cout << "DepthMapFactor: " << mDepthMapFactor << endl;
        cout << "queueSize: " << queueSize << endl;
        cout << "mbuseExact: " << mbuseExact << endl;

        //接受RGB DepTh 位姿数据
        if (mbuseExact) {
            syncExact = new message_filters::Synchronizer<ExactSyncPolicy>(ExactSyncPolicy(queueSize), *subImageColor,
                                                                           *subImageDepth, *tcw_sub);
            syncExact->registerCallback(std::bind(&PointCloudMapper::callback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
        } else {
            syncApproximate = new message_filters::Synchronizer<ApproximateSyncPolicy>(ApproximateSyncPolicy(queueSize),
                                                                                       *subImageColor, *subImageDepth,
                                                                                       *tcw_sub);
            syncApproximate->registerCallback(std::bind(&PointCloudMapper::callback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
        }

        voxel.setLeafSize(mresolution, mresolution, mresolution);
        globalMap = PointCloud::Ptr(new PointCloud());
        localMap = PointCloud::Ptr(new PointCloud());

        pub_global_pointcloud = this->create_publisher<sensor_msgs::msg::PointCloud2>("Global/PointCloudOutput", 1);
        pub_local_pointcloud = this->create_publisher<sensor_msgs::msg::PointCloud2>("Local/PointCloudOutput", 10);

    }

    PointCloudMapper::~PointCloudMapper() {
        shutdown();
    }


// 由外部函数调用，每生成一个关键帧调用一次该函数
    void PointCloudMapper::insertKeyFrame(cv::Mat &color, cv::Mat &depth, geometry_msgs::msg::PoseStamped &T) {
        unique_lock<mutex> lck(keyframeMutex);
        // 已测试接受到的数据没有问题
//        cout<< BLUE<<"--------------------------------T:\n"<<T.matrix()<<WHITE<<endl;
        mvGlobalPointCloudsPose.push_back(T);

        colorImgs.push_back(color.clone());
        depthImgs.push_back(depth.clone());


        //mLastGlobalPointCloudID=mGlobalPointCloudID;
        mGlobalPointCloudID++;
        mbKeyFrameUpdate = true;

        cout << GREEN << "--------------------------------receive a keyframe, id = " << mGlobalPointCloudID << WHITE
             << endl;
    }

/**
 * @function 更加关键帧生成点云、并对点云进行滤波处理
 * 备注：点云生成函数在　台式机上调用时间在0.1ｓ 左右
 */
    pcl::PointCloud<PointCloudMapper::PointT>::Ptr
    PointCloudMapper::generatePointCloud(cv::Mat &color, cv::Mat &depth, Eigen::Isometry3d &T) {
        chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
        PointCloud::Ptr tmp(new PointCloud());// point cloud is null ptr

        for (int m = 0; m < depth.rows; m += 3) {
            for (int n = 0; n < depth.cols; n += 3) {
                float d = depth.ptr<float>(m)[n] / mDepthMapFactor;
                if (d < 0.01 || d > 10) {
                    continue;
                }
                PointT p;
                p.z = d;
                p.x = (n - mcx) * p.z / mfx;
                p.y = (m - mcy) * p.z / mfy;

                p.b = color.ptr<uchar>(m)[n * 3];
                p.g = color.ptr<uchar>(m)[n * 3 + 1];
                p.r = color.ptr<uchar>(m)[n * 3 + 2];

                tmp->points.push_back(p);
            }
        }

        PointCloud::Ptr cloud_voxel_tem(new PointCloud);
        tmp->is_dense = false;
        voxel.setInputCloud(tmp);
        voxel.setLeafSize(mresolution, mresolution, mresolution);
        voxel.filter(*cloud_voxel_tem);

        PointCloud::Ptr cloud1(new PointCloud);

        // 这里对点云进行变换
        pcl::transformPointCloud(*cloud_voxel_tem, *cloud1, T.matrix());

        chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
        chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

        cout << GREEN << "generate point cloud from  kf-ID:" << mLastGlobalPointCloudID << ", size="
             << cloud1->points.size() << " cost time: " << time_used.count() * 1000 << " ms ." << WHITE << endl;
        mLastGlobalPointCloudID++;
        return cloud1;
    }


/*
 *
 * 由于随着尺寸的增加以后,显示函数会异常退出
 */
    void PointCloudMapper::viewer() {
        int N = 0, i = 0;
        bool KFUpdate = false;
        if (use_viewer) {
            pcl::visualization::CloudViewer pcl_viewer("viewer");
            while (rclcpp::ok()) {
                {
                    unique_lock<mutex> lck_shutdown(shutDownMutex);
                    if (shutDownFlag) {
                        break;
                    }
                }
                // keyframe is updated
                KFUpdate = false;
                {
                    unique_lock<mutex> lck(keyframeMutex);
                    N = (int) mvGlobalPointCloudsPose.size();
                    KFUpdate = mbKeyFrameUpdate;
                    mbKeyFrameUpdate = false;
//                std::cout << "---------------------------lck mbKeyFrameUpdate N:" << mbKeyFrameUpdate << std::endl;
                }
                if (KFUpdate) {
                    std::cout << "---------------------------KFUpdate N:" << N << std::endl;
                    for (i = lastKeyframeSize; i < N && i < (lastKeyframeSize + 5); i++) {
                        if ((mvGlobalPointCloudsPose.size() != colorImgs.size()) ||
                            (mvGlobalPointCloudsPose.size() != depthImgs.size()) ||
                            (depthImgs.size() != colorImgs.size())) {
                            cout << " depthImgs.size != colorImgs.size()  " << endl;
                            continue;
                        }
                        PointCloud::Ptr tem_cloud1(new PointCloud());
                        cout << "i: " << i << "  mvPosePointClouds.size(): " << mvGlobalPointCloudsPose.size() << endl;
                        //生成一幅点云大约在0.1s左右 点云数据
                        Eigen::Isometry3d transform = convert2Eigen(mvGlobalPointCloudsPose[i]);
                        //
                        tem_cloud1 = generatePointCloud(colorImgs[i], depthImgs[i], transform);

                        if (tem_cloud1->empty()) continue;

                        *globalMap += *tem_cloud1;

                        sensor_msgs::msg::PointCloud2 local;
                        pcl::toROSMsg(*tem_cloud1, local);// 转换成ROS下的数据类型 最终通过topic发布
                        local.header.stamp = rclcpp::Clock().now();
                        local.header.frame_id = local_frame_id;
                        pub_local_pointcloud->publish(local);
                    }
                    {
                        int buff_length = 150;
                        if (i > (buff_length + 5)) {
                            shutdown();
                            break;
                        }
                    }
                    lastKeyframeSize = i;
                    sensor_msgs::msg::PointCloud2 output;
                    pcl::toROSMsg(*globalMap, output);
                    output.header.stamp = rclcpp::Clock().now();
                    output.header.frame_id = global_frame_id;
                    pub_global_pointcloud->publish(output);
                    pcl_viewer.showCloud(globalMap);
                    cout << "show global map, size=" << globalMap->points.size() << endl;
                }
            }

        } else{
            while (rclcpp::ok()) {
                {
                    unique_lock<mutex> lck_shutdown(shutDownMutex);
                    if (shutDownFlag) {
                        break;
                    }
                }
                // keyframe is updated
                KFUpdate = false;
                {
                    unique_lock<mutex> lck(keyframeMutex);
                    N = (int) mvGlobalPointCloudsPose.size();
                    KFUpdate = mbKeyFrameUpdate;
                    mbKeyFrameUpdate = false;
//                std::cout << "---------------------------lck mbKeyFrameUpdate N:" << mbKeyFrameUpdate << std::endl;
                }
                if (KFUpdate) {
                    std::cout << "---------------------------KFUpdate N:" << N << std::endl;
                    for (i = lastKeyframeSize; i < N && i < (lastKeyframeSize + 5); i++) {
                        if ((mvGlobalPointCloudsPose.size() != colorImgs.size()) ||
                            (mvGlobalPointCloudsPose.size() != depthImgs.size()) ||
                            (depthImgs.size() != colorImgs.size())) {
                            cout << " depthImgs.size != colorImgs.size()  " << endl;
                            continue;
                        }
                        PointCloud::Ptr tem_cloud1(new PointCloud());
                        cout << "i: " << i << "  mvPosePointClouds.size(): " << mvGlobalPointCloudsPose.size() << endl;
                        //生成一幅点云大约在0.1s左右 点云数据
                        Eigen::Isometry3d transform = convert2Eigen(mvGlobalPointCloudsPose[i]);
                        //
                        tem_cloud1 = generatePointCloud(colorImgs[i], depthImgs[i], transform);

                        if (tem_cloud1->empty()) continue;

                        *globalMap += *tem_cloud1;

                        sensor_msgs::msg::PointCloud2 local;
                        pcl::toROSMsg(*tem_cloud1, local);// 转换成ROS下的数据类型 最终通过topic发布
                        local.header.stamp = rclcpp::Clock().now();
                        local.header.frame_id = local_frame_id;
                        pub_local_pointcloud->publish(local);
                    }
                    {
                        int buff_length = 150;
                        if (i > (buff_length + 5)) {
                            cout << "i =" << i << endl;
                            // shutdown();
                            // break;
                        }
                    }
                    lastKeyframeSize = i;
                    sensor_msgs::msg::PointCloud2 output;
                    pcl::toROSMsg(*globalMap, output);
                    output.header.stamp = rclcpp::Clock().now();
                    output.header.frame_id = global_frame_id;
                    pub_global_pointcloud->publish(output);
                    cout << "show global map, size=" << globalMap->points.size() << endl;
                }
            }
        }
    }


    Eigen::Matrix4f PointCloudMapper::cvMat2Eigen(const cv::Mat &cvT) {
        Eigen::Matrix<float, 4, 4> T;
        T << cvT.at<float>(0, 0), cvT.at<float>(0, 1), cvT.at<float>(0, 2), cvT.at<float>(0, 3),
                cvT.at<float>(1, 0), cvT.at<float>(1, 1), cvT.at<float>(1, 2), cvT.at<float>(1, 3),
                cvT.at<float>(2, 0), cvT.at<float>(2, 1), cvT.at<float>(2, 2), cvT.at<float>(2, 3),
                0, 0, 0, 1;

        return T;
    }
    /**
   * @ 将深度图像映射成彩色图
   *
   */
    void PointCloudMapper::dispDepth(const cv::Mat &in, cv::Mat &out, const float maxValue) {
        cv::Mat tmp = cv::Mat(in.rows, in.cols, CV_8U);
        const uint32_t maxInt = 255;

        for (int r = 0; r < in.rows; ++r) {
            const uint16_t *itI = in.ptr<uint16_t>(r);
            uint8_t *itO = tmp.ptr<uint8_t>(r);

            for (int c = 0; c < in.cols; ++c, ++itI, ++itO) {
                *itO = (uint8_t) std::min((*itI * maxInt / maxValue), 255.0f);
            }
        }

        cv::applyColorMap(tmp, out, cv::COLORMAP_JET);
    }

    void PointCloudMapper::callback(const sensor_msgs::msg::Image::ConstSharedPtr msgRGB,
                                    const sensor_msgs::msg::Image::ConstSharedPtr msgD,
                                    const geometry_msgs::msg::PoseStamped::ConstSharedPtr tcw) {

        std::cout << "----------------------------callback" << std::endl;

        cv::Mat color, depth, depthDisp;
        geometry_msgs::msg::PoseStamped Tcw = *tcw;
        cv_bridge::CvImageConstPtr pCvImage;

        pCvImage = cv_bridge::toCvShare(msgRGB, "bgr8");
        pCvImage->image.copyTo(color);
        pCvImage = cv_bridge::toCvShare(msgD, msgD->encoding); //imageDepth->encoding
        pCvImage->image.copyTo(depth);
        // IR image input
        if (color.type() == CV_16U) {
            cv::Mat tmp;
            color.convertTo(tmp, CV_8U, 0.02);
            cv::cvtColor(tmp, color, CV_GRAY2BGR);
        }
        if (depth.type() != CV_32F)
            depth.convertTo(depth, CV_32F);

        insertKeyFrame(color, depth, Tcw);
    }

    Eigen::Isometry3d PointCloudMapper::convert2Eigen(geometry_msgs::msg::PoseStamped &Tcw) {
        Eigen::Quaterniond q = Eigen::Quaterniond(Tcw.pose.orientation.w, Tcw.pose.orientation.x,
                                                  Tcw.pose.orientation.y, Tcw.pose.orientation.z);
        Eigen::AngleAxisd V6(q);
        //  V6.fromRotationMatrix<double,3,3>(q.toRotationMatrix());
        Eigen::Isometry3d T = Eigen::Isometry3d::Identity();  // 三维变换矩阵
        T.rotate(V6);  // 旋转部分赋值
        T(0, 3) = Tcw.pose.position.x;
        T(1, 3) = Tcw.pose.position.y;
        T(2, 3) = Tcw.pose.position.z;
        return T;
    };

    void PointCloudMapper::getGlobalCloudMap(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr &outputMap) {
        unique_lock<mutex> lck_keyframeUpdated(keyFrameUpdateMutex);
        outputMap = globalMap;
    }

// 复位点云显示模块
    void PointCloudMapper::reset() {
        mvGlobalPointCloudsPose.clear();
        mvGlobalPointClouds.clear();
        mGlobalPointCloudID = 0;
        mLastGlobalPointCloudID = 0;
    }

    void PointCloudMapper::shutdown() {
        {
            unique_lock<mutex> lck(shutDownMutex);
            shutDownFlag = true;
        }
        string save_path = mNodePath + "/resultPointCloudFile.pcd";
        pcl::io::savePCDFile(save_path, *globalMap, true);
        cout << "save pcd files to :  " << save_path << endl;
    }


// -----end of namespace
}
