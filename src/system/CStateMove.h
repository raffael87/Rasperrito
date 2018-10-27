#ifndef C_STATE_MOVE_H
#define C_STATE_MOVE_H

#include "IState.h"

class CStateMove : public IState
{
public:
    CStateMove(const std::string & aName);
    virtual ~CStateMove();

    virtual void Enter();
    virtual void Exit();
    virtual void Update();
    virtual void Pause();
    virtual void Resume();
    virtual void HandleEvents();
};

#endif
