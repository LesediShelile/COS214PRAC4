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
    for (int i = 0; i < children.size() ; i++)
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

    for (DeliveryComponent* component: children )
    {
        if (component != nullptr)
        {
            component->display();
        }
    }
}