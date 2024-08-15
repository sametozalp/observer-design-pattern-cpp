#include<iostream>
#include<list>
#include<string>

using namespace std;

class Observable;

// Abstract Observer class
class Observer {
public:
    virtual void update(Observable* observable) = 0;
    virtual ~Observer() = default;
};

// Observable class that notifies observers
class Observable {
private:
    list<Observer*> observers;

public:
    virtual ~Observable() = default; // Makes the class polymorphic

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.remove(observer);
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(this);
        }
    }
};

// Termometer class derived from Observable
class Termometer : public Observable {
private:
    double temperature;
    double minTemperature;
    double maxTemperature;

    void controlTemperature() {
        notifyObservers();
    }

public:
    Termometer(double minTemperature, double maxTemperature) {
        this->minTemperature = minTemperature;
        this->maxTemperature = maxTemperature;
        this->temperature = 25;
    }

    double getTemperature() const {
        return temperature;
    }

    void setTemperature(double temperature) {
        this->temperature = temperature;

        cout << "Temperature set to: " << temperature << endl;

        controlTemperature();
    }
};

// Parent class derived from Observer
class Parent : public Observer {
private:
    string name;

public:
    Parent(string name) {
        this->name = name;
    }

    void update(Observable* observable) override {
        Termometer* term = static_cast<Termometer*>(observable); // Use static_cast now that we are sure about the type
        if (term) {
            cout << name << " said: Temperature is " << term->getTemperature() << endl;
        }
    }
};

int main() {
    Termometer termometer(0, 100);
    Parent parent("mom");

    termometer.addObserver(&parent);
    termometer.setTemperature(30);

    return 0;
}
