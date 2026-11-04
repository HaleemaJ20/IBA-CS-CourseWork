#include <iostream>
using namespace std;

class Time {
private:
    int* hours;
    int* minutes;

    void normalize() {
        if (*minutes >= 60) {
            *hours += *minutes / 60;
            *minutes = *minutes % 60;
        }
        if (*minutes < 0) {
            *hours = 0;
            *minutes = 0;
        }
    }

public:
    Time(int h = 0, int m = 0) {
        hours = new int(h);
        minutes = new int(m);
        normalize();
    }

    // Copy constructor
    Time(const Time& other) {
        hours = new int(*other.hours);
        minutes = new int(*other.minutes);
    }

    // Destructor
    ~Time() {
        delete hours;
        delete minutes;
    }

    // Assignment operator
    Time& operator=(const Time& other) {
        if (this == &other)
            return *this;

        *hours = *other.hours;
        *minutes = *other.minutes;
        return *this;
    }

    Time operator+(const Time& other) const {
        Time temp(*hours + *other.hours, *minutes + *other.minutes);
        return temp;
    }

    Time operator-(const Time& other) const {
        int total1 = getTotalMinutes();
        int total2 = other.getTotalMinutes();

        if (total1 < total2)
            return Time(0, 0);

        int diff = total1 - total2;
        return Time(diff / 60, diff % 60);
    }

    Time operator*(int factor) const {
        int total = getTotalMinutes() * factor;
        return Time(total / 60, total % 60);
    }

    Time operator/(int divisor) const {
        if (divisor == 0)
            return Time(0, 0);

        int total = getTotalMinutes() / divisor;
        return Time(total / 60, total % 60);
    }

    bool operator==(const Time& other) const {
        return getTotalMinutes() == other.getTotalMinutes();
    }

    bool operator>(const Time& other) const {
        return getTotalMinutes() > other.getTotalMinutes();
    }

    bool operator<(const Time& other) const {
        return getTotalMinutes() < other.getTotalMinutes();
    }

    int getTotalMinutes() const {
        return (*hours * 60) + *minutes;
    }

    double getTotalHours() const {
        return *hours + (*minutes / 60.0);
    }

    void display() const {
        cout << *hours << "h " << *minutes << "m" << endl;
    }
};

int main() {
    Time t1(2, 45);
    Time t2(1, 30);
    Time t3(0, 150);

    cout << "Time 1: "; t1.display();
    cout << "Time 2: "; t2.display();
    cout << "Time 3 (after normalization): "; t3.display();

    Time sum = t1 + t2;
    Time diff = t1 - t2;
    Time doubled = t1 * 2;
    Time halved = t1 / 2;

    cout << "\nSum: "; sum.display();
    cout << "Difference: "; diff.display();
    cout << "Doubled: "; doubled.display();
    cout << "Halved: "; halved.display();

    cout << "\nTotal minutes in t1: " << t1.getTotalMinutes() << endl;
    cout << "Total hours in t1 (decimal): " << t1.getTotalHours() << endl;

    if (t1 > t2) {
        cout << "\nt1 is greater than t2" << endl;
    }

    if (t1 == Time(2, 45)) {
        cout << "t1 equals 2h 45m" << endl;
    }

    cout << "\n--- Testing Copy Constructor ---" << endl;
    Time t4 = t1;
    t4 = t4 + Time(1, 0);
    cout << "Original t1: "; t1.display();
    cout << "Modified copy t4: "; t4.display();

    cout << "\n--- Testing Assignment Operator ---" << endl;
    Time t5(0, 0);
    t5 = t2;
    cout << "Assigned t5: "; t5.display();

    t5 = t5;
    cout << "After self-assignment: "; t5.display();

    return 0;
}
