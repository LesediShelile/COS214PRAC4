#ifndef TESTINGPHASE_H
#define TESTINGPHASE_H
#include "DeliveryPhase.h"

class TestingPhase : public DeliveryPhase {

    public:
        TestingPhase();
        void process();
        void display() const;

};


#endif