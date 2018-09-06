#ifndef C_COMPOSITE_H
#define C_COMPOSITE_H

#include <vector>

template <typename Component>
class CComposite : public Component
{
public:

    virtual ~CComposite()
    {

    }

    void AddChild(Component* apChild)
    {
        if (find(mChildren.begin(), mChildren.end(), apChild) == mChildren.end())
        {
            mChildren.push_back(apChild);
        }
    }

    void RemoveChild(Component *apChild)
    {
        if (find(mChildren.begin(), mChildren.end(), apChild) != mChildren.end())
        {
            mChildren.remove(apChild);
        }
    }

    void ClearAllChildren()
    {
        mChildren.clear();
    }

protected:
    std::vector<Component*> mChildren;
};

#endif
