#include "SensorEcho.h"
#include "GPIO.h"

#include <iostream>
namespace Component
{
const std::string SensorEcho::TRUE = "1";
const std::string SensorEcho::FALSE = "0";

SensorEcho::SensorEcho(const std::string& aEchoPin, const std::string& aTriggerPin) : mThreadActive(false)
{
    mpGPIOEcho = std::unique_ptr<GPIO>(new GPIO(aEchoPin));
    mpGPIOTrigger = std::unique_ptr<GPIO>(new GPIO(aTriggerPin));

}

SensorEcho::~SensorEcho()
{

}

void SensorEcho::DoSomething()
{

}

void SensorEcho::Execute()
{
}

void SensorEcho::Start()
{
    if (isEnabled())
    {
        mThreadActive = true;
        mThread = std::thread (&SensorEcho::Run, this); //Move assignment
        mThread.detach();
    }
}

void SensorEcho::Stop()
{
    mThreadActive = false;
}

double SensorEcho::GetDistance() const
{
    mpGPIOTrigger->SetValue(TRUE);
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    mpGPIOTrigger->SetValue(FALSE);

    auto StartTime = std::chrono::high_resolution_clock::now();
    auto EndTime = std::chrono::high_resolution_clock::now();

    std::string Value = FALSE;

    while (Value == FALSE)
    {
      mpGPIOEcho->GetValue(Value);
      StartTime = std::chrono::high_resolution_clock::now();
    }

    while (Value == TRUE)
    {
      mpGPIOEcho->GetValue(Value);
      EndTime = std::chrono::high_resolution_clock::now();
    }

    std::chrono::duration<double> TimeElapsed = EndTime-StartTime;

    return (TimeElapsed.count() * 34300) / 2;
}

void SensorEcho::Run()
{
    while (mThreadActive)
    {
        double d = GetDistance();
        std::cout << "Distance: " << d << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
    
}
