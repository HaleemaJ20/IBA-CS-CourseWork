#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

void display(vector<Student>& students) {
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].name << " "
             << students[i].age << " "
             << students[i].gpa << endl;
    }
}

int main() {

    vector<Student> students = {
        {"Alice", 22, 3.9},
        {"Bob", 21, 3.7},
        {"Charlie", 23, 3.5},
    };

    int choice;

    while (true) {
        cout << "\nSort by:\n";
        cout << "1. Name\n2. Age\n3. GPA (High)\n4. GPA (Low)\n";
        cout << "Enter choice (1-4) or 0 to exit: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            sort(students.begin(), students.end(),
                [](Student a, Student b) {
                    return a.name < b.name;
                });
            cout << "\nSorted by Name:\n";
        }

        else if (choice == 2) {
            sort(students.begin(), students.end(),
                [](Student a, Student b) {
                    return a.age < b.age;
                });
            cout << "\nSorted by Age:\n";
        }

        else if (choice == 3) {
            sort(students.begin(), students.end(),
                [](Student a, Student b) {
                    return a.gpa > b.gpa;
                });
            cout << "\nSorted by GPA (Highest first):\n";
        }

        else if (choice == 4) {
            sort(students.begin(), students.end(),
                [](Student a, Student b) {
                    return a.gpa < b.gpa;
                });
            cout << "\nSorted by GPA (Lowest first):\n";
        }

        else {
            cout << "Invalid choice!\n";
            continue;
        }

        display(students);
    }

    return 0;
}