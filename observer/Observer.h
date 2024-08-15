#ifndef OBSERVER_H
#define OBSERVER_H

class Observable;

class Observer {
public:
    virtual void update(Observable* observable) = 0;
    virtual ~Observer() = default;
};

#endif // OBSERVER_H
