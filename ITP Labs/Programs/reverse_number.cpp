#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a 5-digit number: ";
    cin >> num;
    
    int d1, d2, d3, d4, d5;
    d1 = num % 10;
    d2 = (num/10) % 10;
    d3 = (num/100) % 10;
    d4 = (num/1000) % 10;
    d5 = (num/10000) % 10;

    cout << "Your number " << num << " " << "in reversed order is " << d1 << d2 << d3 << d4 << d5;
    return 0;
}