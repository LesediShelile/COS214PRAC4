#ifndef PRIORITYDECORATOR_H
#define PRIORITYDECORATOR_H

#include "DeliveryDecorator.h"
#include "DeliveryComponent.h"

class PriorityDecorator : public DeliveryDecorator{

    private:
        int priority;

    public:
        PriorityDecorator(DeliveryComponent* c, int priority);
        virtual ~PriorityDecorator();

        virtual void display() const;
        int getPriority() const;

};

#endif //PRIORITYDECORATOR_H
