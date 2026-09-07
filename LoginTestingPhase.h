#ifndef LOGINTESTINGPHASE_H
#define LOGINTESTINGPHASE_H
#include "DeliveryPhase.h"

class LoginTestingPhase : public DeliveryPhase {

    public:
        LoginTestingPhase();
        void process();
        void display() const;
};

#endif