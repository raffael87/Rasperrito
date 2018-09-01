#ifndef I_GPIO_H
#define I_GPIO_H

#include <string>

class IGPIO
{
public:
  virtual int SetDirection(const std::string & aDirection) = 0;
  virtual int SetValue(const std::string & aValue) = 0;
  virtual int GetValue(std::string & aReturnValue) = 0;
  
private:
  virtual int ExportGPIO() = 0;
  virtual int UnexportGPIO() = 0;

};

#endif
