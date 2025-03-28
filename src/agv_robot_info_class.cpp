#include "robot_info/agv_robot_info_class.h"
#include "robot_info/robot_info_class.h"

// Constructor: adding maximum_payload and inheriting much of the code through RobotInfo() call
AGVRobotInfo::AGVRobotInfo(std::shared_ptr<ros::NodeHandle> node_handle,
                           const std::string &description,
                           const std::string &serial, const std::string &ip,
                           const std::string &version,
                           const std::string &payload)
    : RobotInfo(node_handle, description, serial, ip, version),
      maximum_payload(payload) {}

// used in inheriting classes to not repeat code
void AGVRobotInfo::set_agv_fields(robotinfo_msgs::RobotInfo10Fields &msg) {
    msg.data_field_05 = "maximum_payload: " + this->maximum_payload;
}

// inherits set_base_fields to populate the message with RobotInfo defaults or passed in values
void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;

  RobotInfo::set_base_fields(msg);
  this->set_agv_fields(msg);

  pub->publish(msg);

  ROS_INFO("Published robot info");
}