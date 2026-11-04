#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;
using namespace chrono;

long long comparisons = 0;

void swapFunc(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
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

int median3(vector<int>& a, int i, int j, int k) {
    if ((a[i] < a[j] && a[j] < a[k]) || (a[k] < a[j] && a[j] < a[i]))
        return j;
    else if ((a[j] < a[i] && a[i] < a[k]) || (a[k] < a[i] && a[i] < a[j]))
        return i;
    else
        return k;
}

int partitionStop(vector<int>& a, int lo, int hi) {
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

    int p = partitionStop(a, lo, hi);

    quicksort(a, lo, p - 1);
    quicksort(a, p + 1, hi);
}

void quicksortPro(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;

    if (hi - lo + 1 <= 10) {
        insertionSort(a, lo, hi);
        return;
    }

    int mid = lo + (hi - lo) / 2;
    int m = median3(a, lo, mid, hi);

    swapFunc(a[lo], a[m]);

    int p = partitionStop(a, lo, hi);

    quicksortPro(a, lo, p - 1);
    quicksortPro(a, p + 1, hi);
}

pair<long long, long long> runTest(vector<int> arr, bool pro) {

    comparisons = 0;

    auto start = high_resolution_clock::now();

    if (pro)
        quicksortPro(arr, 0, arr.size() - 1);
    else
        quicksort(arr, 0, arr.size() - 1);

    auto end = high_resolution_clock::now();

    long long timeTaken =
        duration_cast<microseconds>(end - start).count();

    return {comparisons, timeTaken};
}

int main() {

    int n = 2000;

    vector<int> randomArr(n);
    for (int i = 0; i < n; i++) randomArr[i] = i;

    mt19937 g(random_device{}());
    shuffle(randomArr.begin(), randomArr.end(), g);

    vector<int> allEqual(n, 5);

    vector<int> reverseArr(n);
    for (int i = 0; i < n; i++) reverseArr[i] = n - i;

    cout << "n=2000\n";
    cout << left << setw(15) << "Input type"
         << setw(22) << "Plain QS (cmp/us)"
         << setw(22) << "Pro QS (cmp/us)" << endl;

    auto p1 = runTest(randomArr, false);
    auto p2 = runTest(randomArr, true);

    cout << left << setw(15) << "Random"
         << p1.first << " / " << p1.second << " us"
         << setw(8) << ""
         << p2.first << " / " << p2.second << " us"
         << endl;

    p1 = runTest(allEqual, false);
    p2 = runTest(allEqual, true);

    cout << left << setw(15) << "All Equal"
         << p1.first << " / " << p1.second << " us"
         << setw(8) << ""
         << p2.first << " / " << p2.second << " us"
         << endl;

    p1 = runTest(reverseArr, false);
    p2 = runTest(reverseArr, true);

    cout << left << setw(15) << "Reverse"
         << p1.first << " / " << p1.second << " us"
         << setw(8) << ""
         << p2.first << " / " << p2.second << " us"
         << endl;

    return 0;
}