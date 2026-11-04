#include <iostream>

struct Fraction
{
    int num;
    int denom;
};

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return (a < 0 ? -a : a); 
}

// Task 6 – Simplify
void simplify(Fraction& fraction_value)
{
    int g = gcd(fraction_value.num, fraction_value.denom);
    fraction_value.num /= g;
    fraction_value.denom /= g;

    if (fraction_value.denom < 0)
    {
        fraction_value.denom *= -1;
        fraction_value.num *= -1;
    }
}

// Task 1 – Stream Operator <<
std::ostream& operator<<(std::ostream& output_stream, const Fraction& fraction_value)
{
    output_stream << fraction_value.num << "/" << fraction_value.denom;
    return output_stream;
}

// Task 2 – operator+
Fraction operator+(const Fraction& first_fraction, const Fraction& second_fraction)
{
    Fraction result;
    result.num = first_fraction.num * second_fraction.denom + first_fraction.denom * second_fraction.num;
    result.denom = first_fraction.denom * second_fraction.denom;

    simplify(result);
    return result;
}

// Task 3 – operator+=-
void operator+=(Fraction& first_fraction, const Fraction& second_fraction)
{
    first_fraction.num = first_fraction.num * second_fraction.denom + first_fraction.denom * second_fraction.num;

    first_fraction.denom = first_fraction.denom * second_fraction.denom;

    simplify(first_fraction);
}

// Task 4 – operator*
Fraction operator*(const Fraction& first_fraction, const Fraction& second_fraction)
{
    Fraction result;
    result.num = first_fraction.num * second_fraction.num;
    result.denom = first_fraction.denom * second_fraction.denom;

    simplify(result);
    return result;
}

// Task 5 – operator*=
void operator*=(Fraction& first_fraction, const Fraction& second_fraction)
{
    first_fraction.num *= second_fraction.num;
    first_fraction.denom *= second_fraction.denom;

    simplify(first_fraction);
}

// Task 7 – operator==
bool operator==(const Fraction& first_fraction, const Fraction& second_fraction)
{
    Fraction f1 = first_fraction;
    Fraction f2 = second_fraction;

    simplify(f1);
    simplify(f2);

    return (f1.num == f2.num && f1.denom == f2.denom);
}

int main() {
    Fraction f1{1, 2};
    Fraction f2{3, 4};

    std::cout << "f1 = " << f1 << "\n";
    std::cout << "f2 = " << f2 << "\n";

    auto sum = f1 + f2;
    std::cout << "f1 + f2 = " << sum << "\n";

    f1 += f2;
    std::cout << "f1 after += f2: " << f1 << "\n";

    Fraction f3{1, 2};
    Fraction f4{1, 4};
    auto product = f3 * f4;
    std::cout << "f3 * f4 = " << product << "\n";

    f3 *= f4;
    std::cout << "f3 after *= f4: " << f3 << "\n";

    Fraction f5{1, 2};
    Fraction f6{2, 4};

    if (f5 == f6)
        std::cout << "f5 and f6 are equal\n";
    else
        std::cout << "f5 and f6 are not equal\n";
}
