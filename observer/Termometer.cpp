#include "Termometer.h"
#include <iostream>

Termometer::Termometer(double minTemperature, double maxTemperature)
    : minTemperature(minTemperature), maxTemperature(maxTemperature), temperature(25) {}

double Termometer::getTemperature() const {
    return temperature;
}

void Termometer::setTemperature(double temperature) {
    this->temperature = temperature;
    std::cout << "Temperature set to: " << temperature << std::endl;
    controlTemperature();
}

void Termometer::controlTemperature() {
    notifyObservers();
}
