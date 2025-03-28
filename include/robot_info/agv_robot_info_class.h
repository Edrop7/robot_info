#pragma once
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

class AGVRobotInfo : public RobotInfo {
public:
    AGVRobotInfo(std::shared_ptr<ros::NodeHandle> node_handle,
            const std::string &description = "Default Robot",
            const std::string &serial = "0000000",
            const std::string &ip = "192.168.0.1", 
            const std::string &version = "1.0.0",
            const std::string &payload = "1 kg");
    virtual void publish_data() override;
    virtual void set_agv_fields(robotinfo_msgs::RobotInfo10Fields &msg); // used in inherited classes

protected:
    //the rest are inherited
    std::string maximum_payload;
};