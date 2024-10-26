import matplotlib.pyplot as plt

# Data for thresholds and corresponding execution times
thresholds = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60]
execution_times = [8952, 8865, 9097, 9194, 10633, 10619, 10610, 10645, 10623, 11684, 11669, 11709]

# Plotting the data
plt.figure(figsize=(10, 6))
plt.plot(thresholds, execution_times, marker='o', linestyle='-', color='blue', label='Execution Time (ms)')

# Highlight the optimum threshold
optimum_threshold = 20
optimum_time = execution_times[thresholds.index(optimum_threshold)]
plt.axvline(x=optimum_threshold, color='green', linestyle='--', label='Optimum Threshold (20)')
plt.scatter(optimum_threshold, optimum_time, color='red', s=100, zorder=5, label=f'Optimum Point (Threshold 20, Time {optimum_time}ms)')

# Adding titles and labels
plt.title('Execution Time vs. Threshold')
plt.xlabel('Threshold')
plt.ylabel('Execution Time (ms)')
plt.xticks(thresholds)
plt.grid(True)
plt.legend(loc='upper left')

# Display the plot
plt.show()