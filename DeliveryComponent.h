#ifndef DELIVERYCOMPONENT_H
#define DELIVERYCOMPONENT_H

#include <iostream>
#include <string>

class DeliveryComponent{

    public:
        virtual void process()=0;
        virtual void display() const =0;
        virtual bool changeState(DeliveryComponent*, std::string){return false;};
        virtual std::string getState() const {return "";};
        virtual ~DeliveryComponent(){}
        virtual int childCount() const { return 0; }
        virtual DeliveryComponent* getChild(int ) const { return nullptr; }
};

#endif
