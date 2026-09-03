#ifndef DELIVERYPHASE_H
#define DELIVERYPHASE_H
#include "DeliveryComponent.h"
#include <vector>
#include <iostream>

class DeliveryPhase : public DeliveryComponent{
    private:
        std::vector<DeliveryComponent*> children;

    public:
        virtual void process();
        virtual void add(DeliveryComponent* phase);
        virtual void remove(DeliveryComponent* phase);
        virtual void display() const;
};

#endif