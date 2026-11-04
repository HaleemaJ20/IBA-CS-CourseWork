#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double c = 0) : celsius(c) {}

    operator double() const {
        return celsius;
    }

    operator int() const {
        return (int)celsius;
    }

    friend double toFahrenheit(const Temperature& t);

    void display() const {
        cout << "Celsius: " << celsius << endl;
        cout << "Fahrenheit: " << (celsius * 9 / 5 + 32) << endl;
    }
};

double toFahrenheit(const Temperature& t) {
    return t.celsius * 9 / 5 + 32;
}

int main() {
    Temperature t1(25.5);
    Temperature t2(100);
    Temperature t3(-40);

    t1.display();
    t2.display();
    t3.display();

    double c = t1;
    int ci = t1;

    cout << "Temperature in Celsius (double): " << c << endl;
    cout << "Temperature in Celsius (int): " << ci << endl;
    cout << "Temperature in Fahrenheit: " << toFahrenheit(t1) << endl;

    return 0;
}
