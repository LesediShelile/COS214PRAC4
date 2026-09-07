#ifndef AUDITDECORATOR_H
#define AUDITDECORATOR_H

#include "DeliveryDecorator.h"
#include <vector>
#include <string>

class AuditDecorator : public DeliveryDecorator {
private:
    std::vector<std::string> log;
    void recordAttempt(bool success, std::string trigger, std::string beforeState);

public:
    AuditDecorator(DeliveryComponent* c);
    virtual ~AuditDecorator();

    virtual bool changeState(DeliveryComponent* dependency, std::string trigger);
    virtual void display() const;
    void printLog() const;
};

#endif //AUDITDECORATOR_H