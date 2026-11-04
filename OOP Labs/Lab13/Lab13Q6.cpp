#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;

void merge(vector<int>& a, int lo, int mid, int hi) {

    vector<int> aux(hi - lo + 1);

    int i = lo;       
    int j = mid + 1;  
    int k = 0;

    while (i <= mid && j <= hi) {
        comparisons++;
        if (a[i] <= a[j]) {
            aux[k++] = a[i++];
        } else {
            aux[k++] = a[j++];
        }
    }

    while (i <= mid) {
        aux[k++] = a[i++];
    }

    while (j <= hi) {
        aux[k++] = a[j++];
    }

    for (int x = 0; x < aux.size(); x++) {
        a[lo + x] = aux[x];
    }
}

void mergesort(vector<int>& a, int lo, int hi) {
    if (lo >= hi) return;

    int mid = lo + (hi - lo) / 2;

    mergesort(a, lo, mid);
    mergesort(a, mid + 1, hi);

    merge(a, lo, mid, hi);
}

void printArray(const vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
}

int main() {

    vector<int> v1 = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    vector<int> v2 = {10, 10, 5, 5, 1, 1};

    comparisons = 0;
    mergesort(v1, 0, v1.size() - 1);

    cout << "v1 sorted: ";
    printArray(v1);
    cout << "(comparisons: " << comparisons << ")\n";

    comparisons = 0;
    mergesort(v2, 0, v2.size() - 1);

    cout << "v2 sorted: ";
    printArray(v2);
    cout << "(comparisons: " << comparisons << ")\n";

    return 0;
}