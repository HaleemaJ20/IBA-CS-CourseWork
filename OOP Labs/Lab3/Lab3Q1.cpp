#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Arithmetic operators
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // Casting operators
    operator double() const {
        return std::sqrt(real * real + imag * imag);
    }

    operator int() const {
        return static_cast<int>(real);
    }

    // Friend functions
    friend double magnitude(const Complex& c);
    friend void display(const Complex& c);
};

// Friend function to calculate magnitude
double magnitude(const Complex& c) {
    return std::sqrt(c.real * c.real + c.imag * c.imag);
}

// Friend function to display complex number
void display(const Complex& c) {
    std::cout << c.real;
    if (c.imag >= 0) {
        std::cout << " + " << c.imag << "i";
    } else {
        std::cout << " - " << -c.imag << "i";
    }
    std::cout << std::endl;
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    std::cout << "c1: ";
    display(c1);

    std::cout << "c2: ";
    display(c2);

    std::cout << "Sum: ";
    display(sum);

    std::cout << "Difference: ";
    display(diff);

    std::cout << "Product: ";
    display(prod);

    double mag = c1;   // Casting to double
    int r = c1;        // Casting to int

    std::cout << "Magnitude of c1: " << mag << std::endl;
    std::cout << "Real part of c1 (as int): " << r << std::endl;
    std::cout << "Magnitude using friend: " << magnitude(c1) << std::endl;

    return 0;
}
