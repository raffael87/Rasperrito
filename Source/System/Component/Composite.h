#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>
#include <memory>

template <typename Component>
class Composite : public Component
{
public:

    virtual ~Composite()
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
    std::vector<std::shared_ptr<Component*> > mChildren;
};

#endif // COMPOSITE_H
