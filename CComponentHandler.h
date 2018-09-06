#ifndef C_COMPONENT_HANDLER_H
#define C_COMPONENT_HANDLER_H

class CComponentHandler
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
    CComponentHandler() : mEnabled(true) {}

private:
    bool mEnabled;
};

#endif
