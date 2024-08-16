# The program is being compiled and timed
echo "Compiling 64x64 integer matrix multiplication program and time taken is:"
time g++ -std=c++20 64_int.cpp -o 64_int

# The compiled program is being run and timed
echo "Running the compiled program and time taken is:"
time ./64_int


echo "Compiling 128x128 integer matrix multiplication program and time taken is:"
time g++ -std=c++20 128_int.cpp -o 128_int
echo "Running the compiled program and time taken is:"
time ./128_int

echo "Compiling 256x256 integer matrix multiplication program and time taken is:"
time g++ -std=c++20 256_int.cpp -o 256_int
echo "Running the compiled program and time taken is:"
time ./256_int

echo "Compiling 512x512 integer matrix multiplication program and time taken is:"
time g++ -std=c++20 512_int.cpp -o 512_int
echo "Running the compiled program and time taken is:"
time ./512_int

echo "Compiling 1024x1024 integer matrix multiplication program and time taken is:"
time g++ -std=c++20 1024_int.cpp -o 1024_int
echo "Running the compiled program and time taken is:"
time ./1024_int

echo "Compiling 64x64 double matrix multiplication program and time taken is:"
time g++ -std=c++20 64_double.cpp -o 64_double
echo "Running the compiled program and time taken is:"
time ./64_double

echo "Compiling 128x128 double matrix multiplication program and time taken is:"
time g++ -std=c++20 128_double.cpp -o 128_double
echo "Running the compiled program and time taken is:"
time ./128_double

echo "Compiling 256x256 double matrix multiplication program and time taken is:"
time g++ -std=c++20 256_double.cpp -o 256_double
echo "Running the compiled program and time taken is:"
time ./256_double

echo "Compiling 512x512 double matrix multiplication program and time taken is:"
time g++ -std=c++20 512_double.cpp -o 512_double
echo "Running the compiled program and time taken is:"
time ./512_double

echo "Compiling 1024x1024 double matrix multiplication program and time taken is:"
time g++ -std=c++20 1024_double.cpp -o 1024_double
echo "Running the compiled program and time taken is:"
time ./1024_double
