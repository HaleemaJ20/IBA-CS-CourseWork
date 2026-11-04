#include <iostream>
#include <iomanip>  // for setprecision
#include <cmath>    // only for fabs, not sqrt

using namespace std;

int main() {
    double N;
    cout << "Enter a positive number: ";
    cin >> N;

    double a = 0;
    double b = (N < 1) ? 1 : N;   // handle N < 1 case
    double m;

    while ((b - a) > 0.01) {      // stop when interval is small enough
        m = (a + b) / 2;
        if (m * m > N)
            b = m;
        else
            a = m;
    }

    cout << fixed << setprecision(2);
    cout << "Square root of " << N << " is " << m << endl;

    return 0;
}
