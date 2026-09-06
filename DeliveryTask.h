#ifndef DELIVERYTASK_H
#define DELIVERYTASK_H
#include "DeliveryComponent.h"
#include <string>


class DeliveryTask : public DeliveryComponent{

    protected:
        std::string name;

    public:

        DeliveryTask(const std::string&name);
        void start();
        void submitForTesting();
        void recordTestResult();
        void requestReview();
        void deploy();
        void process();
        void display()const;
        virtual ~DeliveryTask();
    

};

#endif