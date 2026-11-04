/*Q1 partitionNoStop performs more comparisons, 
because skipping equal elements creates highly unbalanced partitions, leading to quadratic time. 
This difference disappears on random arrays since duplicates are rare, so both methods produce 
balanced splits. Therefore, partitionStop is preferred as it handles duplicates efficiently
and maintains consistent performance. */

/*Q2 For a random array, the difference between the two partitioning strategies disappears because
 there are very few duplicate elements, so both methods produce balanced partitions and perform a 
 similar number of comparisons.*/

 /*Q3 For a general-purpose sorting algorithm, the partitionStop strategy is preferred because 
 it handles duplicate elements efficiently and maintains balanced partitions, ensuring consistent 
 O(NlogN) performance.*/


#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

int comparisons = 0;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitionStop(vector<int>& arr, int lo, int hi) {
    int pivot = arr[lo];
    int i = lo;
    int j = hi + 1;
    
    while (true) {
        while (true) {
            i++;
            if (i > hi) break;
            comparisons++;  
            if (arr[i] >= pivot) break;  
        }

        while (true) {
            j--;
            if (j <= lo) break;
            comparisons++; 
            if (arr[j] <= pivot) break;  
        }

        if (i >= j) break;

        swap(arr[i], arr[j]);
    }

    swap(arr[lo], arr[j]);
    return j;
}

int partitionNoStop(vector<int>& arr, int lo, int hi) {
    int pivot = arr[lo];  
    int i = lo;
    int j = hi + 1;
    
    while (true) {
        while (true) {
            i++;
            if (i > hi) break;
            comparisons++; 
            if (arr[i] > pivot) break;  
        }

        while (true) {
            j--;
            if (j <= lo) break;
            comparisons++;  
            if (arr[j] < pivot) break;
        }

        if (i >= j) break;

        swap(arr[i], arr[j]);
    }

    swap(arr[lo], arr[j]);
    return j;
}

void quicksortStop(vector<int>& arr, int lo, int hi) {
    if (hi <= lo) return;
    int j = partitionStop(arr, lo, hi);
    quicksortStop(arr, lo, j - 1);
    quicksortStop(arr, j + 1, hi);
}

void quicksortNoStop(vector<int>& arr, int lo, int hi) {
    if (hi <= lo) return;
    int j = partitionNoStop(arr, lo, hi);
    quicksortNoStop(arr, lo, j - 1);
    quicksortNoStop(arr, j + 1, hi);
}

void printArray(const vector<int>& arr) {
    cout << "{";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ",";
    }
    cout << "}";
}

void testBothVersions(vector<int> arr, const string& testName) {
    cout << "\n--- " << testName << " ";
    printArray(arr);
    cout << " ---\n";

    vector<int> arrStop = arr;
    comparisons = 0;
    quicksortStop(arrStop, 0, arrStop.size() - 1);
    cout << "partitionStop comparisons: " << comparisons << "\n";

    vector<int> arrNoStop = arr;
    comparisons = 0;
    quicksortNoStop(arrNoStop, 0, arrNoStop.size() - 1);
    cout << "partitionNoStop comparisons: " << comparisons << "\n";

    if (arrStop != arrNoStop) {
        cout << "ERROR: Sorted arrays don't match!\n";
    }
}
 
int main() {
    vector<int> allEqual = {5, 5, 5, 5, 5, 5, 5, 5};
    vector<int> halfEqual = {3, 5, 3, 5, 3, 5, 3, 5};
    vector<int> random8 = {4, 2, 7, 1, 9, 3, 6, 8};

    testBothVersions(allEqual, "All Equal");
    testBothVersions(halfEqual, "Half Equal");
    testBothVersions(random8, "Random");

    //Exercise 2
    vector<int> sizes = {8, 16, 32, 64, 128, 256};

    cout << "\n--- Exercise 2: Scaling Study ---\n";

    for (int n : sizes) {

        vector<int> arr(n, 5);

        comparisons = 0;
        vector<int> a = arr;
        quicksortStop(a, 0, n - 1);
        int stopCount = comparisons;

        comparisons = 0;
        vector<int> b = arr;
        quicksortNoStop(b, 0, n - 1);
        int noStopCount = comparisons;

        cout << "n = " << n
             << " stop = " << stopCount
             << " noStop = " << noStopCount
             << endl;
    }

    return 0;
}

 /*
    Growth pattern:
    The partitionStop version grows much more slowly and behaves roughly like O(N log N),
    because duplicates are distributed across both partitions, keeping recursion balanced.

    The partitionNoStop version grows much faster, approximately O(N²),
    because all equal elements go into one partition, creating highly unbalanced recursion.

    Ratio estimate (n = 256):
    noStop grows roughly proportional to N², while stop grows like N log N.
    So the ratio noStop / stop becomes very large (close to linear in N),
    which matches the theoretical prediction that noStop degrades toward ½N²
    while stop stays near N log N.
 */
