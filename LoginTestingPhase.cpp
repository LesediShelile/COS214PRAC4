#include "LoginTestingPhase.h"

LoginTestingPhase::LoginTestingPhase() :DeliveryPhase("Login Testing Phase"){}

void LoginTestingPhase::process(){
    std::cout << "Running login testing phase ..." << std::endl;
}

void LoginTestingPhase::display() const{
    std::cout << "Login Testing Phase : " << std::endl;
}