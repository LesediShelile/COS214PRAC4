#include <iostream>
#include <string>

#include "State.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define YELLOW  "\033[33m"

#include "DeliveryComponent.h"
#include "DeliveryPhase.h"
#include "FrontendPhase.h"
#include "BackendPhase.h"
#include "DevelopmentPhase.h"
#include "UnitTestingPhase.h"
#include "TestingPhase.h"
#include "AuthenticationPhase.h"
#include "IntegrationTestingPhase.h"
#include "LoginTestingPhase.h"

#include "LoginDesign.h"
#include "CreateAPI.h"
#include "DatabaseSetUp.h"
#include "APITesting.h"
#include "LoginTesting.h"

#include "DepthFirstIterator.h"
#include "BreadthFirstIterator.h"

#include "PriorityDecorator.h"
#include "AuditDecorator.h"


// ============================================================
// HELPER FUNCTIONS
// ============================================================

void displayHierarchy(DeliveryPhase* root)
{
    std::cout << "\n";
    std::cout << CYAN
              << "========== DEPTH-FIRST HIERARCHY ==========\n"
              << RESET;

    DepthFirstIterator iterator(root);

    iterator.first();

    while (!iterator.isDone())
    {
        iterator.current()->display();
        iterator.next();
    }
}


void displayBreadthHierarchy(DeliveryPhase* root)
{
    std::cout << "\n";
    std::cout << CYAN
              << "========= BREADTH-FIRST HIERARCHY =========\n"
              << RESET;

    BreadthFirstIterator iterator(root);

    iterator.first();

    while (!iterator.isDone())
    {
        iterator.current()->display();
        iterator.next();
    }
}


DeliveryComponent* getTask(
    int choice,
    LoginDesign* login,
    LoginTesting* loginTest,
    DatabaseSetUp* database,
    CreateAPI* api,
    APITesting* apiTest)
{
    switch (choice)
    {
        case 1:
            return login;

        case 2:
            return loginTest;

        case 3:
            return database;

        case 4:
            return api;

        case 5:
            return apiTest;

        default:
            return nullptr;
    }
}


std::string getTaskName(int choice)
{
    switch (choice)
    {
        case 1:
            return "Login Design";

        case 2:
            return "Login Testing";

        case 3:
            return "Database Setup";

        case 4:
            return "Create API";

        case 5:
            return "API Testing";

        default:
            return "Unknown";
    }
}


DeliveryPhase* getPhase(
    int choice,
    DeliveryPhase* frontEnd,
    DeliveryPhase* backEnd,
    DeliveryPhase* development,
    DeliveryPhase* unitTesting,
    DeliveryPhase* intergrationTesting,
    DeliveryPhase* testing,
    DeliveryPhase* authenticate)
{
    switch (choice)
    {
        case 1:
            return frontEnd;

        case 2:
            return backEnd;

        case 3:
            return development;

        case 4:
            return unitTesting;

        case 5:
            return intergrationTesting;

        case 6:
            return testing;

        case 7:
            return authenticate;

        default:
            return nullptr;
    }
}


void showTaskMenu()
{
    std::cout << "\n";
    std::cout << YELLOW
              << "Select Task:\n"
              << RESET;

    std::cout << "1. Login Design\n";
    std::cout << "2. Login Testing\n";
    std::cout << "3. Database Setup\n";
    std::cout << "4. Create API\n";
    std::cout << "5. API Testing\n";
    std::cout << "0. Back\n";
}


void showPhaseMenu()
{
    std::cout << "\n";
    std::cout << YELLOW
              << "Select Phase:\n"
              << RESET;

    std::cout << "1. Frontend Phase\n";
    std::cout << "2. Backend Phase\n";
    std::cout << "3. Development Phase\n";
    std::cout << "4. Unit Testing Phase\n";
    std::cout << "5. Integration Testing Phase\n";
    std::cout << "6. Testing Phase\n";
    std::cout << "7. Authentication Phase\n";
    std::cout << "0. Back\n";
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    // ========================================================
    // CREATE SYSTEM
    // ========================================================

    std::cout << MAGENTA
              << "====================================\n"
              << "       TASK-FORGE SOFTWARE DELIVERY\n"
              << "====================================\n"
              << RESET;

    std::cout << CYAN
              << "\nCreating project hierarchy...\n"
              << RESET;

    DeliveryPhase* PhaseCont =
        new DeliveryPhase("Development phases");

    FrontendPhase* frontEnd =
        new FrontendPhase();

    BackendPhase* backEnd =
        new BackendPhase();

    DevelopmentPhase* development =
        new DevelopmentPhase();

    UnitTestingPhase* unitTesting =
        new UnitTestingPhase();

    TestingPhase* testing =
        new TestingPhase();

    AuthenticationPhase* authenticate =
        new AuthenticationPhase();

    IntegrationTestingPhase* intergrationTesting =
        new IntegrationTestingPhase();

    LoginTestingPhase* loginTestingPhase =
        new LoginTestingPhase();


    // ========================================================
    // CREATE TASKS
    // ========================================================

    std::cout << CYAN
              << "Creating tasks...\n"
              << RESET;

    LoginDesign* login =
        new LoginDesign();

    LoginTesting* loginTest =
        new LoginTesting();

    DatabaseSetUp* database =
        new DatabaseSetUp();

    CreateAPI* api =
        new CreateAPI();

    APITesting* apiTest =
        new APITesting();


    // ========================================================
    // BUILD COMPOSITE HIERARCHY
    // ========================================================

    std::cout << CYAN
              << "Building hierarchy...\n"
              << RESET;

    PhaseCont->add(frontEnd);
    PhaseCont->add(backEnd);
    PhaseCont->add(development);
    PhaseCont->add(unitTesting);
    PhaseCont->add(intergrationTesting);
    PhaseCont->add(testing);
    PhaseCont->add(authenticate);

    testing->add(loginTestingPhase);

    frontEnd->add(login);
    frontEnd->add(loginTest);

    backEnd->add(database);
    backEnd->add(api);
    backEnd->add(apiTest);

    std::cout << GREEN
              << "Project hierarchy successfully created!\n"
              << RESET;


    // ========================================================
    // NORMAL TASK OPERATIONS
    // ========================================================

    std::cout << CYAN
              << "\nRunning task operations...\n"
              << RESET;

    login->start();
    login->submitForTesting();
    login->recordTestResult();
    login->requestReview();
    login->deploy();

    loginTest->start();
    loginTest->submitForTesting();
    loginTest->recordTestResult();
    loginTest->requestReview();
    loginTest->deploy();

    database->start();
    database->submitForTesting();
    database->recordTestResult();
    database->requestReview();
    database->deploy();

    api->start();
    api->submitForTesting();
    api->recordTestResult();
    api->requestReview();
    api->deploy();

    apiTest->start();
    apiTest->submitForTesting();
    apiTest->recordTestResult();
    apiTest->requestReview();
    apiTest->deploy();


    // ========================================================
    // COMPOSITE DEMONSTRATION
    // ========================================================

    std::cout << "\n============================================\n";
    std::cout << CYAN
              << "COMPOSITE DEMONSTRATION\n"
              << RESET;

    std::cout << "Number of phases: "
              << PhaseCont->childCount()
              << std::endl;

    std::cout << "\nFirst phase:\n";

    if (PhaseCont->getChild(0) != nullptr)
    {
        PhaseCont->getChild(0)->display();
    }

    std::cout << "\nTesting null addition:\n";

    PhaseCont->add(nullptr);

    std::cout << "Removing authentication phase...\n";

    PhaseCont->remove(authenticate);

    std::cout << "Number of phases after removal: "
              << PhaseCont->childCount()
              << std::endl;

    std::cout << "Adding authentication phase back...\n";

    PhaseCont->add(authenticate);

    std::cout << "Number of phases: "
              << PhaseCont->childCount()
              << std::endl;

    std::cout << "\nProcessing frontend phase:\n";

    frontEnd->process();

    std::cout << "\nProcessing backend phase:\n";

    backEnd->process();


    // ========================================================
    // ITERATOR DEMONSTRATION
    // ========================================================

    displayHierarchy(PhaseCont);

    displayBreadthHierarchy(PhaseCont);


    // ========================================================
    // STATE DEMONSTRATION
    // ========================================================

    std::cout << "\n============================================\n";
    std::cout << CYAN
              << "STATE DEMONSTRATION\n"
              << RESET;

    std::cout << "\nLogin -> PLANNING\n";
    login->changeState(nullptr, "PLANNING");

    std::cout << "\nLogin -> COMPLETED\n";
    login->changeState(nullptr, "COMPLETED");

    std::cout << "\nLogin Testing -> INPROGRESS\n";
    loginTest->changeState(login, "INPROGRESS");

    std::cout << "\nLogin -> DELAYED\n";
    login->changeState(nullptr, "DELAYED");

    std::cout << "\nLogin Testing -> INPROGRESS\n";
    loginTest->changeState(login, "INPROGRESS");

    std::cout << "\nLogin -> INPROGRESS\n";
    login->changeState(nullptr, "INPROGRESS");

    std::cout << "\nLogin -> COMPLETED\n";
    login->changeState(nullptr, "COMPLETED");

    std::cout << "\nLogin Testing -> DELAYED\n";
    loginTest->changeState(login, "DELAYED");

    std::cout << "\nLogin Testing -> INPROGRESS\n";
    loginTest->changeState(login, "INPROGRESS");

    std::cout << "\nLogin Testing -> COMPLETED\n";
    loginTest->changeState(login, "COMPLETED");

    std::cout << "\nTesting invalid Login transitions:\n";

    login->changeState(nullptr, "PLANNING");
    login->changeState(nullptr, "DELAYED");
    login->changeState(nullptr, "INPROGRESS");


    // ========================================================
    // DECORATOR DEMONSTRATION
    // ========================================================

    std::cout << "\n============================================\n";
    std::cout << CYAN
              << "DECORATOR DEMONSTRATION\n"
              << RESET;

    PriorityDecorator* p_dec =
        new PriorityDecorator(frontEnd, 3);

    p_dec->process();
    p_dec->display();

    std::cout << "\nPriority: "
              << p_dec->getPriority()
              << std::endl;

    std::cout << "Priority decorator child count: "
              << p_dec->childCount()
              << std::endl;

    if (p_dec->getChild(0) != nullptr)
    {
        std::cout << "Priority decorator first child:\n";
        p_dec->getChild(0)->display();
    }


    AuditDecorator* a_dec =
        new AuditDecorator(frontEnd);

    a_dec->process();
    a_dec->display();

    a_dec->process();
    a_dec->process();

    std::cout << "\nAudit decorator state: "
              << a_dec->getState()
              << std::endl;

    std::cout << "\nTesting audit state change:\n";

    a_dec->changeState(nullptr, "COMPLETED");

    std::cout << "\nAudit log:\n";

    a_dec->printLog();


    // ========================================================
    // EMPTY DECORATOR
    // ========================================================

    DeliveryDecorator* emptyDecorator =
        new DeliveryDecorator(nullptr);

    std::cout << "\n============================================\n";
    std::cout << CYAN
              << "EMPTY DECORATOR TEST\n"
              << RESET;

    emptyDecorator->process();
    emptyDecorator->display();

    std::cout << "Empty decorator state: "
              << emptyDecorator->getState()
              << std::endl;

    std::cout << "Empty decorator child count: "
              << emptyDecorator->childCount()
              << std::endl;

    if (emptyDecorator->getChild(0) == nullptr)
    {
        std::cout << GREEN
                  << "Null handling successful.\n"
                  << RESET;
    }


    // ========================================================
    // INTERACTIVE FULL SYSTEM
    // ========================================================

    std::cout << "\n\n";
    std::cout << MAGENTA
              << "================================================\n"
              << "       TASK-FORGE INTERACTIVE SYSTEM\n"
              << "================================================\n"
              << RESET;

    int mainChoice = -1;

    while (mainChoice != 0)
    {
        std::cout << "\n";
        std::cout << MAGENTA
                  << "=============== MAIN MENU ===============\n"
                  << RESET;

        std::cout << "1. View complete project hierarchy\n";
        std::cout << "2. Depth-first traversal\n";
        std::cout << "3. Breadth-first traversal\n";
        std::cout << "4. View/process a phase\n";
        std::cout << "5. Manage tasks\n";
        std::cout << "6. Manage task states\n";
        std::cout << "7. Manage Composite hierarchy\n";
        std::cout << "8. Priority Decorator\n";
        std::cout << "9. Audit Decorator\n";
        std::cout << "10. Test empty decorator\n";
        std::cout << "0. Exit\n";

        std::cout << "\nEnter choice: ";
        std::cin >> mainChoice;


        // ====================================================
        // 1. VIEW COMPLETE HIERARCHY
        // ====================================================

        if (mainChoice == 1)
        {
            std::cout << "\n============================================\n";
            std::cout << CYAN
                      << "COMPLETE PROJECT HIERARCHY\n"
                      << RESET;

            PhaseCont->display();

            std::cout << "\nTotal top-level phases: "
                      << PhaseCont->childCount()
                      << std::endl;
        }


        // ====================================================
        // 2. DEPTH FIRST
        // ====================================================

        else if (mainChoice == 2)
        {
            displayHierarchy(PhaseCont);
        }


        // ====================================================
        // 3. BREADTH FIRST
        // ====================================================

        else if (mainChoice == 3)
        {
            displayBreadthHierarchy(PhaseCont);
        }


        // ====================================================
        // 4. PHASE MANAGEMENT
        // ====================================================

        else if (mainChoice == 4)
        {
            int phaseChoice = -1;

            while (phaseChoice != 0)
            {
                showPhaseMenu();

                std::cout << "\nEnter choice: ";
                std::cin >> phaseChoice;

                if (phaseChoice == 0)
                {
                    break;
                }

                DeliveryPhase* selectedPhase =
                    getPhase(
                        phaseChoice,
                        frontEnd,
                        backEnd,
                        development,
                        unitTesting,
                        intergrationTesting,
                        testing,
                        authenticate
                    );

                if (selectedPhase == nullptr)
                {
                    std::cout << RED
                              << "Invalid phase.\n"
                              << RESET;
                    continue;
                }

                int phaseAction = -1;

                std::cout << "\nSelected phase.\n";

                while (phaseAction != 0)
                {
                    std::cout << "\n";
                    std::cout << "1. Display phase\n";
                    std::cout << "2. Process phase\n";
                    std::cout << "3. View child count\n";
                    std::cout << "4. View first child\n";
                    std::cout << "0. Back\n";

                    std::cout << "\nEnter action: ";
                    std::cin >> phaseAction;

                    if (phaseAction == 1)
                    {
                        selectedPhase->display();
                    }
                    else if (phaseAction == 2)
                    {
                        selectedPhase->process();
                    }
                    else if (phaseAction == 3)
                    {
                        std::cout << "Child count: "
                                  << selectedPhase->childCount()
                                  << std::endl;
                    }
                    else if (phaseAction == 4)
                    {
                        if (selectedPhase->getChild(0) != nullptr)
                        {
                            selectedPhase->getChild(0)->display();
                        }
                        else
                        {
                            std::cout << "This phase has no children.\n";
                        }
                    }
                }
            }
        }


        // ====================================================
        // 5. TASK MANAGEMENT
        // ====================================================

        else if (mainChoice == 5)
        {
            int taskChoice = -1;

            while (taskChoice != 0)
            {
                showTaskMenu();

                std::cout << "\nEnter choice: ";
                std::cin >> taskChoice;

                if (taskChoice == 0)
                {
                    break;
                }

                DeliveryComponent* selectedTask =
                    getTask(
                        taskChoice,
                        login,
                        loginTest,
                        database,
                        api,
                        apiTest
                    );

                if (selectedTask == nullptr)
                {
                    std::cout << RED
                              << "Invalid task.\n"
                              << RESET;
                    continue;
                }

                std::cout << "\nSelected: "
                          << getTaskName(taskChoice)
                          << std::endl;

                int taskAction = -1;

                while (taskAction != 0)
                {
                    std::cout << "\n";
                    std::cout << "1. Display task\n";
                    std::cout << "2. Process task\n";
                    std::cout << "3. View current state\n";
                    std::cout << "4. View child count\n";
                    std::cout << "0. Back\n";

                    std::cout << "\nEnter action: ";
                    std::cin >> taskAction;

                    if (taskAction == 1)
                    {
                        selectedTask->display();
                    }
                    else if (taskAction == 2)
                    {
                        selectedTask->process();
                    }
                    else if (taskAction == 3)
                    {
                        std::cout << "Current state: "
                                  << selectedTask->getState()
                                  << std::endl;
                    }
                    else if (taskAction == 4)
                    {
                        std::cout << "Child count: "
                                  << selectedTask->childCount()
                                  << std::endl;
                    }
                }
            }
        }


        // ====================================================
        // 6. STATE MANAGEMENT
        // ====================================================

        else if (mainChoice == 6)
        {
            int taskChoice = -1;

            showTaskMenu();

            std::cout << "\nSelect task: ";
            std::cin >> taskChoice;

            DeliveryComponent* selectedTask =
                getTask(
                    taskChoice,
                    login,
                    loginTest,
                    database,
                    api,
                    apiTest
                );

            if (selectedTask == nullptr)
            {
                std::cout << RED
                          << "Invalid task.\n"
                          << RESET;

                continue;
            }

            std::string state;

            std::cout << "\nSelected task: "
                      << getTaskName(taskChoice)
                      << std::endl;

            std::cout << "Current state: "
                      << selectedTask->getState()
                      << std::endl;

            std::cout << "\nAvailable states:\n";
            std::cout << "PLANNING\n";
            std::cout << "INPROGRESS\n";
            std::cout << "DELAYED\n";
            std::cout << "COMPLETED\n";

            std::cout << "\nEnter new state: ";
            std::cin >> state;

            bool result = false;

            if (taskChoice == 2)
            {
                /*
                    Login Testing depends on Login Design.
                */

                result =
                    selectedTask->changeState(
                        login,
                        state
                    );
            }
            else
            {
                result =
                    selectedTask->changeState(
                        nullptr,
                        state
                    );
            }

            if (result)
            {
                std::cout << GREEN
                          << "State transition successful.\n"
                          << RESET;
            }
            else
            {
                std::cout << RED
                          << "State transition rejected.\n"
                          << RESET;
            }

            std::cout << "Current state: "
                      << selectedTask->getState()
                      << std::endl;
        }


        // ====================================================
        // 7. COMPOSITE MANAGEMENT
        // ====================================================

        else if (mainChoice == 7)
        {
            int compositeChoice = -1;

            while (compositeChoice != 0)
            {
                std::cout << "\n";
                std::cout << CYAN
                          << "========= COMPOSITE MANAGEMENT =========\n"
                          << RESET;

                std::cout << "1. Add Authentication phase\n";
                std::cout << "2. Remove Authentication phase\n";
                std::cout << "3. View phase count\n";
                std::cout << "4. Get phase by index\n";
                std::cout << "5. Try adding nullptr\n";
                std::cout << "0. Back\n";

                std::cout << "\nEnter choice: ";
                std::cin >> compositeChoice;

                if (compositeChoice == 1)
                {
                    PhaseCont->add(authenticate);

                    std::cout << GREEN
                              << "Authentication phase added.\n"
                              << RESET;
                }
                else if (compositeChoice == 2)
                {
                    PhaseCont->remove(authenticate);

                    std::cout << GREEN
                              << "Authentication phase removed.\n"
                              << RESET;
                }
                else if (compositeChoice == 3)
                {
                    std::cout << "Number of phases: "
                              << PhaseCont->childCount()
                              << std::endl;
                }
                else if (compositeChoice == 4)
                {
                    int index;

                    std::cout << "Enter index: ";
                    std::cin >> index;

                    if (index >= 0 &&
                        index < PhaseCont->childCount())
                    {
                        PhaseCont->getChild(index)->display();
                    }
                    else
                    {
                        std::cout << RED
                                  << "Invalid index.\n"
                                  << RESET;
                    }
                }
                else if (compositeChoice == 5)
                {
                    std::cout << "Attempting to add nullptr...\n";

                    PhaseCont->add(nullptr);

                    std::cout << GREEN
                              << "Null component handled safely.\n"
                              << RESET;
                }
            }
        }


        // ====================================================
        // 8. PRIORITY DECORATOR
        // ====================================================

        else if (mainChoice == 8)
        {
            int taskChoice;
            int priority;

            showTaskMenu();

            std::cout << "\nSelect task to decorate: ";
            std::cin >> taskChoice;

            DeliveryComponent* selectedTask =
                getTask(
                    taskChoice,
                    login,
                    loginTest,
                    database,
                    api,
                    apiTest
                );

            if (selectedTask == nullptr)
            {
                std::cout << RED
                          << "Invalid task.\n"
                          << RESET;

                continue;
            }

            std::cout << "Enter priority: ";
            std::cin >> priority;

            PriorityDecorator* priorityDecorator =
                new PriorityDecorator(
                    selectedTask,
                    priority
                );

            std::cout << "\nDecorated task:\n";

            priorityDecorator->display();

            std::cout << "\nPriority: "
                      << priorityDecorator->getPriority()
                      << std::endl;

            std::cout << "Child count through decorator: "
                      << priorityDecorator->childCount()
                      << std::endl;

            delete priorityDecorator;
        }


        // ====================================================
        // 9. AUDIT DECORATOR
        // ====================================================

        else if (mainChoice == 9)
        {
            int taskChoice;
            int auditChoice = -1;

            showTaskMenu();

            std::cout << "\nSelect task to audit: ";
            std::cin >> taskChoice;

            DeliveryComponent* selectedTask =
                getTask(
                    taskChoice,
                    login,
                    loginTest,
                    database,
                    api,
                    apiTest
                );

            if (selectedTask == nullptr)
            {
                std::cout << RED
                          << "Invalid task.\n"
                          << RESET;

                continue;
            }

            AuditDecorator* auditDecorator =
                new AuditDecorator(selectedTask);

            while (auditChoice != 0)
            {
                std::cout << "\n";
                std::cout << CYAN
                          << "=========== AUDIT MENU ===========\n"
                          << RESET;

                std::cout << "Selected task: "
                          << getTaskName(taskChoice)
                          << std::endl;

                std::cout << "Current state: "
                          << selectedTask->getState()
                          << std::endl;

                std::cout << "\n1. Change state through AuditDecorator\n";
                std::cout << "2. Display audit log\n";
                std::cout << "3. Display decorated task\n";
                std::cout << "0. Back\n";

                std::cout << "\nEnter choice: ";
                std::cin >> auditChoice;

                if (auditChoice == 1)
                {
                    std::string newState;

                    std::cout << "\nAvailable states:\n";
                    std::cout << "PLANNING\n";
                    std::cout << "INPROGRESS\n";
                    std::cout << "DELAYED\n";
                    std::cout << "COMPLETED\n";

                    std::cout << "\nEnter new state: ";
                    std::cin >> newState;

                    bool result;

                    if (taskChoice == 2)
                    {
                        result =
                            auditDecorator->changeState(
                                login,
                                newState
                            );
                    }
                    else
                    {
                        result =
                            auditDecorator->changeState(
                                nullptr,
                                newState
                            );
                    }

                    if (result)
                    {
                        std::cout << GREEN
                                  << "Transition successful.\n"
                                  << RESET;
                    }
                    else
                    {
                        std::cout << RED
                                  << "Transition failed.\n"
                                  << RESET;
                    }

                    std::cout << "Current state: "
                              << selectedTask->getState()
                              << std::endl;
                }
                else if (auditChoice == 2)
                {
                    std::cout << "\n";
                    std::cout << CYAN
                              << "============ AUDIT LOG ============\n"
                              << RESET;

                    auditDecorator->printLog();
                }
                else if (auditChoice == 3)
                {
                    auditDecorator->display();
                }
            }

            delete auditDecorator;
        }


        // ====================================================
        // 10. EMPTY DECORATOR
        // ====================================================

        else if (mainChoice == 10)
        {
            DeliveryDecorator* empty =
                new DeliveryDecorator(nullptr);

            std::cout << "\n";
            std::cout << CYAN
                      << "========= EMPTY DECORATOR TEST =========\n"
                      << RESET;

            std::cout << "Calling process():\n";
            empty->process();

            std::cout << "Calling display():\n";
            empty->display();

            std::cout << "Calling getState(): "
                      << empty->getState()
                      << std::endl;

            std::cout << "Calling childCount(): "
                      << empty->childCount()
                      << std::endl;

            std::cout << "Calling getChild(0): ";

            if (empty->getChild(0) == nullptr)
            {
                std::cout << "nullptr returned safely.\n";
            }

            delete empty;
        }


        // ====================================================
        // INVALID MENU
        // ====================================================

        else if (mainChoice != 0)
        {
            std::cout << RED
                      << "Invalid menu option.\n"
                      << RESET;
        }
    }


    // ========================================================
    // CLEANUP
    // ========================================================

    std::cout << "\n";
    std::cout << CYAN
              << "Cleaning up TaskForge...\n"
              << RESET;

    delete a_dec;
    delete p_dec;
    delete emptyDecorator;

    delete PhaseCont;

    delete frontEnd;
    delete backEnd;
    delete development;
    delete unitTesting;
    delete intergrationTesting;
    delete testing;
    delete authenticate;
    delete loginTestingPhase;

    delete login;
    delete loginTest;
    delete database;
    delete api;
    delete apiTest;

    std::cout << GREEN
              << "All objects cleaned up successfully.\n"
              << RESET;

    std::cout << "\n=========================================\n";

    std::cout << MAGENTA
              << "Thank you for using Task-Forge!\n"
              << RESET;

    return 0;
}