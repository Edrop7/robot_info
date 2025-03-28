#pragma once
#include <memory> // For smart pointers, attempting as covered in C++ reinforcement class this week
#include <robotinfo_msgs/RobotInfo10Fields.h> // for the custom message type provided
#include <ros/ros.h>

class RobotInfo {
public:
  // Constructor to accept default or passed in values
  RobotInfo(std::shared_ptr<ros::NodeHandle> node_handle,
            const std::string &description = "Default Robot",
            const std::string &serial = "0000000",
            const std::string &ip = "192.168.0.1", 
            const std::string &version = "1.0.0");

  virtual void publish_data(); // will need to be modified when inherited
  void repeat_publishing_loop(); // used to replace ros::spin as it did not loop my code
  virtual void set_base_fields(robotinfo_msgs::RobotInfo10Fields &msg); // used in inherited classes

protected:
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;

  std::shared_ptr<ros::NodeHandle> nh; // smart pointer used for inheritance
  std::shared_ptr<ros::Publisher> pub; // smart pointer used for inheritance
};
