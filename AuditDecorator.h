#ifndef AUDITDECORATOR_H
#define AUDITDECORATOR_H

#include "DeliveryDecorator.h"
#include <vector>
#include <string>

class AuditDecorator : public DeliveryDecorator {
private:
    std::vector<std::string> log;
    void recordAttempt(bool success);

public:
    AuditDecorator(DeliveryComponent* c);
    virtual ~AuditDecorator();

    virtual bool changeState();
    virtual void display() const;
    void printLog() const;
};

#endif //AUDITDECORATOR_H