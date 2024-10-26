import matplotlib.pyplot as plt

# Data for sizes and corresponding execution times
sizes = [100000, 120000, 140000, 160000, 180000, 300000, 320000]
merge_sort_times = [14, 18, 16, 21, 33, 64, 90]
hybrid_sort_times = [0, 14, 2, 14, 18, 33, 20]

# Plotting the data
plt.figure(figsize=(10, 6))

# Plot Merge Sort times
plt.plot(sizes, merge_sort_times, marker='o', linestyle='-', color='blue', label='Merge Sort')

# Plot Hybrid Sort times
plt.plot(sizes, hybrid_sort_times, marker='x', linestyle='--', color='green', label='Hybrid Sort')

# Adding titles and labels
plt.title('Merge Sort vs. Hybrid Sort Execution Time')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (ms)')
plt.grid(True)
plt.legend(loc='upper left')

# Display the plot
plt.show()
