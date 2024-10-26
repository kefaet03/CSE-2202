#include <bits/stdc++.h>
#include <chrono>
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

int main(){
    int size = 100000;
    for(int n=15 ; n>0 ; --n){
        cout <<  "Size: " << size << endl;
        vector<int> vec(size);
        for (int i = 0; i < size; i++)
        {
            vec[i] = rand() % 1000;
        }

        auto start1 = chrono::high_resolution_clock::now();
        vector<int> copy1 = vec;
        insertion_sort(copy1, 0, copy1.size() - 1);
        auto end1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "Insertion Sort: " << duration1 << "milliseconds" << endl;

        auto start2 = chrono::high_resolution_clock::now();
        vector<int> copy2 = vec;
        counting_sort(copy2);
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
        cout << "Counting Sort: " << duration2 << "milliseconds" << endl;

        auto start3 = chrono::high_resolution_clock::now();
        vector<int> copy3 = vec;
        mergeSort(copy3, 0, copy3.size()-1);
        auto end3 = chrono::high_resolution_clock::now();
        auto duration3 = chrono::duration_cast<chrono::milliseconds>(end3 - start3).count();
        cout << "Merge Sort: " << duration3 << "milliseconds" << endl;

        size += 20000;
    }

}