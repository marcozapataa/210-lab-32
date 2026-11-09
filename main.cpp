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

    lanes[0].push_back(Car());
    lanes[0].push_back(Car());
    lanes[1].push_back(Car());
    lanes[2].push_back(Car());
    lanes[2].push_back(Car());
    lanes[2].push_back(Car());

    cout << lanes[0].size() << endl;
    cout << lanes[1].size() << endl;
    cout << lanes[2].size() << endl;
    cout << lanes[3].size() << endl;

    lanes[0].pop_front();
    lanes[1].pop_back();
    cout << lanes[3].empty() << endl;
    cout << lanes[0].empty() << endl;

    return 0;
}