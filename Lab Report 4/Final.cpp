#include <bits/stdc++.h>
using namespace std;

void generateFile(const string &filename, int n)
{
    ofstream outFile(filename);
    if (!outFile.is_open())
    {
        cerr << "Error " << filename << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100000);

    for (int i = 0; i < n; ++i)
    {
        outFile << dist(gen) << " ";
    }

    outFile.close();
    cout << "yes" << endl;
}

void merge(vector<int> &arr, int left, int mid, int right, long long &swaps)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
        swaps++;
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
        swaps++;
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
        swaps++;
    }
}

void mergeSort(vector<int> &arr, int left, int right, long long &swaps)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, swaps);
        mergeSort(arr, mid + 1, right, swaps);
        merge(arr, left, mid, right, swaps);
    }
}

int partition(vector<int> &arr, int low, int high, long long &swaps)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            ++i;
            ++swaps;
        } while (arr[i] < pivot);

        do
        {
            --j;
            ++swaps;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int> &arr, int low, int high, long long &swaps)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high, swaps);
        quickSort(arr, low, pivot - 1, swaps);
        quickSort(arr, pivot + 1, high, swaps);
    }
}

int main()
{
    string file = "number.txt";
    int n;

    cout << "n: ";
    cin >> n;
    generateFile(file, n);

    ifstream inFile(file);
    if (!inFile.is_open())
    {
        cerr << "Error" << file << endl;
        return 1;
    }

    vector<int> nums;
    int num;
    while (inFile >> num)
    {
        nums.push_back(num);
    }
    inFile.close();

    vector<int> mSortNums = nums;
    long long mSwaps = 0;
    mergeSort(mSortNums, 0, mSortNums.size() - 1, mSwaps);
    cout << "Merge: " << mSwaps << endl;

    vector<int> qSortNums = nums;
    long long qSwaps = 0;
    quickSort(qSortNums, 0, qSortNums.size() - 1, qSwaps);
    cout << "Quick: " << qSwaps << endl;

    cout <<  "Worst Case: " << endl;

    sort(mSortNums.begin(),mSortNums.end());
    reverse(mSortNums.begin(),mSortNums.end());
    mSwaps = 0;
    mergeSort(mSortNums, 0, mSortNums.size() - 1, mSwaps);
    cout << "Merge (descending): " << mSwaps << endl;

    sort(qSortNums.begin(), qSortNums.end());
    qSwaps = 0;
    quickSort(qSortNums, 0, qSortNums.size() - 1, qSwaps);
    cout << "Quick (ascending): " << qSwaps << endl;

    return 0;
}
