#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

long long fib_memo(int n, vector<long long> &memo) {
    if (n <= 1) return n;
    //check if answer already exists
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

double calculate_time_1c(){
    int n = 50;
    vector<long long> memo(n, -1);

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < n; i++) {
        cout << fib_memo(i, memo) << " ";
    }

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = end.tv_sec - start.tv_sec + (end.tv_nsec - start.tv_nsec) / 1e9;
    return time_taken;
}

int main_1c() {
    double time_taken = calculate_time_1c();
    cout << "\nTime taken by recursive with memoization: " << time_taken << " seconds" << endl;

    return 0;
}
