#ifndef ITERATOR_H
#define ITERATOR_H

class DeliveryComponent;

class Iterator{

    public:
        virtual ~Iterator(){};
        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() = 0;
        virtual DeliveryComponent* current() = 0;
};

#endif //ITERATOR_H
