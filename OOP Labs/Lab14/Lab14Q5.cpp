/*(a) For n = 10000:
      nlog2n = 10000 × 13.29
      ≈ 132900
10000log2(10000) ≈ 132900
n² = 100000000
10000² = 100000000

Measured values are close in growth pattern:
Merge Sort ≈ n log n
Selection/Insertion ≈ n²

(b) Merge Sort uses extra memory because it creates temporary arrays during merging.
Selection Sort and Insertion Sort sort directly inside the original array, so they need no extra array.*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(vector<int>& arr, long long& cmp)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            cmp++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(vector<int>& arr, long long& cmp)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            cmp++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
                break;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int left, int mid, int right, long long& cmp)
{
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        cmp++;
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

void mergeSort(vector<int>& arr, int left, int right, long long& cmp)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, cmp);
    mergeSort(arr, mid + 1, right, cmp);

    merge(arr, left, mid, right, cmp);
}

int main()
{
    srand(time(0));
    int sizes[] = {100, 1000, 5000, 10000};

    cout << "n\tSelection\tInsertion\tMerge\n";

    for (int n : sizes)
    {
        vector<int> original(n);

        for (int i = 0; i < n; i++)
            original[i] = rand() % 10000;

        vector<int> a = original;
        vector<int> b = original;
        vector<int> c = original;

        long long s = 0, ins = 0, m = 0;

        selectionSort(a, s);
        insertionSort(b, ins);
        mergeSort(c, 0, c.size() - 1, m);

        cout << n << "  \t" << s << "    \t" << ins << "    \t" << m << endl;
    }

    return 0;
}