#include <iostream>
using namespace std;

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}


int main() {

    float (*operations[4])(float, float) = {add, subtract, multiply, divide};

    int choice;
    float num1, num2;

    while (true) {
        cout << "\nCalculator Menu:\n";
        cout << "0. Add\n";
        cout << "1. Subtract\n";
        cout << "2. Multiply\n";
        cout << "3. Divide\n";
        cout << "Enter choice (0-3) or -1 to exit: ";
        cin >> choice;

        if (choice == -1) break;

        if (choice < 0 || choice > 3) {
            cout << "Invalid choice!" << endl;
            continue;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        if (choice == 3 && num2 == 0) {
            cout << "Error: Division by zero!" << endl;
        } else {
            float result = operations[choice](num1, num2);
            cout << "Result: " << result << endl;
        }
    }

    return 0;
}