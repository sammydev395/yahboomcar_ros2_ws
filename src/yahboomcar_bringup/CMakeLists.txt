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

# Install param and rviz directories
install(DIRECTORY param/
  DESTINATION share/${PROJECT_NAME}/param
)
install(DIRECTORY rviz/
  DESTINATION share/${PROJECT_NAME}/rviz
)

ament_package()
