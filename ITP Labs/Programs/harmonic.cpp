#include <iostream>

double harmonic_sum(int n)
{
    if (n == 0)
        return 0;

    return (1.0 / n) + harmonic_sum(n - 1);
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    std::cout << "Harmonic sum H(" << n << ") = " << harmonic_sum(n) << std::endl;

    return 0;
}