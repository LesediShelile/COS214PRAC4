#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include <stack>

#include "Iterator.h"
#include "DeliveryComponent.h"

class DepthFirstIterator : public Iterator{

    private:
        DeliveryComponent* root;
        std::stack<DeliveryComponent*> nodes;
    public:

        DepthFirstIterator(DeliveryComponent* root);
        virtual ~DepthFirstIterator();

        virtual void first();
        virtual void next();
        virtual bool isDone() const;
        virtual DeliveryComponent* current() const;

};

#endif //DEPTHFIRSTITERATOR_H
