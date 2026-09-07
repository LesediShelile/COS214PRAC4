#ifndef LOGINTESTING_H
#define LOGINTESTING_H
#include "DeliveryTask.h"

class LoginTesting : public DeliveryTask {
    public:
        LoginTesting();
        void process();
        void display() const;
};

#endif