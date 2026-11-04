#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num1;
    cout << "Enter numerator for the first fraction: ";
    cin >> num1;

    int den1;
    cout << "Enter denominator for the first fraction: ";
    cin >> den1;
    
    int num2;
    cout << "Enter numerator for the second fraction: ";
    cin >> num2;

    int den2;
    cout << "Enter denominator for the second fraction: ";
    cin >> den2;

    char operation;
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    if (operation == '+') {
        int common_den = den1 * den2;
        int result = (num1 * den2) + (num2 * den1);

        //Simplify the fraction
        int g = result, h = common_den;         // temporary variables
        while (h != 0) {                        // find gcd(result, common_den)
            int temp = h;
            h = g % h;
            g = temp;
        }
        result /= g;                            // Divide by gcd to simplify
        common_den /= g;

        if (common_den < 0) {                   //to move the -ve sign to the numerator
        common_den = -common_den;
        result = -result;
        }

        cout << result << "/" << common_den;
    }

    else if (operation == '-') {
        int common_den = den1 * den2;
        int result = (num1 * den2) - (num2 * den1);

        int g = result, h = common_den;
        while (h != 0) {
            int temp = h;
            h = g % h;
            g = temp;
        }
        result /= g;
        common_den /= g;

        if (common_den < 0) {                   
        common_den = -common_den;
        result = -result;
        }

        cout << result << "/" << common_den;
    }

    else if (operation == '*') {
        int result = num1 * num2;
        int resultd = den1 * den2;

        int g = result, h = resultd;
        while (h != 0) {
            int temp = h;
            h = g % h;
            g = temp;
        }
        result /= g;
        resultd /= g;

        if (resultd < 0) {
        resultd = -resultd;
        result  = -result;
        }


        cout << result << "/" << resultd;     
    }
    else if (operation == '/'){
        int result = num1 * den2;
        int resultd = den1 * num2;

        int g = result, h = resultd;
        while (h != 0) {
            int temp = h;
            h = g % h;
            g = temp;
        }
        result /= g;
        resultd /= g;

        if (resultd < 0) {
        resultd = -resultd;
        result  = -result;
        }

        cout << result << "/" << resultd; 
    }

}