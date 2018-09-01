#include "CGPIO.h"

#include <iostream>
#include <chrono>
#include <thread>

double GetDistance(IGPIO & SonarEcho, IGPIO & SonarTrigger)
{
    SonarTrigger.SetValue("1");

    std::this_thread::sleep_for(std::chrono::microseconds(100));

    SonarTrigger.SetValue("0");

    auto StartTime = std::chrono::high_resolution_clock::now();
    auto EndTime = std::chrono::high_resolution_clock::now();

    std::string Value = "0";

    while (Value == "0")
    {
      SonarEcho.GetValue(Value);
      StartTime = std::chrono::high_resolution_clock::now();
    }

    while (Value == "1")
    {
      SonarEcho.GetValue(Value);
      EndTime = std::chrono::high_resolution_clock::now();
    }

    std::chrono::duration<double> TimeElapsed = EndTime-StartTime;

    return (TimeElapsed.count() * 34300) / 2;;

}


int main()
{
  CGPIO SonarEcho("13");
  CGPIO SonarTrigger("12");

  std::cout << "SUCCESS: GPIO exported" << std::endl;

  SonarEcho.SetDirection("in");
  SonarTrigger.SetDirection("out");

  std::cout << "SUCCESS: GPIO SetDirection" << std::endl;

  int input = 0;
  while(input == 0)
  {
    //std::cin >> input;

    auto distance = GetDistance(SonarEcho, SonarTrigger);
    std::cout << "Distance: " << distance << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
