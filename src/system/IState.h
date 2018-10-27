#ifndef I_STATE_H
#define I_STATE_H

#include <string>

class IState
{
public:
    virtual ~IState() {}
    virtual void Enter() = 0;
    virtual void Exit() = 0;
    virtual void Update() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    virtual void HandleEvents() = 0;
    const std::string& GetName()
    {
        return mName;
    }
protected:
    IState(std::string aName) : mName(aName) {}
private:
    std::string mName;
};

#endif
