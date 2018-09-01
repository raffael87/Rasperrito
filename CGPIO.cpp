#include "CGPIO.h"

#include <fstream>
#include <iostream>
#include <sstream>

CGPIO::CGPIO(const std::string & aPinNumber) : m_PinNumber(aPinNumber)
{
  ExportGPIO();
}

CGPIO::~CGPIO()
{
  UnexportGPIO();
}


int CGPIO::ExportGPIO()
{
  std::string sysString = "/sys/class/gpio/export";
  std::ofstream exportGPIO(sysString.c_str());

  if (!exportGPIO.is_open())
  {
    std::cout << "ERROR ExportGPIO()." << std::endl;
    return -1;
  }

  exportGPIO << m_PinNumber;
  exportGPIO.close();

  return 0;
}

int CGPIO::UnexportGPIO()
{
  std::string sysString = "/sys/class/gpio/unexport";
  std::ofstream unexportGPIO(sysString.c_str());

  if (!unexportGPIO.is_open())
  {
    std::cout << "ERROR UnexportGPIO()." << std::endl;
    return -1;
  }

  unexportGPIO << m_PinNumber;
  unexportGPIO.close();

  return 0;
}

int CGPIO::SetDirection(const std::string & aDirection)
{
  std::string directionString = "/sys/class/gpio/gpio" + m_PinNumber + "/direction";
  std::ofstream setDirectionGPIO(directionString.c_str());

  if (!setDirectionGPIO.is_open())
  {
    std::cout << "ERROR SetDirection()" << std::endl;
    return -1;
  }

  setDirectionGPIO << aDirection;
  setDirectionGPIO.close();

  return 0;
}

int CGPIO::SetValue(const std::string & aValue)
{
  std::string valueString = "/sys/class/gpio/gpio" + m_PinNumber + "/value";
  std::ofstream setValueGPIO(valueString.c_str());

  if (!setValueGPIO.is_open())
  {
    std::cout << "ERROR SetValue" << std::endl;
    return -1;
  }

  setValueGPIO << aValue;
  setValueGPIO.close();

  return 0;
}

int CGPIO::GetValue(std::string & aReturnValue)
{
  std::string valueString = "/sys/class/gpio/gpio" + m_PinNumber + "/value";
  std::ifstream getValueGPIO(valueString.c_str());

  if (!getValueGPIO.is_open())
  {
    std::cout << "ERROR GetValue" << std::endl;
    return -1;
  }
  getValueGPIO >> aReturnValue;

  if(aReturnValue != "0")
  {
    aReturnValue = "1";
  }
  else
  {
    aReturnValue = "0";
  }
  getValueGPIO.close();
  return 0;
}
