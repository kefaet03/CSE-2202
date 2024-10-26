import matplotlib.pyplot as plt

# Data for sizes and corresponding execution times
sizes = [100000, 120000, 140000, 160000, 180000, 200000, 220000, 240000, 260000, 280000, 300000, 320000]
merge_sort_times = [20, 20, 33, 45, 32, 32, 34, 40, 35, 41, 53, 61]
hybrid_sort_times = [8, 16, 10, 17, 20, 21, 21, 27, 23, 24, 20, 23]

# Plotting the data
plt.figure(figsize=(10, 6))

# Plot Merge Sort times
plt.plot(sizes, merge_sort_times, marker='o', linestyle='-', color='blue', label='Merge Sort')

# Plot Hybrid Sort times
plt.plot(sizes, hybrid_sort_times, marker='x', linestyle='--', color='green', label='Hybrid Sort')

# Adding titles and labels
plt.title('Execution Time Comparison: Merge Sort vs. Hybrid Sort')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (ms)')
plt.grid(True)
plt.legend(loc='upper left')

# Display the plot
plt.show()


