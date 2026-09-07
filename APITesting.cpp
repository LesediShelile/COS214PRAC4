#include "APITesting.h"

APITesting::APITesting():DeliveryTask("API Testing"){}

void APITesting::process(){
    std::cout << "Running API testing..." << std::endl;
}

void APITesting::display() const{
    std::cout << "Task - Test API " << std::endl;
}