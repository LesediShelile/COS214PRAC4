#ifndef DEVELOPMENTPHASE_H
#define DEVELOPMENTPHASE_H
#include "DeliveryPhase.h"

class DevelopmentPhase : public DeliveryPhase {

    public: 
    DevelopmentPhase();
    void process();
    void display() const;

};

#endif
