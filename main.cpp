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
    return 0;
}