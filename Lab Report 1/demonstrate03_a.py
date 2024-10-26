import matplotlib.pyplot as plt

thresholds = [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60]
execution_times = [15, 14, 11, 7, 9, 14, 13, 9, 11, 10, 8, 9]

plt.figure(figsize=(10, 6))
plt.plot(thresholds, execution_times, marker='o', linestyle='-', color='blue', label='Execution Time (ms)')

optimum_threshold = 20
optimum_time = execution_times[thresholds.index(optimum_threshold)]
plt.axvline(x=optimum_threshold, color='green', linestyle='--', label='Optimum Threshold (20)')
plt.scatter(optimum_threshold, optimum_time, color='red', s=100, zorder=5, label=f'Optimum Point (Threshold 20, Time {optimum_time}ms)')

plt.title('Execution Time vs. Threshold for Bubble Sort')
plt.xlabel('Threshold')
plt.ylabel('Execution Time (ms)')
plt.xticks(thresholds)
plt.grid(True)
plt.legend(loc='upper left')

plt.show()
