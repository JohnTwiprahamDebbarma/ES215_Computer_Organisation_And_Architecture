import random
import numpy as np

def generate_and_save_matrix_double(N, filename):
    with open(filename, 'w') as file:
        for i in range(N):
            row = [str(round(random.uniform(0, 99.99), 2)) for _ in range(N)]  # Random doubles between 0.00 and 99.99
            file.write(" ".join(row) + "\n")
            

def read_matrix(filename, N, dtype=float):
    matrix = np.zeros((N, N), dtype=dtype)
    with open(filename, 'r') as file:
        for i, line in enumerate(file):
            matrix[i] = np.array(line.split(), dtype=dtype)
    return matrix

def multiply_and_save_matrices(matrix1, matrix2, N, output_filename, dtype=float):
    result_matrix = np.zeros((N, N), dtype=dtype)
    
    for i in range(N):
        for j in range(N):
            for k in range(N):
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j]
    
    # Writing the result to a file
    with open(output_filename, 'w') as file:
        for row in result_matrix:
            file.write(" ".join(map(str, row)) + "\n")
            
            
def main():
    filename_double1 = f'matrix_double_{256}_1.txt'
    filename_double2 = f'matrix_double_{256}_2.txt'
    output_filename_double = f'matrix_double_result_{256}.txt'
    generate_and_save_matrix_double(256, filename_double1)
    generate_and_save_matrix_double(256, filename_double2)
    print(f"Generated matrices (double) for N={256} and saved to files.")
    matrix1_double = read_matrix(filename_double1, 256, dtype=float)
    matrix2_double = read_matrix(filename_double2, 256, dtype=float)
    multiply_and_save_matrices(matrix1_double, matrix2_double, 256, output_filename_double, dtype=float)
    print(f"Multiplication result for double matrices of size {256} saved to {output_filename_double}")


if __name__ == "__main__":
    main()