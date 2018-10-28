#include "System.h"
#include "Component/ComponentManager.h"

#include <iostream>

System* System::mpInstance = nullptr;

System* System::Instance(bool& aIsRunning)
{
    if (mpInstance == nullptr)
    {
        mpInstance = new System(aIsRunning);
    }
    
    return mpInstance;
}

System::System(bool& aIsRunning) : mIsRunning(aIsRunning)
{
    mpComponentManager = std::make_unique<ComponentManager>();
}

System::~System()
{
    
}

void System::Run()
{
    if (mInitalized)
    {
        mIsRunning = true;

        while (mIsRunning)
        {
            mpComponentManager->Update();
        }

        std::cout << "Shutting all down" << std::endl;
    }
}

void System::Init()
{
    mInitalized = false;

    mpComponentManager->Init();

    mInitalized = true;
    
    std::cout << "System: Init finished successfully" << std::endl;
}
