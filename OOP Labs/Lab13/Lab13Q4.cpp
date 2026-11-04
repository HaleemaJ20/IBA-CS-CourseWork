/*
Median-of-three gives the largest improvement on the reverse-sorted input.

This is because plain Quicksort performs worst when the pivot is consistently
poor (leading to highly unbalanced partitions). Reverse-sorted arrays cause
this worst-case behavior.

Median-of-three avoids this by selecting a better pivot (closer to the true median),
keeping partitions balanced and significantly reducing recursion depth and comparisons.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

long long comparisons = 0;

void swapFunc(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int median3(vector<int>& a, int i, int j, int k) {
    if ((a[i] < a[j] && a[j] < a[k]) || (a[k] < a[j] && a[j] < a[i]))
        return j;
    else if ((a[j] < a[i] && a[i] < a[k]) || (a[k] < a[i] && a[i] < a[j]))
        return i;
    else
        return k;
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
    int p = partition(a, lo, hi);
    quicksort(a, lo, p - 1);
    quicksort(a, p + 1, hi);
}

void quicksortM3(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;

    int mid = lo + (hi - lo) / 2;
    int m = median3(a, lo, mid, hi);

    swapFunc(a[lo], a[m]); 

    int p = partition(a, lo, hi);

    quicksortM3(a, lo, p - 1);
    quicksortM3(a, p + 1, hi);
}

void runTest(vector<int> a, string label, bool useM3) {

    comparisons = 0;

    if (useM3)
        quicksortM3(a, 0, a.size() - 1);
    else
        quicksort(a, 0, a.size() - 1);

    cout << label << " " << comparisons << " ";
}

vector<int> nearlySorted(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i;

    random_device rd;
    mt19937 g(rd());

    for (int i = 0; i < n / 20; i++) {
        int x = g() % n;
        int y = g() % n;
        swap(a[x], a[y]);
    }

    return a;
}

int main() {

    int n = 500;

    vector<int> randomArr(n);
    for (int i = 0; i < n; i++) randomArr[i] = i;

    random_device rd;
    mt19937 g(rd());
    shuffle(randomArr.begin(), randomArr.end(), g);

    vector<int> near = nearlySorted(n);

    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[i] = n - i;

    cout << "n=500\n";
    cout << "Input type       Plain QS   Median-of-three QS\n";

    cout << "Random ";
    runTest(randomArr, "         ", false);
    runTest(randomArr, "     ", true);
    cout << "\n";

    cout << "Nearly Sorted ";
    runTest(near, "  ", false);
    runTest(near, "    ", true);
    cout << "\n";

    cout << "Reverse Sorted ";
    runTest(rev, " ", false);
    runTest(rev, "   ", true);
    cout << "\n";

    return 0;
}