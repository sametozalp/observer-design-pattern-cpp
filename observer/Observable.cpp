#include "Observable.h"

Observable::~Observable() = default;

void Observable::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Observable::removeObserver(Observer* observer) {
    observers.remove(observer);
}

void Observable::notifyObservers() {
    for (Observer* observer : observers) {
        observer->update(this);
    }
}
