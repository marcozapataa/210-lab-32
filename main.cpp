#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <array>
using namespace std;


int main() {
    srand(time(nullptr));

    // create array for deque
    array<deque<Car>, 4> lanes;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            lanes[i].push_back(Car());
        }
    }

    cout << "Initial Queue: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Lane " << i + 1 << ": " << endl;
        for (Car& car : lanes[i]) {
            car.print();
        }
    }

    for (int day = 1; day <= 20; day++) {
        cout << "Time: " << day << endl;

        for (int i = 0; i < 4; i++) {
            int ranNum = rand() % 100 + 1;

            if (lanes[i].empty()) {
                if (ranNum >= 1 && ranNum <= 50) {
                    lanes[i].push_back(Car());
                }
            }
            else {
                if (ranNum >= 1 && ranNum <= 50) {
                    cout << "Lane: " << i + 1 << " Paid: ";
                    lanes[i].front().print();
                    lanes[i].pop_front();
                }
                else {
                    lanes[i].push_back(Car());

                    cout << "Lane: " << i + 1 << " Joined: ";
                    lanes[i].back().print();
                }
            }
        }
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