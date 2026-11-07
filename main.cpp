#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
using namespace std;

// use a constant and initialize it to 2 for
// the initial size of the deque.
const int INITIAL_Q_SIZE = 2;

int main() {
    srand(time(nullptr));

    // create car object to be placed in the deque
    deque<Car> myCars;

    // for loop to populate deque with car objects
    for (int i = 0; i < INITIAL_Q_SIZE; i++) {
        myCars.push_back(Car());
    }

    // display the initial queue
    cout << "Initial queue: " << endl;
    for (Car& car : myCars) {
        car.print();
    }

    // intialize the time period counter
    int timePeriod = 0;

    // continue the simulation while cars are still in the queue
    while (!myCars.empty()) {
        timePeriod++;
        cout << "\nTime: " << timePeriod;

        // generate a random number between 1 and 100
        int ranNum = rand() % 100 + 1;

        if (ranNum >= 1 && ranNum <= 55) {
            Car& frontElement = myCars.front();
            cout << " Operation: Car paid: " 
                 << "[" << frontElement.getYear()
                 << " " << frontElement.getMake()
                 << "(" << frontElement.getTransponder() << ")]";
            // remove the first car when it pays the toll
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