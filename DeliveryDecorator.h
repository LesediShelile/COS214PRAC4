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
        virtual int childCount() const; 
        virtual DeliveryComponent* getChild(int index) const;

    private:
        //declared and left undefined - copying a decorator would shallow copy
        //component and free it twice
        DeliveryDecorator(const DeliveryDecorator& other);
        DeliveryDecorator& operator=(const DeliveryDecorator& other);

};

#endif //DELIVERYDECORATOR_H
