#ifndef FRONTENDPHASE_H
#define FRONTENDPHASE_H
#include "DeliveryPhase.h"

class FrontendPhase : public DeliveryPhase{

    public:
        FrontendPhase();
         void process();
        void display() const;
};

#endif