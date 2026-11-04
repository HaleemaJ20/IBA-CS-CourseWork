#include <iostream>
#include <string>

class Student {
private:
    std::string erpId;
    std::string name;
    double cgpa;
    std::string phone;

    static int m_count;

public:
    // Constructor declaration
    Student(std::string name, double cgpa, std::string phone);

    //Getters
    std::string getErpId();
    std::string getName();
    double getCgpa();
    std::string getPhone();

    // Setters
    void setName(std::string name);
    void setCgpa(double cgpa);
    void setPhone(std::string phone);

    void print();
};

int Student::m_count = 32432;

//Constructor definition
Student::Student(std::string name, double cgpa, std::string phone) {
    erpId = std::to_string(++m_count);
    this->name = name;
    this->cgpa = 0.0;
    this->phone = "00000000000";

    setCgpa(cgpa);
    setPhone(phone);
}

//Getters
std::string Student::getErpId() { return erpId; }
std::string Student::getName() { return name; }
double Student::getCgpa() { return cgpa; }
std::string Student::getPhone() { return phone; }

//Setters
void Student::setName(std::string name) {
    this->name = name;
}

void Student::setCgpa(double cgpa) {
    if (cgpa >= 0.0 && cgpa <= 4.0)
        this->cgpa = cgpa;
    else
        std::cout << "Updated CGPA is invalid! Must be between 0.0 and 4.0\n";
}

void Student::setPhone(std::string phone) {
    if (phone.length() == 11) {
        bool valid = true;
        for (char c : phone) {
            if (!std::isdigit(c)) {
                valid = false;
                break;
            }
        }
        if (valid)
            this->phone = phone;
        else
            std::cout << "Updated phone number is invalid! Must contain only digits\n";
    } else {
        std::cout << "Updated phone number is invalid! Must be exactly 11 digits\n";
    }
}

void Student::print() {
    std::cout << "ERP ID: " << erpId << "\n";
    std::cout << "Name  : " << name << "\n";
    std::cout << "CGPA  : " << cgpa << "\n";
    std::cout << "Phone : " << phone << "\n";
}

int main() {

    Student s1("Haleema", 3.2, "03001234567");

    s1.setCgpa(5.5);

    s1.setPhone("12345");

    std::cout << "\nNew updated values:\n";
    std:: cout << "Student 1 Data:\n";
    s1.setCgpa(3.8);
    s1.setPhone("03111222333");

    s1.print();
    std:: cout << std:: endl;

    Student s2("Ayesha", 3.2, "03001234567");

    std:: cout << "Student 2 Data:\n";
    s2.setCgpa(3.5);
    s2.setPhone("03111222444");

    s2.print();


    return 0;
}
