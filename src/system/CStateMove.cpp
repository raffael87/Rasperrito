#include "CStateMove.h"

#include <iostream>

CStateMove::CStateMove(const std::string & aName) : IState(aName)
{

}

CStateMove::~CStateMove()
{
    std::cout << "CStateMove: ~CStateMove" << std::endl;
}

void CStateMove::CStateMove::Enter()
{
    std::cout << "CStateMove: Enter" << std::endl;
}

void CStateMove::Exit()
{
    std::cout << "CStateMove: Exit" << std::endl;
}

void CStateMove::Update()
{
    std::cout << "CStateMove: Update" << std::endl;
}

void CStateMove::Pause()
{
    std::cout << "CStateMove: Pause" << std::endl;
}

void CStateMove::Resume()
{
    std::cout << "CStateMove: Resume" << std::endl;
}

void CStateMove::HandleEvents()
{
    std::cout << "CStateMove: HandleEvents" << std::endl;
}
