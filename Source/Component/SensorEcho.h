#ifndef SENSOR_ECHO_H
#define SENSOR_ECHO_H

#include <memory>
#include <thread>

#include "IComponent.h"
#include "IGPIO.h"
#include "../System/Component/ComponentHandler.h"
namespace Component
{
class SensorEcho : public IComponent, public ComponentHandler
{
public:
    SensorEcho(const std::string& aEchoPin, const std::string& aTriggerPin);
    
    virtual ~SensorEcho();

    virtual void DoSomething() override;
    virtual void Execute() override;
    virtual void Start();
    virtual void Stop();

protected:
    virtual double  GetDistance() const;
    virtual void    Run();
private:
    std::unique_ptr<IGPIO>      mpGPIOEcho;
    std::unique_ptr<IGPIO>      mpGPIOTrigger;
    std::thread                 mThread;
    bool                        mThreadActive;
    static const std::string    TRUE;
    static const std::string    FALSE;
};
}

#endif
