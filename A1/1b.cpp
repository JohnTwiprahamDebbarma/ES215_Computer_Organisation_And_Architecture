#include <iostream>
#include <ctime>
using namespace std;

void fib_loop(int n) {
    long long a = 0, b = 1, c;
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";
    for (int i = 2; i < n; i++) {
        c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
}

double calculate_time_1b(){
    int n = 50;
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    fib_loop(n);

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = end.tv_sec - start.tv_sec + (end.tv_nsec - start.tv_nsec) / 1e9;
    return time_taken;
}

int main_1b() {
    double time_taken = calculate_time_1b();
    cout << "\nTime taken by loop: " << time_taken << " seconds" << endl;

    return 0;
}
