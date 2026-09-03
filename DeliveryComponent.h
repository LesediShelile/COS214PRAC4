#ifndef DELIVERYCOMPONENT_H
#define DELIVERYCOMPONENT_H

class DeliveryComponent{

    public:
        
    virtual void process()=0;
    virtual void add(DeliveryComponent param)=0;
    virtual void remove(DeliveryComponent param)=0;
    virtual void display() const =0;


};

#endif