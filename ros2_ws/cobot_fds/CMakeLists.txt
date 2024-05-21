cmake_minimum_required(VERSION 3.8)
project(cobot_fds)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(messages REQUIRED)


include_directories(include)


add_executable(cobot_drive_main src/fcs.cpp src/serial.cpp src/drive.cpp src/cobot_drive_main.cpp )
ament_target_dependencies(cobot_drive_main rclcpp std_msgs tf2_ros tf2 nav_msgs std_msgs geometry_msgs messages)

install(TARGETS 
  cobot_drive_main
  DESTINATION lib/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()


