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

    // create deque to store Car objects
    deque<Car> myCars;

    // populate deque with initial cars
    for (int i = 0; i < INITIAL_Q_SIZE; i++) {
        myCars.push_back(Car());
    }

    // display the initial queue
    cout << "Initial queue: " << endl;
    for (Car& car : myCars) {
        car.print();
    }

    // initialize the time period counter
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
                 << " (" << frontElement.getTransponder() << ")]";
            // remove the first car when it pays the toll
            myCars.pop_front();
        }
        else {
            // add a car to the back of the queue
            myCars.push_back(Car());
            Car& backElement = myCars.back();
            cout << " Operation: Joined lane: "
                 << "[" << backElement.getYear()
                 << " " << backElement.getMake()
                 << " (" << backElement.getTransponder() << ")]";
        }

        // display the updated queue after each operation
        cout << "\nQueue: " << endl;

        // check if the deque is empty
        if (myCars.empty()) {
            cout << "   Empty" << endl;
        }
        else {
            // display the remaining cars in the queue
            for (Car& car : myCars) {
                car.print();
            }

        }
        
    }

    return 0;
}