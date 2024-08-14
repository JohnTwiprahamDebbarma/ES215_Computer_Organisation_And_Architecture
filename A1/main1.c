#include <stdio.h>
#include "1a.c"
#include "1b.c"
#include "1c.c"
#include "1d.c"

// Forward declarations of the `calculate_time` functions
double calculate_time_1a();  // from 1a.c
double calculate_time_1b();  // from 1b.c
double calculate_time_1c();  // from 1c.c
double calculate_time_1d();  // from 1d.c

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
    printf("Speedup of loop over recursion: %f\n", speedup(time_1a, time_1b));
    printf("Speedup of recursion with memoization over recursion: %f\n", speedup(time_1a, time_1c));
    printf("Speedup of loop with memoization over recursion: %f\n", speedup(time_1a, time_1d));

    return 0;
}
