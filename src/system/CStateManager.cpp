#include "CStateManager.h"

#include <iostream>

void CStateManager::ChangeState(const std::string & aStateName)
{
    auto newState = mStates.find(aStateName);
    if (newState != mStates.end())
    {
        std::cout << "CStateManager: ChangeState" << std::endl;
        if(mpCurrentState)
        {
            mpCurrentState->Exit();
        }
        mpCurrentState = newState->second;
        mpCurrentState->Enter();
    }
    else
    {
        std::cout << "CStateManager: ChangeState Error" << std::endl;
    }
}

void CStateManager::AddState(tStatePtr apState)
{
    std::cout << "CStateManager: AddState" << std::endl;

    auto newState = mStates.find(apState->GetName());
    if (newState == mStates.end())
    {
        mStates.insert(std::pair<std::string, tStatePtr>(apState->GetName(), apState));
    }
    else
    {
        std::cout << "CStateManager: AddState Error" << std::endl;
    }
}

void CStateManager::RemoveState(const std::string & aStateName)
{
    std::cout << "CStateManager: RemoveState" << std::endl;
}

void CStateManager::Clear()
{
    std::cout << "CStateManager: Clear" << std::endl;
}

void CStateManager::HandleEvents()
{
    std::cout << "CStateManager: HandleEvents" << std::endl;
}

void CStateManager::Update()
{
    HandleEvents();

    mpCurrentState->HandleEvents();
    mpCurrentState->Update();
}
