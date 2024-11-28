#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Quick Sort
int quickSortSwaps = 0;

void quickSwap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    quickSortSwaps++;
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low]; 
    int i = low + 1;      
    int j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot) i++; 
        while (j >= low && arr[j] > pivot) j--;  

        if (i >= j) break; 
        quickSwap(arr[i], arr[j]); 
    }
    quickSwap(arr[low], arr[j]); 
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int mergeSortInversions = 0;

void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            mergeSortInversions += (n1 - i); 
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// vector<int> generateRandomArray(int size, int maxVal) {
//     vector<int> arr(size);
//     for (int i = 0; i < size; i++) {
//         arr[i] = rand() % maxVal;
//     }
//     return arr;
// }

// void saveResultsToFile(const vector<int> &arr, const string &filename, int quickSwaps, int mergeInversions) {
//     ofstream outFile(filename);
//     if (!outFile) {
//         cerr << "Error opening file: " << filename << endl;
//         return;
//     }
//     outFile << "Sorted Array:\n";
//     for (int num : arr) {
//         outFile << num << " ";
//     }
//     outFile << "\n\nQuick Sort Swaps: " << quickSwaps << endl;
//     outFile << "Merge Sort Inversions: " << mergeInversions << endl;
//     outFile.close();
// }

int main() {
    // srand(time(0));

    // int arraySize, maxVal;
    // cout << "Enter array size: ";
    // cin >> arraySize;
    // cout << "Enter maximum value for elements: ";
    // cin >> maxVal;

    // vector<int> arr = generateRandomArray(arraySize, maxVal);
    vector<int> arr;
    int num;
    string filename = "sorted_results.txt";

    ifstream inputFile(filename);
    if(!inputFile.is_open()){
        cerr << "Error" << filename << endl;
        return 1;
    }
    while(inputFile >> num){
        arr.push_back(num);
    }
    inputFile.close();

    vector<int> quickSortArr = arr;
    vector<int> mergeSortArr = arr;

    quickSortSwaps = 0;
    quickSort(quickSortArr, 0, 5000 - 1);
    mergeSortInversions = 0;
    mergeSort(mergeSortArr, 0, 5000 - 1);

    // // saveResultsToFile(quickSortArr, "sorted_results.txt", quickSortSwaps, mergeSortInversions);

    cout << "Quick Sort Swaps: " << quickSortSwaps << endl;
    cout << "Merge Sort Inversions: " << mergeSortInversions << endl;
    cout << "Results saved to 'sorted_results.txt'" << endl;

    return 0;
}
