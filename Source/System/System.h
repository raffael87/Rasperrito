#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>

class ComponentManager;

class StateManager;

class System
{
public:
    static System* Instance(bool& aIsRunning);
    ~System();
        
    void Init();
    void Run();
        
protected:
    System();
    System(bool& aIsRunning);

private:
    static System*                  mpInstance;
        
    std::unique_ptr<ComponentManager>   mpComponentManager;
    bool                                mInitalized;
    bool&                               mIsRunning;
};

#endif
