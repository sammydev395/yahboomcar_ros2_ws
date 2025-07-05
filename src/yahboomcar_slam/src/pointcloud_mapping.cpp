/**
 * @function 接受RGB图像 Depth深度图像  相机位姿Tcw
 *
 * @param topicColor
 * @param topicDepth
 * @param topicTcw
 * @param cameraParamFile  
 * 修改于高翔发布的点云构建线程
 * cenruping@vip.qq.com
 */

#include <iostream>
#include <string>
#include <pcl_conversions/pcl_conversions/pcl_conversions.h>
#include "PCLMapper.h"

using namespace std;


int main(int argc, char **argv) {

    std::string cameraParamFile;

    rclcpp::init(argc, argv);
    
    if (!rclcpp::ok()) {
        cout << "ros init error..." << endl;
        return 0;
    }
    
    auto node = std::make_shared<Mapping::PointCloudMapper>();
    
    // Create executor and add node
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    
    // Start the viewer in a separate thread
    std::thread viewer_thread([node]() {
        node->viewer();
    });
    
    // Spin the node
    executor.spin();
    
    // Wait for viewer thread to finish
    viewer_thread.join();
    
    cout << "ros shutdown ..." << endl;
    rclcpp::shutdown();
    return 0;
}