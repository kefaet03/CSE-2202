#include <bits/stdc++.h>
#define ll long long
#define fri(n) for (int i = 0; i < n; i++)
#define frk(n) for (int k = 0; k < n; k++)
#define frj(n) for (int j = 0; j < n; j++)
#define ff first
#define ss second
#define nn
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

void insertion_sort(vector<int> &vec, int left, int right)
{
    auto start = chrono::high_resolution_clock::now();

    for (int i = left + 1; i <= right; i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j] = key;
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << "milliseconds" << endl;
}

void insertion_sort_hybrid(vector<int> &vec, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j] = key;
    }
}

void counting_sort(vector<int> &vec)
{
    auto start = chrono::high_resolution_clock::now();

    int max = *max_element(vec.begin(), vec.end());

    int n = vec.size();
    vector<int> count(max + 1, 0);

    for (int i = 0; i < n; i++)
    {
        count[vec[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> output(n);

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[vec[i]] - 1] = vec[i];
        count[vec[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        vec[i] = output[i];
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Execution time: " << duration << "milliseconds" << endl;
}

void bubble_sort(std::vector<int> &arr, int left, int right)
{
    for (int i = left; i < right - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < right - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void merge(vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = vec[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = vec[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);

        merge(vec, left, mid, right);
    }
}

void Hybride1(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        if (right - left + 1 <= 7)
        {
            insertion_sort_hybrid(vec, left, right);
        }
        else
        {
            int mid = left + (right - left) / 2;

            Hybride1(vec, left, mid);
            Hybride1(vec, mid + 1, right);

            merge(vec, left, mid, right);
        }
    }
}

void Hybride2(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        if (right - left + 1 <= 7)
        {
            bubble_sort(vec, left, right);
        }
        else
        {
            int mid = left + (right - left) / 2;

            Hybride2(vec, left, mid);
            Hybride2(vec, mid + 1, right);

            merge(vec, left, mid, right);
        }
    }
}

