#include "robot_info/hydraulic_system_monitor.h"

HydraulicSystemMonitor::HydraulicSystemMonitor(
    const std::string &oil_temp, 
    const std::string &tank_fill_level,
    const std::string &oil_pressure)
    : hydraulic_oil_temperature(oil_temp),
      hydraulic_oil_tank_fill_level(tank_fill_level),
      hydraulic_oil_pressure(oil_pressure) 
{
}

std::vector<std::string> HydraulicSystemMonitor::grab_hydraulic_data() 
{
  return {hydraulic_oil_temperature, hydraulic_oil_tank_fill_level, hydraulic_oil_pressure};
}