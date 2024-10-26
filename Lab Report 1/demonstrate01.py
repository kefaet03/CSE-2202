import matplotlib.pyplot as plt

# Data
sizes = [100000, 120000, 140000, 160000, 180000, 200000, 220000, 240000, 260000, 280000, 300000, 320000]
insertion_sort_times = [19637, 32951, 60216, 78775, 99484, 114046, 147110, 205017, 887718, 264110, 264524, 1158980]
counting_sort_times = [0, 0, 0, 0, 7, 15, 21, 19, 23, 27, 29, 30]
merge_sort_times = [17, 31, 34, 35, 41, 46, 43, 80, 58, 48, 62, 86]

# Plot
plt.figure(figsize=(12, 6))
plt.plot(sizes, insertion_sort_times, label="Insertion Sort", marker='o', color='r')
plt.plot(sizes, counting_sort_times, label="Counting Sort", marker='s', color='g')
plt.plot(sizes, merge_sort_times, label="Merge Sort", marker='^', color='b')

# Logarithmic scale for y-axis
plt.yscale('log')

# Labeling
plt.xlabel('Array Size')
plt.ylabel('Time (milliseconds, log scale)')
plt.title('Comparison of Sorting Algorithm Runtimes (Logarithmic Scale)')
plt.legend()
plt.grid(True, which="both", linestyle="--", linewidth=0.5)

# Show plot
plt.show()
