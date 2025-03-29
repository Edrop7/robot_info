#pragma once
#include <vector>
#include <string>

class HydraulicSystemMonitor {
public:
  // Constructor to accept default or passed in values
  HydraulicSystemMonitor(const std::string &oil_temp = "32 C",
            const std::string &tank_fill_level = "75 %",
            const std::string &oil_pressure = "200 bar");

  std::vector<std::string> grab_hydraulic_data(); // to be used in agv_robot_info_class

private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;
};