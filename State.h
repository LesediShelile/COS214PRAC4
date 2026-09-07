#ifndef STATE_H
#define STATE_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

#include <iostream>
#include <string>

#include "DeliveryTask.h"
#include "DeliveryComponent.h"

class DeliveryComponent;

class State
{
    public:
        State(DeliveryTask* task){this->currentTask = task;} //empty Constructor
        virtual bool handleChange(DeliveryComponent* dependency, std::string newState) = 0; //PURE VIRTUAL allows to change states
        std::string getName(){return this->name;}; //Return what the name of the state
        virtual void setState(std::string name) = 0; //Base classes will set the name
        virtual ~State(){} //virtual destructor

    protected:
        std::string name; //name of the state
        DeliveryTask* currentTask;
};

//PLANNING STATE
class Planning : public State
{
    public:
        Planning(DeliveryTask* t) : State(t){}; //Constructor
        virtual bool handleChange(DeliveryComponent* dependency, std::string newState); //implement transitions
        virtual void setState(std::string name){this->name = "PLANNING";}; //set state name
        virtual ~Planning(){}; //destructor

};

//IN PROGRESS STATE
class InProgress : public State
{
    public:
        InProgress(DeliveryTask* t) : State(t){}; //Constructor
        virtual bool handleChange(DeliveryComponent* dependency, std::string newString); //implement transitions
        virtual void setState(std::string name); //set state name
        virtual ~InProgress(){}; //destructor

};

//DELAYED STATE
class Delayed : public State
{
    public:
        Delayed(DeliveryTask* t) : State(t){}; //Constructor
        virtual bool handleChange(DeliveryComponent* dependency, std::string newState); //implement transitions
        virtual void setState(std::string name); //set state name
        virtual ~Delayed(){}; //destructor

};

//COMPLETED STATE
class Completed : public State
{
    public:
        Completed(DeliveryTask* t) : State(t){}; //Constructor
        virtual bool handleChange(DeliveryComponent* dependency, std::string newState); //implement transitions
        virtual void setState(std::string name); //set state name
        virtual ~Completed(){}; //destructor
};

#endif //STATE_H