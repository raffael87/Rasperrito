#ifndef COMPONENT_HANDLER_H
#define COMPONENT_HANDLER_H

class ComponentHandler
{
public:
    virtual void Enable()
    {
        mEnabled = true;
    }
    virtual void Disable()
    {
        mEnabled = false;
    }

    virtual bool isEnabled() const
    {
        return mEnabled;
    }
    
protected:
    ComponentHandler() : mEnabled(true) {}

private:
    bool mEnabled;
};

#endif // COMPONENT_HANDLER_H
