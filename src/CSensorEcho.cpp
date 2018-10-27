#include "CSensorEcho.h"
#include "CGPIO.h"

#include <iostream>

const std::string CSensorEcho::TRUE = "1";
const std::string CSensorEcho::FALSE = "0";

CSensorEcho::CSensorEcho(const std::string& aEchoPin, const std::string& aTriggerPin) : mThreadActive(false)
{
    mpGPIOEcho = std::unique_ptr<CGPIO>(new CGPIO(aEchoPin));
    mpGPIOTrigger = std::unique_ptr<CGPIO>(new CGPIO(aTriggerPin));

}

CSensorEcho::~CSensorEcho()
{

}

void CSensorEcho::DoSomething()
{

}

void CSensorEcho::Execute()
{
}

void CSensorEcho::Start()
{
    if (isEnabled())
    {
        mThreadActive = true;
        mThread = std::thread (&CSensorEcho::Run, this); //Move assignment
        mThread.detach();
    }
}

void CSensorEcho::Stop()
{
    mThreadActive = false;
}

double CSensorEcho::GetDistance() const
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

void CSensorEcho::Run()
{
    while (mThreadActive)
    {
        double d = GetDistance();
        std::cout << "Distance: " << d << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
