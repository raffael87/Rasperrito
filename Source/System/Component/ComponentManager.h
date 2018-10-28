//
//  ComponentManager.h
//  Rasperrito
//
//  Created by Raffael Lorenz on 28.10.18.
//  Copyright © 2018 LoRa. All rights reserved.
//

#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "IComponent.h"
#include <vector>

class ComponentManager
{
public:
    typedef std::vector<std::shared_ptr<IComponent> > tComponents;
    ComponentManager();
    virtual ~ComponentManager();
    
    virtual void Init();
    
    virtual void Update();
    
private:
    tComponents mComponents;
};
#endif // COMPONENT_MANAGER_H
