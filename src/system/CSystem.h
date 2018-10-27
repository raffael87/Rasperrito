#ifndef C_SYSTEM_H
#define C_SYSTEM_H

#include <memory>

class CStateManager;

class CSystem
{
public:
    CSystem(bool& aIsRunning);
    ~CSystem();

    void Init();

    void Run();

private:
    void InitStateManager();

    std::unique_ptr<CStateManager>  mpStateManager;
    bool                            mInitalized;
    bool&                           mIsRunning;
};

#endif
