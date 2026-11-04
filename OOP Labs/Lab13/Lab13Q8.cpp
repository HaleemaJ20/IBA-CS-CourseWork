#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;

long long comparisons = 0;

struct Student {
    string name;
    int erp;
    double gpa;
};

void swapFunc(Student &a, Student &b) {
    Student t = a;
    a = b;
    b = t;
}

int partition(vector<Student>& a, int lo, int hi,
              function<bool(const Student&, const Student&)> comp) {

    Student pivot = a[lo];
    int i = lo;
    int j = hi + 1;

    while (true) {

        while (true) {
            i++;
            if (i > hi) break;
            comparisons++;
            if (!comp(a[i], pivot)) break;
        }

        while (true) {
            j--;
            if (j <= lo) break;
            comparisons++;
            if (!comp(pivot, a[j])) break;
        }

        if (i >= j) break;

        swapFunc(a[i], a[j]);
    }

    swapFunc(a[lo], a[j]);
    return j;
}

void quicksort(vector<Student>& a, int lo, int hi,
               function<bool(const Student&, const Student&)> comp) {

    if (lo >= hi) return;

    int p = partition(a, lo, hi, comp);
    quicksort(a, lo, p - 1, comp);
    quicksort(a, p + 1, hi, comp);
}

void printStudents(vector<Student> a) {
    for (auto &s : a) {
        cout << s.name << " " << s.erp << " " << s.gpa << endl;
    }
}

int main() {

    vector<Student> students = {
        {"Ahmed", 29010, 3.45},
        {"Ali", 29184, 3.72},
        {"Fatima", 29055, 3.90},
        {"Zara", 29210, 3.60},
        {"Usman", 28990, 2.90},
        {"Hassan", 29300, 3.10},
        {"Ayesha", 29100, 3.85},
        {"Bilal", 29020, 3.30},
        {"Sara", 29250, 3.95},
        {"Omar", 29080, 3.40}
    };

    vector<Student> byName = students;
    comparisons = 0;

    quicksort(byName, 0, byName.size() - 1,
        [](const Student &a, const Student &b) {
            return a.name < b.name;
        });

    cout << "Sorted by Name:\n";
    printStudents(byName);
    cout << "(comparisons: " << comparisons << ")\n\n";

    vector<Student> byGPA = students;
    comparisons = 0;

    quicksort(byGPA, 0, byGPA.size() - 1,
        [](const Student &a, const Student &b) {
            return a.gpa > b.gpa;
        });

    cout << "Sorted by GPA (Desc):\n";
    printStudents(byGPA);
    cout << "(comparisons: " << comparisons << ")\n\n";

    vector<Student> byERP = students;
    comparisons = 0;

    quicksort(byERP, 0, byERP.size() - 1,
        [](const Student &a, const Student &b) {
            return a.erp < b.erp;
        });

    cout << "Sorted by ERP (Asc):\n";
    printStudents(byERP);
    cout << "(comparisons: " << comparisons << ")\n";

    return 0;
}