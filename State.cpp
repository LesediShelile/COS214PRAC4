#include "State.h"
#include "DeliveryTask.h"

bool Planning::handleChange(DeliveryComponent* dependency, std::string newState)
{
    if(newState == "COMPLETED")
    {
        std::cout << RED << "Invalid State transition: Cannot move from Planning to Completed.\n" << RESET;
        return false;
    }
    if(newState == "DELAYED")
    {
        std::cout << CYAN << "Switching State from planning to delayed.\n" << RESET;
        this->currentTask->setState(new Delayed(currentTask));
        return true;
    }

    if(newState == "PLANNING")
    {
        std::cout << CYAN << "Current State is already planning.\n" << RESET;
        return false;
    }

    if(dependency != NULL)
    {
        if(newState == "INPROGRESS" && dependency->getState() == "COMPLETED")
        {
            std::cout << GREEN << "Switching State from planning to In progress.\n" << RESET;
            this->currentTask->setState(new InProgress(currentTask));
            return true;
        }
        if(newState == "INPROGRESS" && dependency->getState() == "PLANNING")
        {
            std::cout << RED << "Invalid State Transition: Cannot switch state to in progress while dependent is still in planning\n" << RESET;
            return false;
        }
        if(newState == "INPROGRESS" && dependency->getState() == "DELAYED")
        {
            std::cout << RED << "Invalid State Transition: Cannot switch state to in progress while dependent is still delayed\n" << RESET;
            return false;
        }
    }
    if(newState == "INPROGRESS" && dependency == NULL)
    {
        std::cout << GREEN << "Switching State from planning to In progress.\n" << RESET;
        this->currentTask->setState(new InProgress(currentTask));
        return true;
    }
    std::cout << RED << "An Error has occured.\n" << RESET;
    return false;
}

bool Delayed::handleChange(DeliveryComponent* dependency, std::string newState)
{
    if(newState == "COMPLETED")
    {
        std::cout << RED << "Invalid State Transition: Cannot move from Delayed to Completed\n" << RESET;
        return false;
    }
    if(newState == "PLANNING")
    {
        std::cout << RED << "Invalid State Transition: Cannot move from delayed back to planning\n" << RESET;
        return false;
    }
    if(newState == "DELAYED")
    {
        std::cout << CYAN << "Current State is already delayed\n" << RESET;
        return false;
    }
    if(dependency != NULL)
    {
        if(newState == "INPROGRESS" && dependency->getState() == "PLANNING")
        {
            std::cout << RED << "Invalid State Transition: Cannot switch state to in progress while dependency is still in planning\n" << RESET;
            return false;
        }
        if(newState == "INPROGRESS" && dependency->getState() == "DELAYED")
        {
            std::cout << RED << "Invalid State Transition: Cannot switch state to in progress while dependency is delayed\n" << RESET;
            return false;
        }
        if(newState == "INPROGRESS" && dependency->getState() == "COMPLETED")
        {
            std::cout << GREEN << "Switching State from Delayed to in progress\n" << RESET;
            this->currentTask->setState(new InProgress(currentTask));
            return true;
        }
    }
    if(newState == "INPROGRESS" && dependency == NULL)
    {
        std::cout << GREEN << "Switching State from Delayed to In progress.\n" << RESET;
        this->currentTask->setState(new InProgress(currentTask));
        return true;
    }
    std::cout << RED << "An Error Occured\n" << RESET;
    return false;
}

bool InProgress::handleChange(DeliveryComponent* dependency, std::string newState)
{
    if(newState == "COMPLETED")
    {
        std::cout << GREEN << "Switching state from in progress to completed\n" << RESET;
        this->currentTask->setState(new Completed(currentTask));
        return true;
    }
    if(newState == "DELAYED")
    {
        std::cout << GREEN << "Switching state from in progress to delayed\n" << RESET;
        this->currentTask->setState(new Delayed(currentTask));
        return true;
    }
    if(newState == "PLANNING")
    {
        std::cout << RED << "Invalid state transition: cannot switch state from in progress to planning\n" << RESET;
        return false;
    }
    if(newState == "INPROGRESS")
    {
        std::cout << CYAN << "Current State is already in progress\n" << RESET;
        return false;
    }
    std::cout << RED << "An Error occured.\n" << RESET;
    return false;
}

bool Completed::handleChange(DeliveryComponent* dependency, std::string newState)
{
        if(newState == "COMPLETED")
    {
        std::cout << CYAN << "Current State is already completed\n" << RESET;
        return false;
    }
    if(newState == "DELAYED")
    {
        std::cout << RED << "Invalid State transition: cannot switch state from completed to delayed\n" << RESET;
        return false;
    }
    if(newState == "PLANNING")
    {
        std::cout << RED << "Invalid state transition: cannot switch state from completed to planning\n" << RESET;
        return false;
    }
    if(newState == "INPROGRESS")
    {
        std::cout << RED << "Invalid State Transition: cannot switch state from completed to in progress\n" << RESET;
        return false;
    }
    std::cout << RED << "An Error occured.\n" << RESET;
    return false;
}