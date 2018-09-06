#ifndef I_GPIO_H
#define I_GPIO_H

#include <string>

#include "RobotSystem.h"

class IGPIO
{
public:

    IGPIO()
    {}

    virtual ~IGPIO()
    {}
    /**
    * Sets direction to the path.
    * @param aDirection name of direction in sys path.
    * @return Error code.
    */
    virtual GPIOError SetDirection(const std::string & aDirection) = 0;

    /**
    * Sets value to the path.
    * @param aValue name of value in sys path.
    * @return Error code.
    */
    virtual GPIOError SetValue(const std::string & aValue) = 0;

    /**
    * Gets value from the file.
    * @param aReturnValue reference to the return value.
    * @return Error code.
    */
    virtual GPIOError GetValue(std::string & aReturnValue) = 0;

    virtual GPIOError SetPWM(const std::string & aFrequency) = 0;

private:
    /**
    * Exports pin.
    * @return Error code.
    */
    virtual GPIOError ExportGPIO() = 0;

    /**
    * Unexports pin.
    * @return Error code.
    */
    virtual GPIOError UnexportGPIO() = 0;

};

#endif
