#ifndef PARENT_H
#define PARENT_H

#include "Observer.h"
#include "Termometer.h"
#include <string>

class Parent : public Observer {
private:
    std::string name;

public:
    Parent(const std::string& name);

    void update(Observable* observable) override;
};

#endif // PARENT_H
