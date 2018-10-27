#include "CStatePause.h"

#include <iostream>

CStatePause::CStatePause(const std::string & aName) : IState(aName)
{

}

CStatePause::~CStatePause()
{
    std::cout << "CStatePause: ~CStatePause" << std::endl;
}

void CStatePause::CStatePause::Enter()
{
    std::cout << "CStatePause: Enter" << std::endl;
}

void CStatePause::Exit()
{
    std::cout << "CStatePause: Exit" << std::endl;
}

void CStatePause::Update()
{
    std::cout << "CStatePause: Update" << std::endl;
}

void CStatePause::Pause()
{
    std::cout << "CStatePause: Pause" << std::endl;
}

void CStatePause::Resume()
{
    std::cout << "CStatePause: Resume" << std::endl;
}

void CStatePause::HandleEvents()
{
    std::cout << "CStatePause: HandleEvents" << std::endl;
}
