#include "Car.h"
#include <iostream>
#include <deque>
using namespace std;

const int INITIAL_Q_SIZE = 2;

int main() {
    deque<Car> myCars;

    for (int i = 0; i < INITIAL_Q_SIZE; i++) {
        myCars.push_back(Car());
    }

    for (Car& car : myCars) {
        car.print();
    }

    return 0;
}