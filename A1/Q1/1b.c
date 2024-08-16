#include <stdio.h>
#include <time.h>

void fib_loop(int n) {
    long long a = 0, b = 1, c;
    if (n >= 1) printf("%lld ", a);
    if (n >= 2) printf("%lld ", b);
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf("%lld ", c);
        a = b;
        b = c;
    }
}

double calculate_time_1b() {
    int n = 50;
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    fib_loop(n);

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    return time_taken;
}

int main_1b() {
    double time_taken = calculate_time_1b();
    printf("Time taken by loop: %f seconds\n", time_taken);
    return 0;
}
