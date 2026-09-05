#ifndef DELIVERYPHASE_H
#define DELIVERYPHASE_H
#include "DeliveryComponent.h"
#include <vector>
#include <iostream>

class DeliveryPhase : public DeliveryComponent{
    private:
        std::vector<DeliveryComponent*> children;

    public:
        virtual void process() =0;
        virtual void add(DeliveryComponent* phase) =0;
        virtual void remove(DeliveryComponent* phase) =0;
        virtual void display() const =0;
};

#endif