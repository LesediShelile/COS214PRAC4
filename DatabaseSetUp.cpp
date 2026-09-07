#include "DatabaseSetUp.h"

DatabaseSetUp::DatabaseSetUp() : DeliveryTask("Database Set up"){}

void DatabaseSetUp::process()
{
    std::cout << "Database is being set up..." << std::endl;
}

void DatabaseSetUp::display() const
{
    std::cout << "Task - Set Up Database " << std::endl;
}