#include "CGPIO.h"

#include <fstream>
    #include <iostream>
    #include <sstream>

const std::string m_SystemPath = "/sys/class/gpio/";

CGPIO::CGPIO(const std::string & aPinNumber) : m_PinNumber(aPinNumber)
{
  ExportGPIO();
}

CGPIO::~CGPIO()
{
  UnexportGPIO();
}


GPIOError CGPIO::ExportGPIO()
{
    GPIOError ReturnCode = GPIOError::ERROR;
    const std::string sysString = m_SystemPath + "export";
    std::ofstream exportGPIO(sysString.c_str());

    if (!exportGPIO.is_open())
    {
        std::cout << "ERROR ExportGPIO()." << std::endl;
    }
    else
    {
        exportGPIO << m_PinNumber;
        exportGPIO.close();
        ReturnCode = GPIOError::OK;
    }

    return ReturnCode;
}

GPIOError CGPIO::UnexportGPIO()
{
    GPIOError ReturnCode = GPIOError::ERROR;
    std::string sysString = m_SystemPath + "unexport";
    std::ofstream unexportGPIO(sysString.c_str());

    if (!unexportGPIO.is_open())
    {
        std::cout << "ERROR UnexportGPIO()." << std::endl;
    }
    else
    {
        unexportGPIO << m_PinNumber;
        unexportGPIO.close();
        ReturnCode = GPIOError::OK;
    }

    return ReturnCode;
}

GPIOError CGPIO::SetDirection(const std::string & aDirection)
{
    GPIOError ReturnCode = GPIOError::ERROR;

    std::string directionString = m_SystemPath + "gpio" + m_PinNumber + "/direction";
    std::ofstream setDirectionGPIO(directionString.c_str());

    if (!setDirectionGPIO.is_open())
    {
        std::cout << "ERROR SetDirection()" << std::endl;
    }
    else
    {
        setDirectionGPIO << aDirection;
        setDirectionGPIO.close();
        ReturnCode = GPIOError::OK;
    }

    return ReturnCode;
}

GPIOError CGPIO::SetValue(const std::string & aValue)
{
    GPIOError ReturnCode = GPIOError::ERROR;
    std::string valueString = m_SystemPath + "gpio" + m_PinNumber + "/value";
    std::ofstream setValueGPIO(valueString.c_str());

    if (!setValueGPIO.is_open())
    {
        std::cout << "ERROR SetValue" << std::endl;
    }
    else
    {
        setValueGPIO << aValue;
        setValueGPIO.close();
        ReturnCode = GPIOError::OK;
    }

    return ReturnCode;
}

GPIOError CGPIO::GetValue(std::string & aReturnValue)
{
    GPIOError ReturnCode = GPIOError::ERROR;
    std::string valueString = m_SystemPath + "gpio" + m_PinNumber + "/value";
    std::ifstream getValueGPIO(valueString.c_str());

    if (!getValueGPIO.is_open())
    {
        std::cout << "ERROR GetValue" << std::endl;
    }
    else
    {
        getValueGPIO >> aReturnValue;

        if (aReturnValue != "0")
        {
            aReturnValue = "1";
        }

        getValueGPIO.close();
        ReturnCode = GPIOError::OK;
    }

    return ReturnCode;
}
