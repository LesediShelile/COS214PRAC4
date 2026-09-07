#ifndef DELIVERYTASK_H
#define DELIVERYTASK_H
#include "DeliveryComponent.h"
#include "State.h"

#include <iostream>
#include <string>

class State; // forward declaration

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
        bool changeState(DeliveryComponent* dependency, std::string trigger) override;
        std::string getState() const ;
        void setState(State* s);
        virtual ~DeliveryTask();
    
    private:
        State* currentState = new Planning(this);
};

#endif