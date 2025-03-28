#include "robot_info/robot_info_class.h"

// Constructor: Assigns NodeHandle (shared with smart pointer)
RobotInfo::RobotInfo(std::shared_ptr<ros::NodeHandle> node_handle,
                     const std::string &description, 
                     const std::string &serial,
                     const std::string &ip, 
                     const std::string &version)
                    : nh(node_handle), 
                    robot_description(description), 
                    serial_number(serial),
                    ip_address(ip), 
                    firmware_version(version) 
{
    pub = std::make_shared<ros::Publisher>(nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10));
}

// used in inheriting classes to not repeat code
void RobotInfo::set_base_fields(robotinfo_msgs::RobotInfo10Fields &msg) {
    msg.data_field_01 = "robot_description: " + this->robot_description;
    msg.data_field_02 = "serial_number: " + this->serial_number;
    msg.data_field_03 = "ip_address: " + this->ip_address;
    msg.data_field_04 = "firmware_version: " + this->firmware_version;
}


void RobotInfo::publish_data() 
{
  robotinfo_msgs::RobotInfo10Fields msg;

  // strings attached to reflect the grading rubric
  this->set_base_fields(msg);

  pub->publish(msg);

  ROS_INFO("Published robot info");
}