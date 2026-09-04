#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>

#include "DeliveryComponent.h"

class State
{
    public:
        State(){} //empty Constructor
        virtual bool handleChange(DeliveryComponent* d) = 0; //PURE VIRTUAL allows to change states
        std::string getState(){return this->name;}; //Return what the name of the state
        virtual void setState(std::string name) = 0; //Base classes will set the name
        virtual ~State(){} //virtual destructor

    private:
        std::string name; //name of the state
};

//PLANNING STATE
class Planning : public State
{
    public:
        Planning(){}; //Constructor
        virtual bool handleChange(DeliveryComponent* D); //implement transitions
        virtual void setState(std::string name); //set state name
        virtual ~Planning(){}; //destructor

};

//IN PROGRESS STATE
class InProgress : public State
{
    public:
        InProgress(){}; //Constructor
        virtual bool handleChange(DeliveryComponent* D); //implement transitions
        virtual void setState(std::string name); //set state name
        virtual ~InProgress(){}; //destructor

};

//DELAYED STATE
class Delayed : public State
{
    public:
        Delayed(){}; //Constructor
        virtual bool handleChange(DeliveryComponent* D); //implement transitions
        virtual void setState(std::string name); //set state name
        virtual ~Delayed(){}; //destructor

};

//COMPLETED STATE
class Completed : public State
{
    public:
        Completed(){}; //Constructor
        virtual bool handleChange(DeliveryComponent* D); //implement transitions
        virtual void setState(std::string name); //set state name
        virtual ~Completed(){}; //destructor
};

#endif //STATE_H