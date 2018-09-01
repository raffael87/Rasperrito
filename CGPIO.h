#ifndef C_GPIO_H
#define C_GPIO_H

#include "IGPIO.h"

class CGPIO : public IGPIO
{
public:
    CGPIO(const std::string & aPinNumber);
    virtual ~CGPIO();

    /**
    IGPIO Methods.
    * /@
    */
    GPIOError SetDirection(const std::string & aDirection) override;
    GPIOError SetValue(const std::string & aValue) override;
    GPIOError GetValue(std::string & aReturnValue) override;
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
