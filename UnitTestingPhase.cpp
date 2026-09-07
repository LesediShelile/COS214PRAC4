#include "UnitTestingPhase.h"


UnitTestingPhase::UnitTestingPhase() : DeliveryPhase("Unit Testing Phase"){}

void UnitTestingPhase::process(){
    std::cout << "Running unit testing..." << std::endl;
}

void UnitTestingPhase::display() const{
    std::cout << "Unit Testing Phase : " << std::endl;
}


