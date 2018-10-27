#include "CSystem.h"
#include "CStateManager.h"
#include "CStateMove.h"
#include "CStatePause.h"

#include <iostream>

CSystem::CSystem(bool& aIsRunning) : mIsRunning(aIsRunning)
{
    mpStateManager.reset(new CStateManager());
}

CSystem::~CSystem()
{

}

void CSystem::Run()
{
    if (mInitalized)
    {
        mpStateManager->ChangeState("StateMove");
        mIsRunning = true;

        while (mIsRunning)
        {
            mpStateManager->Update();
        }

        std::cout << "Shutting all down" << std::endl;
    }
}

void CSystem::Init()
{
    mInitalized = false;

    // maybe mutex

    InitStateManager();

    mInitalized = true;
}

void CSystem::InitStateManager()
{
    std::shared_ptr<IState> pMove(new CStateMove("StateMove"));
    std::shared_ptr<IState> pPause(new CStatePause("StatePause"));

    mpStateManager->AddState(pMove);
    mpStateManager->AddState(pPause);

    mpStateManager->ChangeState("StatePause");
}
