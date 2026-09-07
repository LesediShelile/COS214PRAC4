#include "IntegrationTestingPhase.h"

IntegrationTestingPhase::IntegrationTestingPhase(): DeliveryPhase("Integration Testing Phase"){}

void IntegrationTestingPhase::process(){
    std::cout << "Integration testing is now running..." << std::endl;
}

void IntegrationTestingPhase::display() const{
    std::cout << "Integration Testing Phase : " << std::endl;
}