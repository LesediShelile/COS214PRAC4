#ifndef DELIVERYTASK_H
#define DELIVERYTASK_H
#include "DeliveryComponent.h"

class DeliveryTask : public DeliveryComponent{

    public:
        void start();
        void submitForTesting();
        void recordTestResult();
        void requestReview();
        void deploy();
        void process();
        void display()const;
    

};

#endif