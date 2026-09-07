#include "DeliveryPhase.h"
#include <iostream>

DeliveryPhase::DeliveryPhase(const std::string& name)
{
    this->name = name;
}

void DeliveryPhase::add(DeliveryComponent* component)
{
    if (component != nullptr)
    {


        children.push_back(component) ;
    }
}

void DeliveryPhase::remove(DeliveryComponent* component)
{
    int size = children.size();
    for (int i = 0; i < size ; i++)
    {
        if (children[i] ==   component)


        {
            children.erase(children.begin() +i);
            return;
        }
    }
}

void DeliveryPhase::process()
{
    for (DeliveryComponent* component: children)
    {
        if (component != nullptr)
        {
            component->process();
        }
    }
}

void DeliveryPhase::display() const
{
    std::cout << name << std::endl;
}

int DeliveryPhase::childCount() const {
    return children.size();
}

DeliveryComponent* DeliveryPhase::getChild(int index) const{
    return children[index];
}