#include <iostream>

int count7(long long n)
{
    int count = 0;
    while (n > 0)
    {
        long long digit = n % 10;
        if (digit == 7)
        {
            count++;
        }
        n = n / 10;
    }
    return count;
}

int main()
{
    long long n;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> n;

    std::cout << "Number of 7s: " << count7(n);
    return 0;
}