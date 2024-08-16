#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void generate_and_save_matrix_int(int N, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Unable to open file for writing: " << filename << endl;
        return;
    }

    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file << rand() % 100 << " "; // Random integers between 0 and 99
        }
        file << "\n";
    }

    file.close();
}

void generate_and_save_matrix_double(int N, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Unable to open file for writing: " << filename << endl;
        return;
    }

    srand(time(0)); // Seed for random number generation

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file << fixed << setprecision(2) << (rand() % 10000) / 100.0 << " "; // Random doubles between 0.00 and 99.99
        }
        file << "\n";
    }

    file.close();
}

template<typename T>
vector<vector<T>> read_matrix(const string& filename, int N) {
    vector<vector<T>> matrix(N, vector<T>(N));
    ifstream file(filename);
    if (!file) {
        cerr << "Unable to open file for reading: " << filename << endl;
        return matrix;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

template<typename T>
double multiply_and_save_matrices(const vector<vector<T>>& matrix1,
                                 const vector<vector<T>>& matrix2,
                                 int N,
                                 const string& output_filename) {
    vector<vector<T>> result_matrix(N, vector<T>(N, 0));

    // Measuring matrix multiplication time:
    auto start = high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start).count();
    
    ofstream file(output_filename);
    if (!file) {
        cerr << "Unable to open file for writing: " << output_filename << endl;
        return duration;
    }

    for (const auto& row : result_matrix) {
        for (const auto& value : row) {
            file << fixed << setprecision(2) << value << " ";
        }
        file << "\n";
    }

    file.close();
    return duration;
}

double calculate_median(vector<double>& times) {
    size_t size = times.size();
    sort(times.begin(), times.end());

    if (size % 2 == 0) {
        return (times[size / 2 - 1] + times[size / 2]) / 2.0;
    } else {
        return times[size / 2];
    }
}

void execute_and_measure(int N, const string& type) {
    string filename1 = "matrix_" + type + "_" + to_string(N) + "_1.txt";
    string filename2 = "matrix_" + type + "_" + to_string(N) + "_2.txt";
    string output_filename = "matrix_" + type + "_result_" + to_string(N) + ".txt";

    // Generating and saving matrices
    if (type == "int") {
        generate_and_save_matrix_int(N, filename1);
        generate_and_save_matrix_int(N, filename2);
    } else {
        generate_and_save_matrix_double(N, filename1);
        generate_and_save_matrix_double(N, filename2);
    }

    cout << "Generated matrices (" << type << ") for N=" << N << " and saved to files." << endl;

    auto matrix1 = read_matrix<double>(filename1, N);
    auto matrix2 = read_matrix<double>(filename2, N);

    vector<double> meat_times, total_times;

    ofstream times_file("execution_times.txt", ios::app);
    if (!times_file) {
        cerr << "Unable to open file for writing times." << endl;
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        auto start_total = high_resolution_clock::now();

        auto meat_time = multiply_and_save_matrices(matrix1, matrix2, N, output_filename);

        auto end_total = high_resolution_clock::now();
        auto total_time = duration_cast<nanoseconds>(end_total - start_total).count();

        double proportion_meat = static_cast<double>(meat_time) / total_time;

        meat_times.push_back(meat_time);
        total_times.push_back(total_time);

        cout << "Time for " << type << " matrix multiplication for N=" << N << " and iteration=" << i << ":" << endl;
        cout << "  Meat portion time: " << meat_time << " nanoseconds" << endl;
        cout << "  Total time: " << total_time << " nanoseconds" << endl;
        cout << "  Meat portion proportion: " << proportion_meat * 100 << "%" << endl;

        times_file << N << "," << i << "," << type << "," << meat_time << "," << total_time << "," << proportion_meat * 100 << endl;
    }
    times_file.close();

    double median_meat_time = calculate_median(meat_times);
    double median_total_time = calculate_median(total_times);

    cout << "Median Meat Time for " << type << " matrix multiplication for N=" << N << ": " << median_meat_time << " nanoseconds" << endl;
    cout << "Median Total Time for " << type << " matrix multiplication for N=" << N << ": " << median_total_time << " nanoseconds" << endl;
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};

    for (const auto& size : sizes) {
        execute_and_measure(size, "int");
        execute_and_measure(size, "double");
    }

    return 0;
}
