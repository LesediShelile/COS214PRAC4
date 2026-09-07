#include "DeliveryDecorator.h"

DeliveryDecorator::DeliveryDecorator(DeliveryComponent* c){
    this->component = c;
}

DeliveryDecorator::~DeliveryDecorator(){
    delete this->component;
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

bool DeliveryDecorator::changeState(){
    return false;
}

int DeliveryDecorator::childCount(){
    if(this->component == nullptr){
        return 0;
    }
    return this->component->childCount();
}

DeliveryComponent* DeliveryDecorator::getChild(int index){
    if(this->component == nullptr){
        return nullptr;
    }
    return this->component->getChild(index);
}
