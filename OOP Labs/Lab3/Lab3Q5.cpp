#include <iostream>
using namespace std;

class Distance {
private:
    double meters;

public:
    Distance(double m = 0) : meters(m) {}

    Distance operator+(const Distance& other) const {
        return Distance(meters + other.meters);
    }

    Distance operator-(const Distance& other) const {
        double result = meters - other.meters;
        if (result < 0) result = 0;
        return Distance(result);
    }

    Distance operator*(double factor) const {
        return Distance(meters * factor);
    }

    Distance operator/(double divisor) const {
        if (divisor == 0) return Distance(meters);
        return Distance(meters / divisor);
    }

    bool operator>(const Distance& other) const {
        return meters > other.meters;
    }

    bool operator<(const Distance& other) const {
        return meters < other.meters;
    }

    bool operator==(const Distance& other) const {
        return meters == other.meters;
    }

    operator double() const {
        return meters;
    }

    operator int() const {
        return (int)(meters * 100);
    }

    double toFeet() const {
        return meters * 3.28084;
    }

    double toInches() const {
        return meters * 39.3701;
    }

    void display() const {
        cout << meters << " m, "
             << (int)(meters * 100) << " cm, "
             << toFeet() << " ft, "
             << toInches() << " in" << endl;
    }
};

int main() {
    Distance d1(5.5);
    Distance d2(3.2);

    Distance sum = d1 + d2;
    Distance diff = d1 - d2;
    Distance scaled = d1 * 2;
    Distance halved = d1 / 2;

    cout << "Distance 1: "; d1.display();
    cout << "Distance 2: "; d2.display();
    cout << "Sum: "; sum.display();
    cout << "Difference: "; diff.display();
    cout << "Scaled (x2): "; scaled.display();
    cout << "Halved (/2): "; halved.display();

    double m = d1;
    int cm = d1;

    cout << "\nDistance in meters: " << m << endl;
    cout << "Distance in centimeters: " << cm << endl;
    cout << "Distance in feet: " << d1.toFeet() << endl;
    cout << "Distance in inches: " << d1.toInches() << endl;

    if (d1 > d2) {
        cout << "\nd1 is greater than d2" << endl;
    }

    if (d1 == Distance(5.5)) {
        cout << "d1 equals 5.5 meters" << endl;
    }

    return 0;
}
