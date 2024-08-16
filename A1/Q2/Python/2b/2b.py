import time
import random
import numpy as np

def generate_and_save_matrix_int(N, filename):
    with open(filename, 'w') as file:
        for i in range(N):
            row = [str(random.randint(0, 99)) for _ in range(N)]  # Random integers between 0 and 99
            file.write(" ".join(row) + "\n")
            
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
    
    # Start measuring time for the matrix multiplication (meat portion)
    start_meat = time.time()

    for i in range(N):
        for j in range(N):
            for k in range(N):
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j]

    end_meat = time.time()
    meat_time = end_meat - start_meat
    
    with open(output_filename, 'w') as file:
        for row in result_matrix:
            file.write(" ".join(map(str, row)) + "\n")

    return meat_time

def main():
    sizes = [64, 128]

    with open('execution_times.txt', 'w') as f:
        f.write("Size,Iteration,Type,Meat Time (s),Total Time (s),Meat Proportion (%)\n")
        for N in sizes:
            # Integer case
            filename_int1 = f'matrix_int_{N}_1.txt'
            filename_int2 = f'matrix_int_{N}_2.txt'
            output_filename_int = f'matrix_int_result_{N}.txt'
            generate_and_save_matrix_int(N, filename_int1)
            generate_and_save_matrix_int(N, filename_int2)
            print(f"Generated matrices (int) for N={N} and saved to files.")
            matrix1_int = read_matrix(filename_int1, N, dtype=int)
            matrix2_int = read_matrix(filename_int2, N, dtype=int)

            for i in range(1, 4):
                # Start measuring total time
                start_total = time.time()

                meat_time = multiply_and_save_matrices(matrix1_int, matrix2_int, N, output_filename_int, dtype=int)

                end_total = time.time()
                total_time = end_total - start_total

                proportion_meat = meat_time / total_time

                print(f"Time for integer matrix multiplication for N={N} and iteration={i}:")
                print(f"  Meat portion time: {meat_time:.6f} seconds")
                print(f"  Total time: {total_time:.6f} seconds")
                print(f"  Meat portion proportion: {proportion_meat * 100:.2f}%")
                
                f.write(f"{N},{i},int,{meat_time:.6f},{total_time:.6f},{proportion_meat * 100:.2f}\n")

            # Double case
            filename_double1 = f'matrix_double_{N}_1.txt'
            filename_double2 = f'matrix_double_{N}_2.txt'
            output_filename_double = f'matrix_double_result_{N}.txt'
            generate_and_save_matrix_double(N, filename_double1)
            generate_and_save_matrix_double(N, filename_double2)
            print(f"Generated matrices (double) for N={N} and saved to files.")
            matrix1_double = read_matrix(filename_double1, N, dtype=float)
            matrix2_double = read_matrix(filename_double2, N, dtype=float)

            for i in range(1, 4):
                # Start measuring total time
                start_total = time.time()

                meat_time = multiply_and_save_matrices(matrix1_double, matrix2_double, N, output_filename_double, dtype=float)

                end_total = time.time()
                total_time = end_total - start_total

                proportion_meat = meat_time / total_time

                print(f"Time for double matrix multiplication for N={N} and iteration={i}:")
                print(f"  Meat portion time: {meat_time:.6f} seconds")
                print(f"  Total time: {total_time:.6f} seconds")
                print(f"  Meat portion proportion: {proportion_meat * 100:.2f}%")
                
                f.write(f"{N},{i},double,{meat_time:.6f},{total_time:.6f},{proportion_meat * 100:.2f}\n")

if __name__ == "__main__":
    main()
