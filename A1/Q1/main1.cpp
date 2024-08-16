#include <iostream>
#include "1a.cpp"
#include "1b.cpp"
#include "1c.cpp"
#include "1d.cpp"
using namespace std;

// Forward declarations of the `calculate_time` functions
double calculate_time_1a();  // from 1a.cpp
double calculate_time_1b();  // from 1b.cpp
double calculate_time_1c();  // from 1c.cpp
double calculate_time_1d();  // from 1d.cpp

double speedup(double baseline, double other) {
    return baseline / other;
}

int main() {
    // Calculating time taken by each method:
    double time_1a = calculate_time_1a();
    double time_1b = calculate_time_1b();
    double time_1c = calculate_time_1c();
    double time_1d = calculate_time_1d();


    cout << " ********************************** " << endl;
    cout << "Time taken using recursion: " << time_1a << "seconds" << endl;
    // Calculate speedups
    cout << "Speedup of loop by keeping recursion as the baseline: " << speedup(time_1a, time_1b) << endl;
    cout << "Speedup of recursion with memoization by keeping recursion as the baseline: " << speedup(time_1a, time_1c) << endl;
    cout << "Speedup of loop with memoization by keeping recursion as the baseline: " << speedup(time_1a, time_1d) << endl;
    cout << " ********************************** " << endl;

    return 0;
}
