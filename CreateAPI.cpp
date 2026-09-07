#include "CreateAPI.h"

CreateAPI::CreateAPI():DeliveryTask("Create API"){}

void CreateAPI::process()
{
    std::cout << "API creation process is running ... " << std::endl;
}

void CreateAPI::display() const
{
    std::cout << "Task - Create API" << std::endl;
}