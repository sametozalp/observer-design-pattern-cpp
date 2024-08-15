#include "Parent.h"
#include <iostream>

Parent::Parent(const std::string& name) : name(name) {}

void Parent::update(Observable* observable) {
    Termometer* term = static_cast<Termometer*>(observable);
    if (term) {
        std::cout << name << " said: Temperature is " << term->getTemperature() << std::endl;
    }
}
