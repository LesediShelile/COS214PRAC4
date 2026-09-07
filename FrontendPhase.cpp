#include "FrontendPhase.h"

FrontendPhase::FrontendPhase(): DeliveryPhase("Frontend Phase"){}

void FrontendPhase::process(){
    std::cout << "Running Frontend phase..." << std::endl;
}

void FrontendPhase::display() const{
    std::cout << "Frontend Phase : " << std::endl;
}