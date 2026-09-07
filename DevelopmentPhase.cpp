#include "DevelopmentPhase.h"

DevelopmentPhase::DevelopmentPhase(): DeliveryPhase("Development Phase"){}

void DevelopmentPhase::process(){
    std::cout << "Running Development Phase..." << std::endl;
}

void DevelopmentPhase::display() const{

    std::cout << "Development Phase : " << std::endl;
}