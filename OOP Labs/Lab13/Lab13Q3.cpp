/*
  Best cutoff:
  Usually between 5 and 20.

  Why very large cutoff (e.g. 100) hurts performance:
  Because Insertion Sort is O(n²), so when it is applied to large subarrays,
  it becomes very expensive and removes the benefit of Quicksort’s O(n log n) behavior.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

long long comparisons = 0;

void swapFunc(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(vector<int>& a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= lo) {
            comparisons++;
            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
            } else {
                break;
            }
        }
        a[j + 1] = key;
    }
}

int partition(vector<int>& a, int lo, int hi) {
    int pivot = a[lo];
    int i = lo;
    int j = hi + 1;

    while (true) {

        while (true) {
            i++;
            if (i > hi) break;
            comparisons++;
            if (a[i] >= pivot) break;
        }

        while (true) {
            j--;
            if (j <= lo) break;
            comparisons++;
            if (a[j] <= pivot) break;
        }

        if (i >= j) break;

        swapFunc(a[i], a[j]);
    }

    swapFunc(a[lo], a[j]);
    return j;
}

void quicksort(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;

    int j = partition(a, lo, hi);
    quicksort(a, lo, j - 1);
    quicksort(a, j + 1, hi);
}

void quicksortCutoff(vector<int>& a, int lo, int hi, int cutoff) {

    if (hi <= lo) return;

    if (hi - lo + 1 <= cutoff) {
        insertionSort(a, lo, hi);
        return;
    }

    int j = partition(a, lo, hi);
    quicksortCutoff(a, lo, j - 1, cutoff);
    quicksortCutoff(a, j + 1, hi, cutoff);
}

void runTest(int cutoff, vector<int> arr) {

    comparisons = 0;
    auto start = high_resolution_clock::now();

    if (cutoff == 1) {
        quicksort(arr, 0, arr.size() - 1);
    } else {
        quicksortCutoff(arr, 0, arr.size() - 1, cutoff);
    }

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    cout << "Cutoff=" << cutoff
         << " comparisons=" << comparisons
         << " time=" << duration.count() << " us"
         << endl;
}

int main() {

    int n = 1000;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) arr[i] = i;
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);

    cout << "n = 1000, randomly shuffled\n";

    runTest(1, arr);
    runTest(5, arr);
    runTest(10, arr);
    runTest(20, arr);

    return 0;
}