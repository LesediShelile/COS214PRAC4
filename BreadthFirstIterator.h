#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include <queue>

#include "Iterator.h"
#include "DeliveryComponent.h"

class BreadthFirstIterator : public Iterator{

    private:
        DeliveryComponent* root; 
        std::queue<DeliveryComponent*> nodes; 

    public:

        BreadthFirstIterator(DeliveryComponent* root);
        virtual ~BreadthFirstIterator();

        virtual void first(); 
        virtual void next();
        virtual bool isDone() const;
        virtual DeliveryComponent* current() const;

};

#endif //BREADTHFIRSTITERATOR_H
