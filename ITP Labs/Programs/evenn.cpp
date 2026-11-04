//Write a program count_even.cpp that reads 10 integer values from input, stores them in an array, and prints the count of even integers.
#include <iostream>
using namespace std;
int main()
{
    int num = {10};
    int arr[num];
    int even = 0;

    cout << "Enter 10 integers: ";

    for (int i = 0; i <= num; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            even++;
        }
    }

    cout << "Count of even integers is: " << even;

}