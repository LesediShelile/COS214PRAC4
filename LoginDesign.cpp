#include "LoginDesign.h"

LoginDesign::LoginDesign() : DeliveryTask("Login Design"){}

void LoginDesign::process()
{
    std::cout << "Login design process is now running..." << std::endl;
}

void LoginDesign::display() const
{
    std::cout << "Task - Design Login " << std::endl;
}