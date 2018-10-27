#ifndef C_STATE_MANAGER_H
#define C_STATE_MANAGER_H

#include "IState.h"

#include <memory>
#include <map>
#include <string>

class CStateManager
{
public:
    typedef std::shared_ptr<IState> tStatePtr;
    typedef std::map<std::string, tStatePtr> tStates;

    void ChangeState(const std::string & aStateName);

    void AddState(tStatePtr apState);

    void RemoveState(const std::string & aStateName);

    void Clear();

    void Update();

    void HandleEvents();


private:

    tStates     mStates;
    tStatePtr   mpCurrentState;

};

#endif
