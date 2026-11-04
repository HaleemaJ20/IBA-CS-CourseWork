#include <iostream>
using namespace std;

int binarySearch(const int arr[], int low, int high, int target, int& calls){
    calls++;
    
    if (low > high)
    return -1;

    int mid = low + (high - low) / 2;

    if(arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return binarySearch(arr, low, mid - 1, target, calls);
    else 
        return binarySearch(arr, mid + 1, high, target, calls);
};

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91, 100};
    int size = 12;

    int targets[] = {2, 100, 23, 1, 150, 50};

    for (int i = 0; i < 6; i++){
        int calls = 0;
        int result = binarySearch(arr, 0, size - 1, targets[i], calls);

        if (result != -1)
            cout << "Search " << targets[i] << ": found at index " << result;
        else
            cout << "Search " << targets[i] << ": not found";

        cout << " (calls: " << calls << ")" << endl;
    }

    return 0;
}