#ifndef DELIVERYPHASE_H
#define DELIVERYPHASE_H
#include "DeliveryComponent.h"
#include <vector>
#include <iostream>

class DeliveryPhase : public DeliveryComponent{
    protected:
        std::vector<DeliveryComponent*> children;
        std::string name;

    public:
        DeliveryPhase( const std::string&name);
        void process();
        void add(DeliveryComponent* phase);
        void remove(DeliveryComponent* phase);
        DeliveryComponent* getChild(int index) const;
        int childCount() const;
        void display() const ;
};

#endif