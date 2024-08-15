#ifndef TERMOMETER_H
#define TERMOMETER_H

#include "Observable.h"

class Termometer : public Observable {
private:
    double temperature;
    double minTemperature;
    double maxTemperature;

    void controlTemperature();

public:
    Termometer(double minTemperature, double maxTemperature);

    double getTemperature() const;
    void setTemperature(double temperature);
};

#endif // TERMOMETER_H
