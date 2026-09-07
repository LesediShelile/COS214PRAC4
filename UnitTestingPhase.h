#ifndef UNITTESTINGPHASE_H
#define UNITTESTINGPHASE_H
#include "DeliveryPhase.h"

class UnitTestingPhase : public DeliveryPhase {

    public:
    UnitTestingPhase();
    void process();
    void display() const;
};

#endif