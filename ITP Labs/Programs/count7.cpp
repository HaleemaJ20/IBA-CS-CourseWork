#include <iostream>

int count7(int n)
{
    if (n == 0)
        return 0;

    int lastDigit = n % 10;

    if (lastDigit == 7)
        return 1 + count7(n / 10);
    else
        return count7(n / 10);
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "Number of 7s: " << count7(n) << std::endl;

    return 0;
}
