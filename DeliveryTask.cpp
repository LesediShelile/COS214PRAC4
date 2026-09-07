#include "DeliveryTask.h"
#include <iostream>

DeliveryTask::DeliveryTask(const std::string& name){

    this->name = name;
}

void DeliveryTask::start(){

    std::cout <<name << " :has started." <<std::endl;
}

void DeliveryTask::submitForTesting(){

    std::cout << name << ": has been submited for testing." <<std::endl;

}

void DeliveryTask::recordTestResult(){

    std::cout << name << ": test result has been recorded." <<std::endl;

}

void DeliveryTask::requestReview(){

    std::cout <<  name << ": request for review has been filed." <<std::endl;


}

void DeliveryTask::deploy() {

    std::cout << name << ": has been deployed." << std::endl;
}

void DeliveryTask::process(){

    std::cout << name << ": is being processed. " <<std::endl;
}

void DeliveryTask::display() const{

    std::cout << " - " << name << std::endl;
}

//CHANGE STATE
void DeliveryTask::setState(State* s)
{
    delete this->currentState;
    this->currentState = s;
}

bool DeliveryTask::changeState(DeliveryComponent* dependency, std::string newState)
{
    return this->currentState->handleChange(dependency, newState);
}

std::string DeliveryTask::getState() const
{
    return this->currentState->getName();
}

DeliveryTask::~DeliveryTask()
{
    delete this->currentState;
}