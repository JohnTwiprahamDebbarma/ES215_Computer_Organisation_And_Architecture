#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void generate_and_save_matrix_double(int N, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Unable to open file for writing: " << filename << endl;
        return;
    }

    srand(static_cast<unsigned>(time(0))); // Seed for random number generation

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file << fixed << setprecision(2) << (rand() / (static_cast<double>(RAND_MAX) / 99.99)) << " "; // Random doubles between 0.00 and 99.99
        }
        file << "\n";
    }

    file.close();
}

vector<vector<double>> read_matrix(const string& filename, int N) {
    vector<vector<double>> matrix(N, vector<double>(N));
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

void multiply_and_save_matrices(const vector<vector<double>>& matrix1,
                                 const vector<vector<double>>& matrix2,
                                 int N,
                                 const string& output_filename) {
    vector<vector<double>> result_matrix(N, vector<double>(N, 0.0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    ofstream file(output_filename);
    if (!file) {
        cerr << "Unable to open file for writing: " << output_filename << endl;
        return;
    }

    for (const auto& row : result_matrix) {
        for (const auto& value : row) {
            file << fixed << setprecision(2) << value << " ";
        }
        file << "\n";
    }

    file.close();
}

int main() {
    const int N = 128;

    // Generate and process double matrices
    string filename_double1 = "matrix_double_" + to_string(N) + "_1.txt";
    string filename_double2 = "matrix_double_" + to_string(N) + "_2.txt";
    string output_filename_double = "matrix_double_result_" + to_string(N) + ".txt";

    generate_and_save_matrix_double(N, filename_double1);
    generate_and_save_matrix_double(N, filename_double2);

    cout << "Generated matrices (double) for N=" << N << " and saved to files." << endl;

    auto matrix1_double = read_matrix(filename_double1, N);
    auto matrix2_double = read_matrix(filename_double2, N);

    multiply_and_save_matrices(matrix1_double, matrix2_double, N, output_filename_double);

    cout << "Multiplication result for double matrices of size " << N << " saved to " << output_filename_double << endl;

    return 0;
}
