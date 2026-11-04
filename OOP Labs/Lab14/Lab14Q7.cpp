#include <iostream>
#include <vector>
using namespace std;

int maxDepth = 0;
long long fibCalls = 0;

void updateDepth(int depth)
{
    if (depth > maxDepth)
        maxDepth = depth;
}

long long factorial(int n, int depth = 1)
{
    updateDepth(depth);

    if (n == 0)
        return 1;

    return n * factorial(n - 1, depth + 1);
}

int binarySearch(vector<int>& arr, int left, int right, int key, int depth = 1)
{
    updateDepth(depth);

    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, left, mid - 1, key, depth + 1);

    return binarySearch(arr, mid + 1, right, key, depth + 1);
}

void mergeSort(vector<int>& arr, int left, int right, int depth = 1)
{
    updateDepth(depth);

    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, depth + 1);
    mergeSort(arr, mid + 1, right, depth + 1);
}

long long fibNaive(int n, int depth = 1)
{
    updateDepth(depth);
    fibCalls++;

    if (n <= 1)
        return n;

    return fibNaive(n - 1, depth + 1) + fibNaive(n - 2, depth + 1);
}

int main()
{
    cout << "Function/Input\tMeasured depth\n";

    maxDepth = 0;
    factorial(10);
    cout << "factorial(10)\t" << maxDepth << endl;

    maxDepth = 0;
    factorial(100);
    cout << "factorial(100)\t" << maxDepth << endl;

    maxDepth = 0;
    factorial(1000);
    cout << "factorial(1000)\t" << maxDepth << endl;

    vector<int> arr1(1000000);
    for (int i = 0; i < 1000000; i++) arr1[i] = i;

    maxDepth = 0;
    binarySearch(arr1, 0, arr1.size()-1, 999999);
    cout << "binarySearch\t" << maxDepth << endl;

    vector<int> arr2(1024);

    maxDepth = 0;
    mergeSort(arr2, 0, arr2.size()-1);
    cout << "mergeSort\t" << maxDepth << endl;

    for (int n : {5,10,15})
    {
        maxDepth = 0;
        fibCalls = 0;
        fibNaive(n);
        cout << "fib(" << n << ")\t\t" << maxDepth << "    calls = " << fibCalls << endl;
    }

    return 0;
}

/*
| Function / input      | Measured max depth | Theoretical depth |
| --------------------- | ------------------ | ----------------- |
| factorial(10)         |                 11 |                10 |
| factorial(100)        |                101 |               100 |
| factorial(1000)       |               1001 |              1000 |
| binarySearch(1000000) |                 20 |                20 |
| mergeSort(1024)       |                 11 |                10 |
| fibNaive(5)           |                  5 |                 5 |
| fibNaive(10)          |                 10 |                10 |
| fibNaive(15)          |                 15 |                15 |
*/

/*
Do measurements match?
Mostly yes. Some are one greater because depth counting started from 1 instead of 0, 
so base call adds one extra level. The growth pattern matches theory.*/