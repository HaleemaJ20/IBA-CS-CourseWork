/*
Adding a full shuffle before sorting also removes worst-case behaviour because it destroys any
adversarial order in the input, ensuring the pivot behaves like a random element.

However, full shuffling has a cost O(N) before sorting and changes the original structure of data,
while random pivot selection keeps input intact and only randomises pivot choice during recursion.
*/

#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

long long comparisons = 0;

void swapFunc(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partitionPlain(vector<int>& a, int lo, int hi) {

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

void quicksortPlain(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;

    int p = partitionPlain(a, lo, hi);
    quicksortPlain(a, lo, p - 1);
    quicksortPlain(a, p + 1, hi);
}

mt19937 rng(42);

int partitionRandom(vector<int>& a, int lo, int hi) {

    uniform_int_distribution<int> dist(lo, hi);
    int randIdx = dist(rng);

    swapFunc(a[lo], a[randIdx]); 

    return partitionPlain(a, lo, hi);
}

void quicksortRandom(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;

    int p = partitionRandom(a, lo, hi);
    quicksortRandom(a, lo, p - 1);
    quicksortRandom(a, p + 1, hi);
}

pair<long long, vector<int>> runPlain(vector<int> a) {
    comparisons = 0;
    quicksortPlain(a, 0, a.size() - 1);
    return {comparisons, a};
}

pair<long long, vector<int>> runRandom(vector<int> a) {
    comparisons = 0;
    quicksortRandom(a, 0, a.size() - 1);
    return {comparisons, a};
}

int main() {

    vector<int> sizes = {100, 200, 400, 800};

    cout << "Sorted input: worst-case demonstration\n";

    for (int n : sizes) {

        vector<int> arr(n);
        for (int i = 0; i < n; i++) arr[i] = i;

        auto plain = runPlain(arr);
        auto rnd = runRandom(arr);

        cout << "n=" << n
             << " plain QS cmp=" << plain.first
             << " random QS cmp=" << rnd.first << endl;
    }

    return 0;
}