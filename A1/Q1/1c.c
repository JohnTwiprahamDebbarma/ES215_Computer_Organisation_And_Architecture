#include <stdio.h>
#include <time.h>

long long fib_memo(int n, long long memo[]) {
    if (n <= 1) return n;
    // Check if answer already exists:
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

double calculate_time_1c() {
    int n = 50;
    long long memo[50];
    for (int i = 0; i < n; i++) memo[i] = -1;

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < n; i++) {
        fib_memo(i, memo);
    }

    clock_gettime(CLOCK_REALTIME, &end);

    // Calculating time in nanoseconds
    double time_taken = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    return time_taken;
}

int main_1c() {
    long long time_taken = calculate_time_1c();
    printf("Time taken by recursion with memoization: %lld ns\n", time_taken);
    return 0;
}
