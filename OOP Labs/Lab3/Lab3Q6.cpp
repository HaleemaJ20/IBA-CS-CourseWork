#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    string erpId;
    double* grades;
    int numCourses;
    double cgpa;

public:
    Student(string n, string id, int courses) {
        name = n;
        erpId = id;
        numCourses = courses;
        cgpa = 0;

        grades = new double[numCourses];
        for (int i = 0; i < numCourses; i++) {
            grades[i] = 0;
        }
    }

    // Copy constructor (deep copy)
    Student(const Student& other) {
        name = other.name;
        erpId = other.erpId;
        numCourses = other.numCourses;
        cgpa = other.cgpa;

        grades = new double[numCourses];
        for (int i = 0; i < numCourses; i++) {
            grades[i] = other.grades[i];
        }
    }

    // Destructor
    ~Student() {
        delete[] grades;
    }

    // Assignment operator
    Student& operator=(const Student& other) {
        if (this == &other)
            return *this;

        delete[] grades;

        name = other.name;
        erpId = other.erpId;
        numCourses = other.numCourses;
        cgpa = other.cgpa;

        grades = new double[numCourses];
        for (int i = 0; i < numCourses; i++) {
            grades[i] = other.grades[i];
        }

        return *this;
    }

    void setGrade(int courseIndex, double grade) {
        if (courseIndex >= 0 && courseIndex < numCourses && grade >= 0 && grade <= 100) {
            grades[courseIndex] = grade;
        }
    }

    void calculateCGPA() {
        double sum = 0;
        for (int i = 0; i < numCourses; i++) {
            sum += grades[i];
        }
        cgpa = sum / numCourses;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "ERP ID: " << erpId << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Grades: ";
        for (int i = 0; i < numCourses; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }

    string getName() const { return name; }
    string getErpId() const { return erpId; }
    double getCGPA() const { return cgpa; }
    int getNumCourses() const { return numCourses; }

    double getGrade(int index) const {
        if (index >= 0 && index < numCourses)
            return grades[index];
        return 0;
    }

    double getHighestGrade() const {
        double max = grades[0];
        for (int i = 1; i < numCourses; i++) {
            if (grades[i] > max)
                max = grades[i];
        }
        return max;
    }

    double getLowestGrade() const {
        double min = grades[0];
        for (int i = 1; i < numCourses; i++) {
            if (grades[i] < min)
                min = grades[i];
        }
        return min;
    }

    int countFailingGrades() const {
        int count = 0;
        for (int i = 0; i < numCourses; i++) {
            if (grades[i] < 50)
                count++;
        }
        return count;
    }
};

int main() {
    Student s1("Ali Ahmed", "26184", 5);
    s1.setGrade(0, 85);
    s1.setGrade(1, 90);
    s1.setGrade(2, 78);
    s1.setGrade(3, 92);
    s1.setGrade(4, 88);
    s1.calculateCGPA();

    cout << "--- Student Information ---" << endl;
    s1.display();

    cout << "\n--- Grade Analysis ---" << endl;
    cout << "Highest Grade: " << s1.getHighestGrade() << endl;
    cout << "Lowest Grade: " << s1.getLowestGrade() << endl;
    cout << "Failing Courses: " << s1.countFailingGrades() << endl;

    cout << "\n--- Testing Deep Copy ---" << endl;
    Student s2 = s1;
    s2.setGrade(0, 95);
    s2.calculateCGPA();

    cout << "\nOriginal Student (s1):" << endl;
    s1.display();
    cout << "\nCopied Student (s2) after modification:" << endl;
    s2.display();

    cout << "\n--- Testing Assignment Operator ---" << endl;
    Student s3("Sara Khan", "26185", 5);
    s3 = s1;
    s3.setGrade(1, 100);
    s3.calculateCGPA();

    cout << "\nOriginal (s1):" << endl;
    s1.display();
    cout << "\nAssigned (s3) after modification:" << endl;
    s3.display();

    s3 = s3;
    cout << "\nAfter self-assignment, s3:" << endl;
    s3.display();

    return 0;
}
