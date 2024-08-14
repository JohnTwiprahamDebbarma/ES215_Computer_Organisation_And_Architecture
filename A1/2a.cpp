#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void multiplyMatricesInt(int N) {
    int** A = new int*[N];
    int** B = new int*[N];
    int** C = new int*[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new int[N];
        B[i] = new int[N];
        C[i] = new int[N];
    }

    // Initialize matrices A and B with some values
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }
    }

    clock_t start = clock();

    // Matrix multiplication
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken by integer matrix multiplication for N=" << N << " : " << fixed << setprecision(6) << time_taken << " seconds" << endl;

    // Deallocate memory
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}

void multiplyMatricesDouble(int N) {
    double** A = new double*[N];
    double** B = new double*[N];
    double** C = new double*[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new double[N];
        B[i] = new double[N];
        C[i] = new double[N];
    }

    // Initialize matrices A and B with some values
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0.0;
        }
    }

    clock_t start = clock();

    // Matrix multiplication
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time taken by double matrix multiplication for N=" << N << " : " << fixed << setprecision(6) << time_taken << " seconds" << endl;

    // Deallocate memory
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}

int main() {
    int sizes[] = {64, 128, 256, 512, 1024};

    cout << "Matrix Multiplication with Integer Elements:" << endl;
    for (int i = 0; i < 5; ++i) {
        multiplyMatricesInt(sizes[i]);
    }

    cout << "\nMatrix Multiplication with Double Elements:" << endl;
    for (int i = 0; i < 5; ++i) {
        multiplyMatricesDouble(sizes[i]);
    }

    return 0;
}
