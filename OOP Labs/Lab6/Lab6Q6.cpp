#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string id;
public:
    Person(string n, int a, string i) : name(n), age(a), id(i) {}

    virtual void displayInfo() {
        cout << "ID: " << id << " | Name: " << name << " | Age: " << age << endl;
    }

    string getName() const {
        return name;
    }

    virtual ~Person() {}
};

class MedicalStaff : public Person {
protected:
    string department;
    double baseSalary;
    int yearsOfExperience;
public:
    MedicalStaff(string n, int a, string i, string dept, double salary, int exp)
        : Person(n, a, i), department(dept), baseSalary(salary), yearsOfExperience(exp) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department
             << " | Base Salary: $" << baseSalary
             << " | Experience: " << yearsOfExperience << " years" << endl;
    }

    virtual double calculateSalary() {
        return baseSalary + yearsOfExperience * 500;
    }

    virtual ~MedicalStaff() {}
};

class Doctor final : public MedicalStaff {
private:
    string specialization;
public:
    Doctor(string n, int a, string i, string dept, double salary, int exp, string spec)
        : MedicalStaff(n, a, i, dept, salary, exp), specialization(spec) {}

    void displayInfo() final {
        MedicalStaff::displayInfo();
        cout << "Specialization: " << specialization << endl;
    }

    double calculateSalary() final {
        double sal = MedicalStaff::calculateSalary();
        if (specialization == "Cardiology" || specialization == "Neurology")
            sal += 5000;
        else if (specialization == "Pediatrics" || specialization == "General")
            sal += 2000;
        else
            sal += 3000;
        return sal;
    }
};

class Nurse final : public MedicalStaff {
private:
    string shift;
public:
    Nurse(string n, int a, string i, string dept, double salary, int exp, string sh)
        : MedicalStaff(n, a, i, dept, salary, exp), shift(sh) {}

    void displayInfo() final {
        MedicalStaff::displayInfo();
        cout << "Shift: " << shift << endl;
    }

    double calculateSalary() final {
        double sal = MedicalStaff::calculateSalary();
        if (shift == "Night")
            sal *= 1.3;
        return sal;
    }
};

/*
// Attempting to derive from Doctor 
class Surgeon : public Doctor {
public:
    void displayInfo() override {} // ERROR: overriding final function
};
*/

int main() {
    vector<Person*> staff;

    staff.push_back(new Doctor("Alice", 45, "D101", "Cardiology", 80000, 15, "Cardiology"));
    staff.push_back(new Doctor("Bob", 38, "D102", "Neurology", 75000, 10, "Neurology"));
    staff.push_back(new Doctor("Charlie", 50, "D103", "General", 70000, 20, "General"));

    cout << "\n--- Staff Information ---\n";
    for (auto p : staff)
        p->displayInfo();

    cout << "\n--- Staff Salaries ---\n";
    double totalPayroll = 0;
    Person* highestPaid = nullptr;
    double maxSalary = 0;

    for (auto p : staff) {
        MedicalStaff* ms = dynamic_cast<MedicalStaff*>(p);
        double sal = ms->calculateSalary();
        totalPayroll += sal;

        cout << p->getName() << "'s Salary: $" << sal << endl;

        if (sal > maxSalary) {
            maxSalary = sal;
            highestPaid = p;
        }
    }

    cout << "\nTotal Hospital Payroll: $" << totalPayroll << endl;

    cout << "\nHighest Paid Staff:\n";
    highestPaid->displayInfo();

    cout << "\n--- Doctors ---\n";
    for (auto p : staff)
        if (dynamic_cast<Doctor*>(p))
            p->displayInfo();

    cout << "\n--- Nurses ---\n";
    for (auto p : staff)
        if (dynamic_cast<Nurse*>(p))
            p->displayInfo();

    for (auto p : staff)
        delete p;

    return 0;
}
