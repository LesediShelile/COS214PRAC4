#include <iostream>
#include "State.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

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

int main()
{
    std::cout << MAGENTA << "====================================\n";
    std::cout << "    TASK-FORGE SOFTWARE DELIVERY\n";
    std::cout << "====================================\n" << RESET;

    std::cout << CYAN << "Creating project hierarchy...\n" << RESET;
    std::cout << std::endl;
    std::cout << CYAN << "Creating Development phases...\n" << RESET;
    DeliveryPhase* PhaseCont = new DeliveryPhase("Development phases");
    std::cout << GREEN << "Parent phase container created!\n" << RESET;

    FrontendPhase* frontEnd = new FrontendPhase();
    BackendPhase* backEnd = new BackendPhase();
    DevelopmentPhase* development = new DevelopmentPhase();
    UnitTestingPhase* unitTesting = new UnitTestingPhase();
    TestingPhase* testing = new TestingPhase();
    AuthenticationPhase* authenticate = new AuthenticationPhase();
    IntegrationTestingPhase* intergrationTesting = new IntegrationTestingPhase();
    LoginTestingPhase* loginTestingPhase = new LoginTestingPhase();

    std::cout << "Front end created!\n";
    std::cout << "Back end created!\n";
    std::cout << "development phase created!\n";
    std::cout << "unit testing phase created!\n";
    std::cout << "testing phase created!\n";
    std::cout << "authentication phase created!\n";
    std::cout << "integration testing phase created!\n";
    std::cout << "login testing phase created!\n";

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
    testing->add(loginTestingPhase);

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

    std::cout << CYAN << "Running task operations...\n" << RESET;

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

    std::cout << GREEN << "Project hierarchy created!\n" << RESET;
    std::cout << "============================================\n";

    std::cout << CYAN << "Testing Composite functions...\n" << RESET;
    std::cout << "Number of phases: "
              << PhaseCont->childCount() << std::endl;

    std::cout << "Getting first phase:\n";
    if (PhaseCont->getChild(0) != nullptr)
    {
        PhaseCont->getChild(0)->display();
    }

    std::cout << "Testing null phase...\n";
    PhaseCont->add(nullptr);

    std::cout << "Removing authentication phase...\n";
    PhaseCont->remove(authenticate);

    std::cout << "Number of phases after removal: "
              << PhaseCont->childCount() << std::endl;

    std::cout << "Adding authentication phase back...\n";
    PhaseCont->add(authenticate);

    std::cout << "Number of phases after adding it back: "
              << PhaseCont->childCount() << std::endl;

    std::cout << "Processing frontend phase...\n";
    frontEnd->process();

    std::cout << "Processing backend phase...\n";
    backEnd->process();

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

    std::cout << "=========================================\n";
    std::cout << CYAN << "Tasks beginning development now:\n" << RESET;
    std::cout << std::endl;
    
    std::cout << "Begin implementing Login:\n";

    std::cout << "Setting login state to planning:\n";
    login->changeState(nullptr, "PLANNING");
    std::cout << std::endl;

    std::cout << "Setting login state to completed\n";
    login->changeState(nullptr, "COMPLETED");
    std::cout << std::endl;


    std::cout << "Setting login testing to in progress:\n";
    loginTest->changeState(login, "INPROGRESS");
    std::cout << std::endl;

    std::cout << "Setting login creation to delayed:\n";
    login->changeState(nullptr, "DELAYED");
    std::cout << std::endl;

    std::cout << "Setting login testing to in progress:\n";
    loginTest->changeState(login, "INPROGRESS");
    std::cout << std::endl;

    std::cout << "Setting login creation to in progress:\n";
    login->changeState(nullptr, "INPROGRESS");
    std::cout << std::endl;

    std::cout << "Setting login creation to completion:\n";
    login->changeState(nullptr, "COMPLETED");
    std::cout << std::endl;

    std::cout << "Setting login testing to delayed:\n";
    loginTest->changeState(login, "DELAYED");
    std::cout << std::endl;
  
    std::cout << "Setting login testing to in progress:\n";
    loginTest->changeState(login, "INPROGRESS");
    std::cout << std::endl;

    std::cout << "Setting login testing to completed:\n";
    loginTest->changeState(login, "COMPLETED");
    std::cout << std::endl;

    std::cout << "Trying to move completed login back to planning:\n";
    login->changeState(nullptr, "PLANNING");
    std::cout << std::endl;

    std::cout << "Trying to move completed login to delayed:\n";
    login->changeState(nullptr, "DELAYED");
    std::cout << std::endl;

    std::cout << "Trying to move completed login to in progress:\n";
    login->changeState(nullptr, "INPROGRESS");

    std::cout << "===========================================\n";
    std::cout << CYAN << "Adding priority decorations...\n" << RESET;

    PriorityDecorator* p_dec = new PriorityDecorator(frontEnd, 3);
    p_dec->process();
    p_dec->display();

    std::cout << GREEN << "decorations added!\n" << RESET;
    std::cout << CYAN << "Adding auditing decorations...\n" << RESET;

    AuditDecorator* a_dec = new AuditDecorator(frontEnd);
    a_dec->process();
    a_dec->display();

    std::cout << "Testing audit decoration again...\n";
    a_dec->process();
    a_dec->process();
    a_dec->display();

    std::cout << GREEN << "decorations added!\n" << RESET;

    std::cout << CYAN << "Testing decorator functions...\n" << RESET;

    std::cout << "Priority: " << p_dec->getPriority() << std::endl;
    std::cout << "Priority decorator child count: "
              << p_dec->childCount() << std::endl;

    if (p_dec->getChild(0) != nullptr)
    {
        std::cout << "Priority decorator first child: ";
        p_dec->getChild(0)->display();
    }

    std::cout << "Audit decorator state: "
              << a_dec->getState() << std::endl;

    std::cout << "Testing audited state change:\n";
    a_dec->changeState(nullptr, "COMPLETED");
    a_dec->printLog();

    DeliveryDecorator* emptyDecorator =
        new DeliveryDecorator(nullptr);

    std::cout << "Testing empty decorator:\n";
    emptyDecorator->process();
    emptyDecorator->display();
    std::cout << "Empty decorator state: "
              << emptyDecorator->getState() << std::endl;
    std::cout << "Empty decorator child count: "
              << emptyDecorator->childCount() << std::endl;

    if (emptyDecorator->getChild(0) == nullptr)
    {
        std::cout << "Empty decorator has no child.\n";
    }

    std::cout << "Cleaning up...\n";
    delete d_it;
    delete b_it;

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
    delete api;
    delete apiTest;
    delete database;

    std::cout << "=========================================\n";
    std::cout << MAGENTA << "Thank you for using Task-forge!\n" << RESET;
    return 0;
}