#ifndef CREATEAPI_H
#define CREATEAPI_H
#include "DeliveryTask.h"

class CreateAPI : public DeliveryTask {
    public:
        CreateAPI();
         void process();
        void display() const;
};
#endif