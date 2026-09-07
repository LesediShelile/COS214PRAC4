#include "TestingPhase.h"

TestingPhase::TestingPhase(): DeliveryPhase("Testing Phase"){
  
}

void TestingPhase::process()
{
    std::cout << "Testing Phase is now runnning..." << std::endl;
}

void TestingPhase::display() const{
    std::cout << "Testing Phase : " << std::endl;
}