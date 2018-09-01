#ifndef C_GPIO_H
#define C_GPIO_H

#include "IGPIO.h"

class CGPIO : public IGPIO
{
public:
  CGPIO(const std::string & aPinNumber);
  virtual ~CGPIO();


  int SetDirection(const std::string & aDirection) override;
  int SetValue(const std::string & aValue) override;
  int GetValue(std::string & aReturnValue) override;

private:
      int ExportGPIO() override;
      int UnexportGPIO() override;
      std::string m_PinNumber;
};

#endif
