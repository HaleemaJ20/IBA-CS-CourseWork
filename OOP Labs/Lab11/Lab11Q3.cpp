#include <iostream>
#include <iomanip>
using namespace std;

struct Card {
    int value;
    char suit;
};

int binarySearchPosition(const int arr[], int low, int high, int target, int& cmp) {
    if (low > high)
        return low;

    int mid = (low + high) / 2;
    cmp++;

    if (arr[mid] <= target)
        return binarySearchPosition(arr, mid + 1, high, target, cmp);
    else
        return binarySearchPosition(arr, low, mid - 1, target, cmp);
}

/*
Binary insertion sort uses binary search to find the insertion position
in O(log n) comparisons instead of scanning one by one, so the total
comparison count drops from O(n^2) to O(n log n). The shifts stay O(n^2)
though because we still have to move every element between pos and i
to the right regardless of how we found pos.
It is preferred over standard insertion sort when comparisons are expensive,
like sorting complex objects or structs where comparing two elements is costly.
*/
void binaryInsertionSort(int arr[], int n, int& cmp) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int pos = binarySearchPosition(arr, 0, i - 1, key, cmp);

        for (int j = i; j > pos; j--) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
    cout << "Binary Insertion Sort comparisons: " << cmp << endl;
}

void standardInsertionSort(int arr[], int n, int& cmp) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            cmp++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    cout << "Standard Insertion Sort comparisons: " << cmp << endl;
}

int main() {
    int original[] = { 42, 7, 19, 7, 55, 3, 19, 88, 3, 61, 27, 42, 14, 99, 27 };
    int n = 15;

    int arr1[15];
    int arr2[15];
    for (int i = 0; i < n; i++) arr1[i] = original[i];
    for (int i = 0; i < n; i++) arr2[i] = original[i];

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << original[i] << " ";
    cout << endl << endl;

    int cmp1 = 0;
    standardInsertionSort(arr1, n, cmp1);
    cout << "Standard Sorted: ";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    cout << endl << endl;

    int cmp2 = 0;
    binaryInsertionSort(arr2, n, cmp2);
    cout << "Binary Sorted: ";
    for (int i = 0; i < n; i++) cout << arr2[i] << " ";
    cout << endl << endl;

    double reduction = (double)(cmp1 - cmp2) / cmp1 * 100.0;

    cout << "Standard Insertion Sort comparisons : " << cmp1 << endl;
    cout << "Binary Insertion Sort comparisons   : " << cmp2 << endl;
    cout << fixed << setprecision(1);
    cout << "Reduction: " << reduction << "%" << endl;

    return 0;
}