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
        virtual ~State(){} //virtual destructor

    private:
        std::string name; //name of the state
};

#endif //STATE_H