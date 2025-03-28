cmake_minimum_required(VERSION 3.0.2)
project(robot_info)

find_package(catkin REQUIRED COMPONENTS
  robotinfo_msgs
  roscpp
)

catkin_package(
 INCLUDE_DIRS include
 LIBRARIES ${PROJECT_NAME}
 CATKIN_DEPENDS robotinfo_msgs roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
  src/robot_info_class.cpp
)

target_link_libraries(${PROJECT_NAME}
${catkin_LIBRARIES}
)

# base class executable
add_executable(robot_info_node src/robot_info_class.cpp src/robot_info_main.cpp)
target_link_libraries(robot_info_node ${catkin_LIBRARIES} ${PROJECT_NAME})

# agv class executable
add_executable(agv_robot_info_node src/agv_robot_info_class.cpp src/robot_info_class.cpp src/agv_robot_info_main.cpp)
target_link_libraries(agv_robot_info_node ${catkin_LIBRARIES} ${PROJECT_NAME})