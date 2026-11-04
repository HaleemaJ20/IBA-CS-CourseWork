#include <iostream>
using namespace std;

template <typename T>
void mySwap(T &a, T &b) {
    // Using reference (&) avoids copying large objects
    // If passed by value, copies of 'a' and 'b' would be made,
    // which is inefficient for large data types
    // Reference allows direct swapping of original variables which is faster and memory efficient.

    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    mySwap(x, y);
    cout << "x: " << x << " y: " << y << endl;

    double a = 2.5, b = 7.8;
    mySwap(a, b);
    cout << "a: " << a << " b: " << b << endl;

    return 0;
}