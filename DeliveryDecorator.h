#ifndef DELIVERYDECORATOR_H
#define DELIVERYDECORATOR_H

#include "DeliveryComponent.h"

class DeliveryDecorator : public DeliveryComponent{

    protected:
        DeliveryComponent* component;
    public:
        DeliveryDecorator(DeliveryComponent* c);
        virtual ~DeliveryDecorator(); 

        virtual void process();
        virtual void display() const;
        virtual bool changeState(); 
        virtual int childCount(); 
        virtual DeliveryComponent* getChild(int index);

};

#endif //DELIVERYDECORATOR_H
