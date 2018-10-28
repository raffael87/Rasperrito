#ifndef GPIO_H
#define GPIO_H

#include "IGPIO.h"

class GPIO : public IGPIO
{
public:
    GPIO(const std::string & aPinNumber);
    virtual ~GPIO();

    /**
    IGPIO Methods.
    * /@
    */
    GPIOError SetDirection(const std::string & aDirection) override;
    GPIOError SetValue(const std::string & aValue) override;
    GPIOError GetValue(std::string & aReturnValue) override;
    GPIOError SetPWM(const std::string & aFrequency) override;
    /**
    * @/
    */

private:
    /**
    IGPIO Methods
    * /@
    */
    GPIOError ExportGPIO() override;
    GPIOError UnexportGPIO() override;
    /**
    * @ /
    */

    std::string m_PinNumber;                //!< Number of the gpio pin.
    static const std::string SystemPath;    //!< Static part of the system path.
};

#endif
