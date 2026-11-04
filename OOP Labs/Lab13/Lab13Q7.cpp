/*
a. On random input, Quicksort and Mergesort are both efficient.
   Quicksort is usually slightly faster due to lower memory overhead,
   but differences in comparisons are not very large.

b. On reverse-sorted input, plain Quicksort performs poorly if pivot
   selection is bad, leading to highly unbalanced partitions, while
   Mergesort remains stable with O(n log n) behavior.

c. Yes, Mergesort’s O(n) extra memory slightly increases overhead,
   but for large inputs the stable O(n log n) time makes it competitive.

d. Mergesort is preferred in scenarios requiring stable sorting or
   predictable performance.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

long long qsComparisons = 0;
long long msComparisons = 0;

void swapFunc(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(vector<int>& a, int lo, int hi) {
    int pivot = a[lo];
    int i = lo;
    int j = hi + 1;

    while (true) {

        while (true) {
            i++;
            if (i > hi) break;
            qsComparisons++;
            if (a[i] >= pivot) break;
        }

        while (true) {
            j--;
            if (j <= lo) break;
            qsComparisons++;
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

    int p = partition(a, lo, hi);
    quicksort(a, lo, p - 1);
    quicksort(a, p + 1, hi);
}

void merge(vector<int>& a, int lo, int mid, int hi) {

    vector<int> temp;

    int i = lo;
    int j = mid + 1;

    while (i <= mid && j <= hi) {
        msComparisons++;
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= hi) temp.push_back(a[j++]);

    for (int k = 0; k < temp.size(); k++) {
        a[lo + k] = temp[k];
    }
}

void mergesort(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;

    int mid = (lo + hi) / 2;

    mergesort(a, lo, mid);
    mergesort(a, mid + 1, hi);

    merge(a, lo, mid, hi);
}

vector<int> randomArray(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;

    random_device rd;
    mt19937 g(rd());
    shuffle(a.begin(), a.end(), g);

    return a;
}

vector<int> sortedArray(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;
    return a;
}

vector<int> reverseArray(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = n - i;
    return a;
}

vector<int> equalArray(int n) {
    return vector<int>(n, 5);
}

pair<long long, long long> runQS(vector<int> a) {
    qsComparisons = 0;

    auto start = high_resolution_clock::now();
    quicksort(a, 0, a.size() - 1);
    auto end = high_resolution_clock::now();

    long long time = duration_cast<microseconds>(end - start).count();
    return {qsComparisons, time};
}

pair<long long, long long> runMS(vector<int> a) {
    msComparisons = 0;

    auto start = high_resolution_clock::now();
    mergesort(a, 0, a.size() - 1);
    auto end = high_resolution_clock::now();

    long long time = duration_cast<microseconds>(end - start).count();
    return {msComparisons, time};
}

pair<long long, long long> avgQS(vector<int> a) {
    long long cmp = 0, t = 0;

    for (int i = 0; i < 5; i++) {
        auto r = runQS(a);
        cmp += r.first;
        t += r.second;
    }

    return {cmp / 5, t / 5};
}

pair<long long, long long> avgMS(vector<int> a) {
    long long cmp = 0, t = 0;

    for (int i = 0; i < 5; i++) {
        auto r = runMS(a);
        cmp += r.first;
        t += r.second;
    }

    return {cmp / 5, t / 5};
}

int main() {

    vector<int> sizes = {500, 2000};

    cout << left << setw(12) << "Input"
         << setw(6) << "n"
         << setw(20) << "QS cmp/time"
         << setw(20) << "MS cmp/time" << endl;

    cout << "------------------------------------------------------------\n";

    for (int n : sizes) {

        vector<pair<string, vector<int>>> tests = {
            {"Random ", randomArray(n)},
            {"NearlySorted ", sortedArray(n)},
            {"Reverse ", reverseArray(n)},
            {"AllEqual ", equalArray(n)}
        };

        for (auto &t : tests) {

            auto qs = avgQS(t.second);
            auto ms = avgMS(t.second);

            cout << left << setw(12) << t.first
                 << setw(6) << n
                 << setw(20) << (to_string(qs.first) + "/" + to_string(qs.second))
                 << setw(20) << (to_string(ms.first) + "/" + to_string(ms.second))
                 << endl;
        }
    }

    return 0;
}