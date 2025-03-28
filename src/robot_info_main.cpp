#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;

  // modified default values to reflect data in grading rubric
  RobotInfo robotInfo(std::make_shared<ros::NodeHandle>(nh), 
                    "Mir100",
                    "567A359", 
                    "169.254.5.180", 
                    "3.5.8");

  // replaced ros::spin() as it wouldnt cycle the publish_data() method
  ros::Rate rate(1);
  while (ros::ok()) {
    robotInfo.publish_data();
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}