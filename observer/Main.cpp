#include "Termometer.h"
#include "Parent.h"

int main() {
    Termometer termometer(0, 100);
    Parent parent("Alice");

    termometer.addObserver(&parent);
    termometer.setTemperature(30);

    return 0;
}
