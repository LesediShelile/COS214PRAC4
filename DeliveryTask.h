#ifndef DELIVERYTASK_H
#define DELIVERYTASK_H
#include "DeliveryComponent.h"
#include "State.h"
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
        bool changeState(DeliveryTask* dependency, std::string newState);
        State* getState(){return this->currentState;};
        void setState(State* s);
        virtual ~DeliveryTask(){delete this->currentState;};
    
    private:
        State* currentState;
};

#endif