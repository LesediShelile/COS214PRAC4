#ifndef DELIVERYCOMPONENT_H
#define DELIVERYCOMPONENT_H

#include <iostream>
#include <string>

class DeliveryComponent{

    public:
        
    virtual void process()=0;
    virtual void display() const =0;
    virtual bool changeState(DeliveryComponent* dependency, std::string trigger){return false;};
    virtual std::string getState() const {return "";};
    virtual ~DeliveryComponent(){}
};

#endif