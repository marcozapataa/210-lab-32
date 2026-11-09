#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;

// Probabilty constants
const int PAID_CHANCE = 46;
const int JOINED_CHANCE = 39;
const int SWITCH_CHANCE = 15;
const int EMPTY_LANE_CHANCE = 50;


int main() {
    srand(time(nullptr));

    // create array containing 4 lanes
    array<deque<Car>, 4> lanes;

    // add two cars to each lane
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            lanes[i].push_back(Car());
        }
    }
    
    // display the intial cars for each lane
    cout << "Initial Queue: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Lane " << i + 1 << ": " << endl;
        for (Car& car : lanes[i]) {
            car.print();
        }
    }

    // run the simulation for 20 periods
    for (int day = 1; day <= 20; day++) {
        cout << "Time: " << day << endl;

        // temp storage for cars switching lanes
        array<deque<Car>, 4> incomingCars;

        // process the operations for all lanes
        for (int i = 0; i < 4; i++) {
            int ranNum = rand() % 100 + 1;

            // check if lane is empty
            if (lanes[i].empty()) {
                if (ranNum <= EMPTY_LANE_CHANCE) {
                    lanes[i].push_back(Car());

                    cout << "Lane: " << i + 1 << " Joined: ";
                    lanes[i].back().print();
                }
            }
            else {
                // front car pays toll and leaves
                if (ranNum <= PAID_CHANCE) {
                    cout << "Lane: " << i + 1 << " Paid: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();
                }
                // add new car to back of lane
                else if (ranNum <= PAID_CHANCE + JOINED_CHANCE) {
                    lanes[i].push_back(Car());

                    cout << "Lane: " << i + 1 << " Joined: ";
                    lanes[i].back().print();
                }
                else if (ranNum <= PAID_CHANCE + JOINED_CHANCE + SWITCH_CHANCE) {
                    int newLane = rand() % 4;

                    while (newLane == i) {
                        newLane = rand() % 4;
                    }
                    Car switchedCar = lanes[i].back();

                    // Store the car until all lanes have been processed
                    incomingCars[newLane].push_back(switchedCar);
                    lanes[i].pop_back();

                    cout << "Lane: " << i + 1
                         << " Switched to Lane: " << newLane + 1 << " ";
                    switchedCar.print();
                }
            }
        }

        // transfer cars into new lanes
        for (int i = 0; i < 4; i++) {
            while (!incomingCars[i].empty()) {
                lanes[i].push_back(incomingCars[i].front());
                incomingCars[i].pop_front();
            }
        }
        // display the new queues
        for (int i = 0; i < 4; i++) {
            cout << "Lane " << i + 1 << " Queue: ";

            if (lanes[i].empty()) {
                cout << "empty" << endl;
            }
            else {
                cout << endl;
                for (Car& car : lanes[i]) {
                    cout << "   ";
                    car.print();
                }
            }
        }
    }
    return 0;
}