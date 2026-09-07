#include "BackendPhase.h"

BackendPhase::BackendPhase() : DeliveryPhase("Backend Phase"){}

void BackendPhase::process()
{
    std::cout << "Running Backend phase..." << std::endl;
}

void BackendPhase::display() const
{
    std::cout << "Backend Phase : " << std::endl;
}