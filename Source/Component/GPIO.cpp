#include "GPIO.h"

#include <fstream>
#include <iostream>
#include <sstream>

const std::string m_SystemPath = "/sys/class/gpio/";

GPIO::GPIO(const std::string & aPinNumber) : m_PinNumber(aPinNumber)
{
    ExportGPIO();
}

GPIO::~GPIO()
{
    UnexportGPIO();
}


GPIOError GPIO::ExportGPIO()
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

GPIOError GPIO::UnexportGPIO()
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

GPIOError GPIO::SetDirection(const std::string & aDirection)
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

GPIOError GPIO::SetValue(const std::string & aValue)
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

GPIOError GPIO::GetValue(std::string & aReturnValue)
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

GPIOError GPIO::SetPWM(const std::string & aFrequency)
{
    GPIOError ReturnCode = GPIOError::ERROR;

    std::string m_SystemPathPwm = "/sys/class/pwm/";

    std::string sysString = m_SystemPathPwm + "export";
    std::ofstream setExportGPIO(sysString.c_str());

    std::string periodString = m_SystemPathPwm + "pwm" + m_PinNumber + "/period";
    std::ofstream setPeriodGPIO(periodString.c_str());

    std::string enableString = m_SystemPathPwm + "pwm" + m_PinNumber + "/enable";
    std::ofstream setEnableGPIO(enableString.c_str());

    if (!setExportGPIO.is_open())
    {
        std::cout << "ERROR SetPWM (3)" << std::endl;
    }
    else if (!setPeriodGPIO.is_open())
    {
        std::cout << "ERROR SetPWM (1)" << std::endl;
    }
    else if (!setEnableGPIO.is_open())
    {
        std::cout << "ERROR SetPWM (2)" << std::endl;
    }
    else
    {
        setPeriodGPIO << aFrequency;
        setPeriodGPIO.close();

        setEnableGPIO << "1";
        setEnableGPIO.close();


        ReturnCode = GPIOError::OK;
    }

    return ReturnCode;

}
