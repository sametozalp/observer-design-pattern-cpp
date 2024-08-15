#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <list>
#include "Observer.h"

class Observable {
private:
    std::list<Observer*> observers;

public:
    virtual ~Observable(); // Virtual destructor

    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();
};

#endif // OBSERVABLE_H
