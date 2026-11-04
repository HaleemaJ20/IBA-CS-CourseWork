#include <iostream>
#include <string>
#include <exception>
using namespace std;

class HospitalException : public exception {
protected:
    string message;
    int errorCode;

public:
    HospitalException(string m, int code) {
        message = m;
        errorCode = code;
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    int getErrorCode() {
        return errorCode;
    }
};

class PatientNotFoundException : public HospitalException {
    int patientID;

public:
    PatientNotFoundException(int id)
    : HospitalException("Patient not found with ID: " + to_string(id), 404) {
        patientID = id;
    }
};

class InvalidAgeException : public HospitalException {
    int age;

public:
    InvalidAgeException(int a)
    : HospitalException("Invalid patient age: " + to_string(a) + ". Must be between 0 and 150.", 400) {
        age = a;
    }
};

class WardFullException : public HospitalException {
    string wardName;

public:
    WardFullException(string w)
    : HospitalException("Ward " + w + " is full. Cannot admit more patients.", 503) {
        wardName = w;
    }
};

class Hospital {
    string wardName;
    int capacity;
    int currentPatients;

public:
    Hospital(string w, int c) {
        wardName = w;
        capacity = c;
        currentPatients = 0;
    }

    void registerPatient(int id, string name, int age) {
        if (age < 0 || age > 150)
            throw InvalidAgeException(age);

        if (currentPatients >= capacity)
            throw WardFullException(wardName);

        currentPatients++;
        cout << "Patient " << name << " registered successfully." << endl;
    }

    void findPatient(int id) {
        if (id < 1 || id > 100)
            throw PatientNotFoundException(id);

        cout << "Patient " << id << " found." << endl;
    }
};

int main() {

    Hospital h("General", 3);

    try {
        h.registerPatient(1, "Ali", -5);
    }
    catch (InvalidAgeException &e) {
        cout << e.what() << " Code: " << e.getErrorCode() << endl;
    }
    catch (HospitalException &e) {
        cout << e.what() << " Code: " << e.getErrorCode() << endl;
    }

    try {
        h.registerPatient(1, "Sara", 25);
        h.registerPatient(2, "Ahmed", 30);
        h.registerPatient(3, "Hina", 28);
        h.registerPatient(4, "Zara", 40);
    }
    catch (WardFullException &e) {
        cout << e.what() << " Code: " << e.getErrorCode() << endl;
    }
    catch (HospitalException &e) {
        cout << e.what() << " Code: " << e.getErrorCode() << endl;
    }

    try {
        h.findPatient(200);
    }
    catch (PatientNotFoundException &e) {
        cout << e.what() << " Code: " << e.getErrorCode() << endl;
    }
    catch (HospitalException &e) {
        cout << e.what() << " Code: " << e.getErrorCode() << endl;
    }

    return 0;
}
