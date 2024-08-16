#include <stdio.h>
#include <time.h>

long long fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

double calculate_time_1a() {
    int n = 50;
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < n; i++) {
        fib_recursive(i);
    }

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    return time_taken;
}

int main_1a() {
    double time_taken = calculate_time_1a();
    printf("Time taken by recursion: %f seconds\n", time_taken);
    return 0;
}
