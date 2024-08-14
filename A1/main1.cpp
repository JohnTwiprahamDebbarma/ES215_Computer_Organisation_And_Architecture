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
    // Calculate time taken by each method
    double time_1a = calculate_time_1a();
    double time_1b = calculate_time_1b();
    double time_1c = calculate_time_1c();
    double time_1d = calculate_time_1d();

    // Calculate speedups
    cout << "Speedup of loop over recursion: " << speedup(time_1a, time_1b) << endl;
    cout << "Speedup of recursion with memoization over recursion: " << speedup(time_1a, time_1c) << endl;
    cout << "Speedup of loop with memoization over recursion: " << speedup(time_1a, time_1d) << endl;

    return 0;
}
