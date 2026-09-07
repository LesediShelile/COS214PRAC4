#include "PriorityDecorator.h"

#include <iostream>

PriorityDecorator::PriorityDecorator(DeliveryComponent* c, int priority) : DeliveryDecorator(c){
    this->priority = priority;
}

PriorityDecorator::~PriorityDecorator(){

}

void PriorityDecorator::display() const{
    DeliveryDecorator::display();

    std::cout << "Priority: " << this->priority << std::endl;
}

int PriorityDecorator::getPriority() const{
    return this->priority;
}
