#include <iostream>

long long factorial(long long n) {
    long long result = 1;
    for (long long i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    long long n;
    std:: cout << "Enter an integer: ";
    std:: cin >> n;

    if (n < 0) {
        std:: cout << "Factorial is not defined for negative numbers.";
    } else {
        std:: cout << n << "! = " << factorial(n);
    }

    return 0;
}


// The largest value of n that can be computed without overflow is 20
