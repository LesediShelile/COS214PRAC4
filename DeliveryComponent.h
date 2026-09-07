#ifndef DELIVERYCOMPONENT_H
#define DELIVERYCOMPONENT_H

<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> c41ffcc52a3efa86bf5a917d860f12bc7a729ef6
#include <string>

class DeliveryComponent{

    public:
        virtual void process()=0;
        virtual void display() const =0;
        virtual bool changeState(DeliveryComponent* dependency, std::string trigger){return false;};
        virtual std::string getState() const {return "";};
        virtual ~DeliveryComponent(){}
        virtual int childCount() const { return 0; }
        virtual DeliveryComponent* getChild(int index) const { return nullptr; }
};

#endif
