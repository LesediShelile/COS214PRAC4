#include "LoginTesting.h"

LoginTesting::LoginTesting() : DeliveryTask("Login Testing"){}

void LoginTesting::process()
{
    std::cout << "Performing tests on Login functionality..." << std::endl;
}

void LoginTesting::display() const
{
    std::cout << "Task - Test Login " << std::endl;
}