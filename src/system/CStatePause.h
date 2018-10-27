#ifndef C_STATE_PAUSE_H
#define C_STATE_PAUSE_H

#include "IState.h"

class CStatePause : public IState
{
public:
    CStatePause(const std::string & aName);
    virtual ~CStatePause();

    virtual void Enter();
    virtual void Exit();
    virtual void Update();
    virtual void Pause();
    virtual void Resume();
    virtual void HandleEvents();
};

#endif
