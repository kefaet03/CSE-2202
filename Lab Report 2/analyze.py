import matplotlib.pyplot as plt

# Data from the table
sizes = [50, 100, 250, 500, 1000, 1500, 2500, 5000]
quick_hull_times = [0.002534, 0.005983, 0.011022, 0.034236, 0.048835, 0.113808, 0.138793, 0.182765]
graham_scan_times = [0.000347, 0.000686, 0.000934, 0.002739, 0.004252, 0.006608, 0.014129, 0.018683]

# Plotting the data
plt.figure(figsize=(10, 6))
plt.plot(sizes, quick_hull_times, label="Quick Hull", marker='o')
plt.plot(sizes, graham_scan_times, label="Graham Scan", marker='s')

# Adding labels and title
plt.xlabel("Input Size (Number of Points)", fontsize=12)
plt.ylabel("Execution Time (Seconds)", fontsize=12)
plt.title("Execution Time Analysis of Quick Hull vs Graham Scan", fontsize=14)
plt.legend(fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)

# Display the plot
plt.show()
