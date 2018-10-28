#include "ComponentManager.h"
#include "../../Component/SensorEcho.h"

ComponentManager::ComponentManager()
{
    
}

ComponentManager::~ComponentManager()
{
    
}

void ComponentManager::Init()
{
    mComponents.push_back(std::make_shared<Component::SensorEcho>("1", "1"));
}

void ComponentManager::Update()
{
    
}
