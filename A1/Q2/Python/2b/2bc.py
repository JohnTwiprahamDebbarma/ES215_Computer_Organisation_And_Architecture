import matplotlib.pyplot as plt
import pandas as pd

# Read the execution times from the file
df = pd.read_csv('execution_times.txt')

# Separate the data by type
df_int = df[df['Type'] == 'int']
df_double = df[df['Type'] == 'double']

# Initialize a figure for plotting
plt.figure(figsize=(14, 7))

# Plot for Integer matrices
plt.subplot(2, 2, 1)
for size in df_int['Size'].unique():
    subset = df_int[df_int['Size'] == size]
    plt.plot(subset['Iteration'], subset['Meat Time (s)'], marker='o', label=f'Int N={size}')
plt.xlabel('Iteration')
plt.ylabel('Meat Time (s)')
plt.title('Integer Meat Time vs Iteration')
plt.legend()
plt.grid(True)

plt.subplot(2, 2, 2)
for size in df_int['Size'].unique():
    subset = df_int[df_int['Size'] == size]
    plt.plot(subset['Iteration'], subset['Total Time (s)'], marker='o', label=f'Int N={size}')
plt.xlabel('Iteration')
plt.ylabel('Total Time (s)')
plt.title('Integer Total Time vs Iteration')
plt.legend()
plt.grid(True)

# Plot for Double matrices
plt.subplot(2, 2, 3)
for size in df_double['Size'].unique():
    subset = df_double[df_double['Size'] == size]
    plt.plot(subset['Iteration'], subset['Meat Time (s)'], marker='o', label=f'Double N={size}')
plt.xlabel('Iteration')
plt.ylabel('Meat Time (s)')
plt.title('Double Meat Time vs Iteration')
plt.legend()
plt.grid(True)

plt.subplot(2, 2, 4)
for size in df_double['Size'].unique():
    subset = df_double[df_double['Size'] == size]
    plt.plot(subset['Iteration'], subset['Total Time (s)'], marker='o', label=f'Double N={size}')
plt.xlabel('Iteration')
plt.ylabel('Total Time (s)')
plt.title('Double Total Time vs Iteration')
plt.legend()
plt.grid(True)

# Save the plots to a file
plt.tight_layout()
plt.savefig('execution_times_with_iterations_plot.png')
plt.show()
