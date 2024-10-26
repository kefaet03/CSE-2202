#include <bits/stdc++.h>
using namespace std;

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

void Hybride2(vector<int> &vec, int left, int right,int thrs)
{
    if (left < right)
    {
        if (right - left + 1 <= thrs)
        {
            bubble_sort(vec, left, right);
        }
        else
        {
            int mid = left + (right - left) / 2;

            Hybride2(vec, left, mid,thrs);
            Hybride2(vec, mid + 1, right,thrs);

            merge(vec, left, mid, right);
        }
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
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        vec[i] = rand() % 1000;
    }
    
    for (int i = 5; i <= 60; i=i+5)
    {
        cout <<  "Threshold: " << i << endl;
        vector<int> copy = vec;
        auto start = chrono::high_resolution_clock::now();
        Hybride2(copy, 0, copy.size()-1,i);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cout << "Execution time: " << duration << " milliseconds" << endl;
    }

    for(int n=12 ; n>0 ; --n){
        cout <<  "Size: " << size << endl;
        vector<int> vec(size);
        for (int i = 0; i < size; i++)
        {
            vec[i] = rand() % 1000;
        }

        auto start1 = chrono::high_resolution_clock::now();
        vector<int> copy1 = vec;
        mergeSort(copy1, 0, copy1.size()-1);
        auto end1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();
        cout << "Merge Sort: " << duration1 << "milliseconds" << endl;

        auto start2 = chrono::high_resolution_clock::now();
        vector<int> copy2 = vec;
        Hybride2(copy1, 0, copy1.size()-1,20);
        auto end2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();
        cout << "Hybrid Sort: " << duration2 << "milliseconds" << endl;

        size += 20000;
    }
}

