import random
import numpy as np

def generate_and_save_matrix_int(N, filename):
    with open(filename, 'w') as file:
        for i in range(N):
            row = [str(random.randint(0, 99)) for _ in range(N)]  # Random integers between 0 and 99
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
    # Generate and process integer matrices
    filename_int1 = f'matrix_int_{1024}_1.txt'
    filename_int2 = f'matrix_int_{1024}_2.txt'
    output_filename_int = f'matrix_int_result_{1024}.txt'
    generate_and_save_matrix_int(1024, filename_int1)
    generate_and_save_matrix_int(1024, filename_int2)
    print(f"Generated matrices (int) for N={1024} and saved to files.")
    matrix1_int = read_matrix(filename_int1, 1024, dtype=int)
    matrix2_int = read_matrix(filename_int2, 1024, dtype=int)
    multiply_and_save_matrices(matrix1_int, matrix2_int, 1024, output_filename_int, dtype=int)
    print(f"Multiplication result for integer matrices of size {1024} saved to {output_filename_int}")


if __name__ == "__main__":
    main()