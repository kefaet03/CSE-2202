#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Global variable to count Quick Sort swaps
int quickSortSwaps = 0;

// Function to swap elements and count swaps
void quickSwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    quickSortSwaps++;
}

// Partition function for Quick Sort using `low` as pivot
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low]; // Pivot is now the low element
    int i = low + 1;      // Start from the next element
    int j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot) i++; // Find element greater than pivot
        while (j >= low && arr[j] > pivot) j--;  // Find element smaller than pivot

        if (i >= j) break; // If pointers cross, exit loop
        quickSwap(arr[i], arr[j]); // Swap elements
    }
    quickSwap(arr[low], arr[j]); // Place pivot in its correct position
    return j;
}

// Quick Sort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array
        quickSort(arr, low, pi - 1);        // Sort the left half
        quickSort(arr, pi + 1, high);       // Sort the right half
    }
}

// Function to read sorted data from file
vector<int> readSortedDataFromFile(const string &filename) {
    vector<int> data;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return data;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.find("Sorted Array:") != string::npos) {
            getline(inFile, line); // Read the line with numbers
            stringstream ss(line);
            int num;
            while (ss >> num) {
                data.push_back(num);
            }
            break;
        }
    }
    inFile.close();
    return data;
}

int main() {
    // Read sorted data from file
    vector<int> sortedData = readSortedDataFromFile("sorted_results.txt");
    if (sortedData.empty()) {
        cerr << "No data found in the file!" << endl;
        return 1;
    }

    // Re-apply Quick Sort
    quickSortSwaps = 0;
    quickSort(sortedData, 0, sortedData.size() - 1);

    // Output the result
    cout << "Quick Sort Swaps on sorted data with low as pivot: " << quickSortSwaps << endl;
    return 0;
}
