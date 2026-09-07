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
        virtual std::string getState() const;
        virtual bool changeState(DeliveryComponent* dependency, std::string trigger); 
        virtual int childCount() const; 
        virtual DeliveryComponent* getChild(int index) const;

    private:
        DeliveryDecorator(const DeliveryDecorator& other);
        DeliveryDecorator& operator=(const DeliveryDecorator& other);

};

#endif //DELIVERYDECORATOR_H
