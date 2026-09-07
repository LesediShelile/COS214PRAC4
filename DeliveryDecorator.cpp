#include "DeliveryDecorator.h"

DeliveryDecorator::DeliveryDecorator(DeliveryComponent* c){
    this->component = c;
}

DeliveryDecorator::~DeliveryDecorator(){
    //delete this->component;
}

void DeliveryDecorator::process(){
    if(this->component != nullptr){
        this->component->process();
    }
}

void DeliveryDecorator::display() const{
    if(this->component != nullptr){
        this->component->display();
    }
}

std::string DeliveryDecorator::getState() const{
    if(this->component == nullptr){
        return "";
    }
    return this->component->getState();
}

bool DeliveryDecorator::changeState(DeliveryComponent* dependency, std::string trigger){
    if(this->component == nullptr){
        return false;
    }
    return this->component->changeState(dependency, trigger);
}

int DeliveryDecorator::childCount() const{
    if(this->component == nullptr){
        return 0;
    }
    return this->component->childCount();
}

DeliveryComponent* DeliveryDecorator::getChild(int index) const{
    if(this->component == nullptr){
        return nullptr;
    }
    return this->component->getChild(index);
}
