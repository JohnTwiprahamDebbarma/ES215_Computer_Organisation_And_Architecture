#include <stdio.h>
#include <time.h>

void fib_loop_memo(int n) {
    long long memo[50];
    memo[0] = 0;
    memo[1] = 1;

    printf("%lld %lld ", memo[0], memo[1]);
    for (int i = 2; i < n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
        printf("%lld ", memo[i]);
    }
}

double calculate_time_1d() {
    int n = 50;
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    fib_loop_memo(n);

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    return time_taken;
}

int main_1d() {
    double time_taken = calculate_time_1d();
    printf("Time taken by loop with memoization: %f seconds\n", time_taken);
    return 0;
}
