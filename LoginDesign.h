#ifndef LOGINDESIGN_H
#define LOGINDESIGN_H
#include "DeliveryTask.h"

class LoginDesign : public DeliveryTask {
    public:
        LoginDesign();
        void process();
        void display() const;
};

#endif