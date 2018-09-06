#ifndef I_COMPONENT_H
#define I_COMPONENT_H

class IComponent
{
public:

    virtual void Execute() = 0;

    virtual void DoSomething() = 0;
};

#endif
