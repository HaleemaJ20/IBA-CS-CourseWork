#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Student {
    string name;
    int exam1, exam2, exam3;
};

int main() {

    vector<Student> students = {
        {"Ali", 60, 70, 65},
        {"Sara", 40, 45, 50},
        {"Ahmed", 80, 75, 85},
        {"Zara", 55, 60, 58},
        {"Bilal", 30, 35, 40},
        {"Hina", 90, 88, 92},
        {"Usman", 50, 52, 48},
        {"Ayesha", 65, 70, 68},
        {"Omar", 45, 50, 55},
        {"Noor", 72, 74, 70}
    };

    cout << "Original students: " << students.size() << endl;

    vector<double> averages;

    transform(students.begin(), students.end(), back_inserter(averages),
        [](Student s) {
            return (s.exam1 + s.exam2 + s.exam3) / 3.0;
        });

    vector<double> passing;

    copy_if(averages.begin(), averages.end(), back_inserter(passing),
        [](double avg) {
            return avg >= 50;
        });

    cout << "Passing students (avg >= 50): " << passing.size() << endl;

    vector<double> bonus;

    transform(passing.begin(), passing.end(), back_inserter(bonus),
        [](double avg) {
            return avg * 1.05;
        });

    cout << "After 5% bonus applied: " << bonus.size() << endl;

    vector<double> honor;

    copy_if(bonus.begin(), bonus.end(), back_inserter(honor),
        [](double avg) {
            return avg >= 60;
        });

    cout << "Honor roll (>= 60 after bonus): " << honor.size() << endl;

    double total = accumulate(honor.begin(), honor.end(), 0.0);
    double finalAvg = total / honor.size();

    cout << "Honor roll average: " << finalAvg << endl;

    return 0;
}