#include "AuditDecorator.h"

#include <iostream>

AuditDecorator::AuditDecorator(DeliveryComponent* c) : DeliveryDecorator(c){

}


AuditDecorator::~AuditDecorator(){

}

void AuditDecorator::display() const{
    DeliveryDecorator::display();

    printLog();
}

//print every attempt recorded against the wrapped component
void AuditDecorator::printLog() const{
    std::cout << "Audit log (" << this->log.size() << " attempt(s)):" << std::endl;

    for(size_t i = 0; i < this->log.size(); i++){
        std::cout << "  " << this->log[i] << std::endl;
    }
}

void AuditDecorator::recordAttempt(bool success){
    std::string entry = "Attempt " + std::to_string(this->log.size() + 1) + ": ";

    if(success){
        entry = entry + "SUCCESS";
    }else{
        entry = entry + "FAILURE";
    }

    this->log.push_back(entry);
}
