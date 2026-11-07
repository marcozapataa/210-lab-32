#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
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

    int timePeriod = 0;

    while (!myCars.empty()) {
        timePeriod++;
        cout << "\nTime: " << timePeriod;
        int ranNum = rand() % 100 + 1;

        if (ranNum >= 1 && ranNum <= 55) {
            myCars.pop_front();
        }
        else {
            myCars.push_back(Car());
        }

        for (Car& car : myCars) {
            car.print();
        }
    }

    return 0;
}