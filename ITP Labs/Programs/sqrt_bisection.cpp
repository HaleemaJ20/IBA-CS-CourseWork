#include <iostream>
#include <iomanip>   
#include <cmath>     

using namespace std;

int main() {
    double N;
    cout << "Enter a positive number: ";
    cin >> N;

    double a = 0;
    double b;           
    if (N < 1)
        b = 1;          
    else
        b = N;         

    double m;

    while ((b - a) > 0.01) {        
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
