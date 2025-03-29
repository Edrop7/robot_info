#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"

// Constructor: adding maximum_payload and inheriting much of the code through
// RobotInfo() call
AGVRobotInfo::AGVRobotInfo(std::shared_ptr<ros::NodeHandle> node_handle,
                           const std::string &description,
                           const std::string &serial, const std::string &ip,
                           const std::string &version,
                           const std::string &payload)
                            : RobotInfo(node_handle, description, serial, ip, version),
                            maximum_payload(payload),
                            hydraulic_system_monitor("45C", "100%", "250 Bar")
{
}

// used in inheriting classes to not repeat code
void AGVRobotInfo::set_agv_fields(robotinfo_msgs::RobotInfo10Fields &msg)
{
  msg.data_field_05 = "maximum_payload: " + this->maximum_payload;
}

// Step 2: addition to grab info from HydraulicSystemMonitor subsystem
void AGVRobotInfo::set_hydraulic_fields(robotinfo_msgs::RobotInfo10Fields &msg) 
{
  std::vector<std::string> hydraulic_data = this->hydraulic_system_monitor.grab_hydraulic_data();
  msg.data_field_06 = "hydraulic_oil_temperature: " + hydraulic_data[0];
  msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulic_data[1];
  msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulic_data[2];
}

// inherits set_base_fields to populate the message with RobotInfo defaults orpassed in values
void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;

  RobotInfo::set_base_fields(msg);
  this->set_hydraulic_fields(msg); // Step 2
  this->set_agv_fields(msg);

  pub->publish(msg);

  ROS_INFO("Published robot info");
}