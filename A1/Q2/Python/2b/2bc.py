import matplotlib.pyplot as plt

def read_execution_times(filename):
    sizes = []
    iterations = []
    types = []
    meat_times = []
    total_times = []
    proportions = []

    with open(filename, 'r') as file:
        # Skip header
        next(file)
        for line in file:
            size, iteration, type_, meat_time, total_time, proportion = line.strip().split(',')
            sizes.append(int(size))
            iterations.append(int(iteration))
            types.append(type_)
            meat_times.append(float(meat_time))
            total_times.append(float(total_time))
            proportions.append(float(proportion))

    return sizes, iterations, types, meat_times, total_times, proportions

def plot_execution_times(sizes, iterations, types, meat_times, total_times, proportions):
    plt.figure(figsize=(12, 8))

    # Plot meat times and total times
    plt.subplot(2, 1, 1)
    for dtype in set(types):
        indices = [i for i in range(len(types)) if types[i] == dtype]
        plt.plot([iterations[i] for i in indices], [meat_times[i] for i in indices], marker='o', linestyle='-', label=f'{dtype} - Meat Time')
        plt.plot([iterations[i] for i in indices], [total_times[i] for i in indices], marker='o', linestyle='--', label=f'{dtype} - Total Time')

    plt.xlabel('Iteration')
    plt.ylabel('Time (seconds)')
    plt.title('Matrix Multiplication Execution Times')
    plt.legend()
    plt.grid(True)

    # Plot proportions
    plt.subplot(2, 1, 2)
    for dtype in set(types):
        indices = [i for i in range(len(types)) if types[i] == dtype]
        plt.plot([iterations[i] for i in indices], [proportions[i] for i in indices], marker='o', linestyle='-', label=f'{dtype} - Meat Proportion')

    plt.xlabel('Iteration')
    plt.ylabel('Proportion (%)')
    plt.title('Meat Portion Proportion')
    plt.legend()
    plt.grid(True)

    plt.tight_layout()
    plt.savefig('execution_times_from_file_plot.png')
    plt.show()

def main():
    filename = 'execution_times.txt'
    sizes, iterations, types, meat_times, total_times, proportions = read_execution_times(filename)
    plot_execution_times(sizes, iterations, types, meat_times, total_times, proportions)

if __name__ == "__main__":
    main()
