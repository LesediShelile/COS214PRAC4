#include "AuditDecorator.h"

#include <iostream>

AuditDecorator::AuditDecorator(DeliveryComponent* c) : DeliveryDecorator(c){

}


AuditDecorator::~AuditDecorator(){

}

void AuditDecorator::display() const{
    DeliveryDecorator::display();

    std::cout << "Audited: " << this->log.size() << " attempt(s)" << std::endl;
}

void AuditDecorator::printLog() const{
    std::cout << "Audit log (" << this->log.size() << " attempt(s)):" << std::endl;

    for(size_t i = 0; i < this->log.size(); i++){
        std::cout << "  " << this->log[i] << std::endl;
    }
}


void AuditDecorator::recordAttempt(bool success, std::string trigger, std::string beforeState){
    std::string entry = "Attempt " + std::to_string(this->log.size() + 1) + ": ";

    entry = entry + "trigger '" + trigger + "' from " + beforeState + " - ";

    if(success){
        entry = entry + "SUCCESS";
    }else{
        entry = entry + "FAILURE";
    }

    this->log.push_back(entry);
}

bool AuditDecorator::changeState(DeliveryComponent* dependency, std::string trigger){
    std::string beforeState = "UNKNOWN";

    if(this->component != nullptr){
        beforeState = this->component->getState();
    }

    bool result = DeliveryDecorator::changeState(dependency, trigger);

    recordAttempt(result, trigger, beforeState);

    return result;
}
