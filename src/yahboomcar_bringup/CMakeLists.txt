cmake_minimum_required(VERSION 3.8)
project(yahboomcar_bringup)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(robot_state_publisher REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(yahboomcar_msgs REQUIRED)

# Add C++ executable
add_executable(base_node 
  src/base_node.cpp
  src/base.cpp
)
ament_target_dependencies(base_node
  rclcpp
  geometry_msgs
  nav_msgs
  tf2_ros
)
target_include_directories(base_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Install C++ executable
install(TARGETS
  base_node
  DESTINATION lib/${PROJECT_NAME}
)

# Install Python scripts
install(PROGRAMS
  scripts/Mcnamu_X3plus.py
  scripts/Mcnamu_driver.py
  scripts/calibrate_angular.py
  scripts/calibrate_linear.py
  scripts/patrol.py
  scripts/transform_utils.py
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# Install config directory
install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

# Install param and rviz directories
install(DIRECTORY param/
  DESTINATION share/${PROJECT_NAME}/param
)
install(DIRECTORY rviz/
  DESTINATION share/${PROJECT_NAME}/rviz
)

ament_package()
