#include "AuthenticationPhase.h"

AuthenticationPhase::AuthenticationPhase(): DeliveryPhase("Authentication Phase")
{}

void AuthenticationPhase::process()
{
    std::cout << "Running Authentication phase..." << std::endl;
}

void AuthenticationPhase::display() const
{
    std::cout << "Authentication Phase : " << std::endl;
}