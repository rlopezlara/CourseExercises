#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include "HeapArray.h"

using namespace std;

void load_sensor_data(HeapArray<int>& data);

int main() {
    cout << "The Sensor Analysis program\n\n";
    int num_days = 0, total_seconds = 0;

    cout << "Enter the number of days you'd like to analyze: ";
    cin >> num_days;
    cout << endl;

    const int seconds_per_day = 86400;
    total_seconds = num_days * seconds_per_day;
    HeapArray<int> data(total_seconds);
    load_sensor_data(data);

    double total = accumulate(data.begin(), data.end(), 0);
    auto min = min_element(data.begin(), data.end());
    auto max = max_element(data.begin(), data.end());

    cout << "Number of sensor readings over " << num_days
        << " days: " << data.size() << endl;
    cout << "Average reading: " << (total / data.size()) << endl;
    cout << "Lowest reading: " << *min << endl;
    cout << "Highest reading: " << *max << endl << endl;
}

void load_sensor_data(HeapArray<int>& data) { // simulate sensor data
    srand(time(nullptr));                     // seed random number
    int num, adjust;
    adjust = rand() % 70 + 10;                // generate number between 10 - 70
    for (int i = 0; i < data.size(); ++i) {
        num = rand() % 100 + 1;               // generate number between 1 - 100
        data[i] = (num < adjust) ? num + adjust : num;  // adjust number
    }
}