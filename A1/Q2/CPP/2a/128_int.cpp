#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

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

vector<vector<int>> read_matrix(const string& filename, int N) {
    vector<vector<int>> matrix(N, vector<int>(N));
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

void multiply_and_save_matrices(const vector<vector<int>>& matrix1,
                                 const vector<vector<int>>& matrix2,
                                 int N,
                                 const string& output_filename) {
    vector<vector<int>> result_matrix(N, vector<int>(N, 0));

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
            file << value << " ";
        }
        file << "\n";
    }

    file.close();
}

int main() {
    const int N = 128;

    // Generate and process integer matrices
    string filename_int1 = "matrix_int_" + to_string(N) + "_1.txt";
    string filename_int2 = "matrix_int_" + to_string(N) + "_2.txt";
    string output_filename_int = "matrix_int_result_" + to_string(N) + ".txt";

    generate_and_save_matrix_int(N, filename_int1);
    generate_and_save_matrix_int(N, filename_int2);

    cout << "Generated matrices (int) for N=" << N << " and saved to files." << endl;

    auto matrix1_int = read_matrix(filename_int1, N);
    auto matrix2_int = read_matrix(filename_int2, N);

    multiply_and_save_matrices(matrix1_int, matrix2_int, N, output_filename_int);

    cout << "Multiplication result for integer matrices of size " << N << " saved to " << output_filename_int << endl;

    return 0;
}
