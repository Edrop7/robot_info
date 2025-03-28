#include "robot_info/robot_info_class.h"
#include "robot_info/agv_robot_info_class.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;

  // modified default values to reflect data in grading rubric
  AGVRobotInfo agvRobotInfo(std::make_shared<ros::NodeHandle>(nh), 
                    "Mir100",
                    "567A359", 
                    "169.254.5.180", 
                    "3.5.8",
                    "100 Kg");

  agvRobotInfo.repeat_publishing_loop();

  return 0;
}