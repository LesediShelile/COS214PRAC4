#include "State.h"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"

#include "DeliveryComponent.h"
#include "DeliveryPhase.h"
#include "FrontendPhase.h"
#include "BackendPhase.h"
#include "DevelopmentPhase.h"
#include "UnitTestingPhase.h"
#include "TestingPhase.h"
#include "AuthenticationPhase.h"
#include "IntegrationTestingPhase.h"
#include "State.h"

#include "LoginDesign.h"
#include "CreateAPI.h"
#include "DatabaseSetUp.h"
#include "APITesting.h"
#include "LoginTesting.h"

#include "DepthFirstIterator.h"
#include "BreadthFirstIterator.h"

int main()
{
    std::cout << "====================================\n";
    std::cout << "    TASK-FORGE SOFTWARE DELIVERY\n";
    std::cout << "====================================\n";

    std::cout << CYAN << "Creating project hierarchy...\n" << RESET;
    std::cout << std::endl;
    std::cout << CYAN << "Creating Development phases...\n" << RESET;
    DeliveryPhase* PhaseCont = new DeliveryPhase("Development phases");
    std::cout << GREEN << "Parent phase containter created!\n" << RESET;

    FrontendPhase* frontEnd = new FrontendPhase();
    BackendPhase* backEnd = new BackendPhase();
    DevelopmentPhase* development = new DevelopmentPhase();
    UnitTestingPhase* unitTesting = new UnitTestingPhase();
    TestingPhase* testing = new TestingPhase();
    AuthenticationPhase* authenticate = new AuthenticationPhase();
    IntegrationTestingPhase* intergrationTesting = new IntegrationTestingPhase();

    std::cout << "Front end created!\n";
    std::cout << "Back end created!\n";
    std::cout << "development phase created!\n";
    std::cout << "unit testing phase created!\n";
    std::cout << "testing phase created!\n";
    std::cout << "authentication phase created!\n";
    std::cout << "integration testing phase created!\n";

    std::cout << CYAN << "All phases created!\n" << RESET;
    std::cout << "===================================\n";

    std::cout << CYAN << "Creating Tasks...\n" << RESET;
    LoginDesign* login = new LoginDesign();
    LoginTesting* loginTest = new LoginTesting();
    DatabaseSetUp* database = new DatabaseSetUp();
    CreateAPI* api = new CreateAPI();
    APITesting* apiTest = new APITesting();

    std::cout << "login task created!\n";
    std::cout << "login testing task created!\n";
    std::cout << "database task created!\n";
    std::cout << "api task created!\n";
    std::cout << "api testing task created!\n";

    std::cout << CYAN << "All tasks created!\n" << RESET;
    std::cout << "====================================\n";
    std::cout << CYAN << "Building hierarchy...\n" << RESET;
    std::cout << "attaching phases to parent phase container...\n";

    PhaseCont->add(frontEnd);
    PhaseCont->add(backEnd);
    PhaseCont->add(development);
    PhaseCont->add(unitTesting);
    PhaseCont->add(intergrationTesting);
    PhaseCont->add(testing);
    PhaseCont->add(authenticate);

    std::cout << "All phases added!\n";
    std::cout << std::endl;
    std::cout << "attaching tasks to respective phases...\n";

    frontEnd->add(login);
    frontEnd->add(loginTest);

    std::cout << "login design added to frontend phase.\n";
    std::cout << "login testing added to frontend phase.\n";

    backEnd->add(database);
    backEnd->add(api);
    backEnd->add(apiTest);

    std::cout << "database creation added to backend phase.\n";
    std::cout << "api creation added to backend phase.\n";
    std::cout << "api testing added to backend phase.\n";

    std::cout << GREEN << "Project hierarchy created!\n" << RESET;
    std::cout << "============================================\n";
    std::cout << CYAN << "Displaying project hierarchy: (Depth-first)\n" << RESET;

    DepthFirstIterator* d_it = new DepthFirstIterator(PhaseCont);
    d_it->first();

    while(!d_it->isDone())
    {
        d_it->current()->display();
        d_it->next();
    }

    std::cout << "=================================\n";
    std::cout << CYAN << "Displaying project hierarchy: (Breadth-first)\n" << RESET;

    BreadthFirstIterator* b_it = new BreadthFirstIterator(PhaseCont);
    b_it->first();

    while(!b_it->isDone())
    {
        b_it->current()->display();
        b_it->next();
    }

    delete d_it;
    delete b_it;
    std::cout << "=========================================\n";
    std::cout << CYAN << "Tasks begining development now:\n" << RESET;

    login->changeState(nullptr, "PLANNING");
    loginTest->changeState(login, "INPROGRESS");
    login->changeState(nullptr, "INPROGRESS");
}