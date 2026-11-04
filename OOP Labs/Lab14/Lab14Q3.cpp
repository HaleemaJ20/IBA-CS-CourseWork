#include <iostream>
#include <vector>
using namespace std;

bool isSorted(const vector<int>& arr, int i = 0)
{
    if (i == arr.size() - 1)
        return true;

    if (arr[i] > arr[i + 1])
        return false;

    return isSorted(arr, i + 1);
}

int sumDigits(int n)
{
    if (n == 0)
        return 0;

    return n % 10 + sumDigits(n / 10);
}

void printReverse(const vector<int>& arr, int i)
{
    if (i < 0)
        return;

    cout << arr[i] << " ";
    printReverse(arr, i - 1);
}

int countOccurrences(const vector<int>& arr, int val, int i = 0)
{
    if (i == arr.size())
        return 0;

    if (arr[i] == val)
        return 1 + countOccurrences(arr, val, i + 1);

    return countOccurrences(arr, val, i + 1);
}

int main()
{
    vector<int> a1 = {1,2,3,4};
    vector<int> a2 = {3,2,5,6};
    vector<int> a3 = {5,5,5};

    cout << "isSorted:\n";
    cout << isSorted(a1) << endl;
    cout << isSorted(a2) << endl;
    cout << isSorted(a3) << endl;

    cout << "\nsumDigits:\n";
    cout << sumDigits(1234) << endl;
    cout << sumDigits(567) << endl;
    cout << sumDigits(9001) << endl;

    cout << "\nprintReverse:\n";
    printReverse(a1, a1.size()-1); cout << endl;
    printReverse(a2, a2.size()-1); cout << endl;
    printReverse(a3, a3.size()-1); cout << endl;

    cout << "\ncountOccurrences:\n";
    cout << countOccurrences(a1, 2) << endl;
    cout << countOccurrences(a2, 2) << endl;
    cout << countOccurrences(a3, 5) << endl;

    return 0;
}