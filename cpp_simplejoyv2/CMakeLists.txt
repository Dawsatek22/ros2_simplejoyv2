
cmake_minimum_required(VERSION 3.25.1)
project(cpp_simplejoyv2)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# Below are the required packages.
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
#below are the required dependencies and excutables
add_executable(gsub src/gpiosub.cpp)
target_link_libraries(gsub -lwiringPi) # Links the WiringPi library to the gpsub node
ament_target_dependencies(gsub rclcpp std_msgs  )
add_executable(jsub src/joy_sub.cpp)
ament_target_dependencies(jsub rclcpp std_msgs)


add_executable(jpub src/joy_pub.cpp) 
ament_target_dependencies(jpub rclcpp std_msgs)


install(TARGETS
gsub
jpub
jsub
  DESTINATION lib/${PROJECT_NAME})




ament_package()
