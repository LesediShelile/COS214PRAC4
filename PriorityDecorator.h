#ifndef PRIORITYDECORATOR_H
#define PRIORITYDECORATOR_H

#include "DeliveryDecorator.h"
#include "DeliveryComponent.h"

//Concrete Decorator - adds a priority level to a delivery component
class PriorityDecorator : public DeliveryDecorator{

    private:
        int priority; //priority level attached to the component

    public:

        PriorityDecorator(DeliveryComponent* c, int priority); //Constructor
        virtual ~PriorityDecorator(); //destructor

        virtual void display() const; //display the component plus its priority
        int getPriority() const; //return the priority level

};

#endif //PRIORITYDECORATOR_H
