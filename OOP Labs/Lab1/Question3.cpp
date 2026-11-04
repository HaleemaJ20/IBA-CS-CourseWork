#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) {
        day = d;
        year = y;
        if (m >= 1 && m <= 12)
            month = m;
        else
            month = 1; 
    }

    void setDay(int d) {
        day = d;
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12)
            month = m;
        else
            month = 1; 
    }

    void setYear(int y) {
        year = y;
    }

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    std::string formatDate() {
        return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
    }
};

int main() {
    Date d1(19, 1, 2024);
    std::cout << d1.formatDate() << std::endl; 

    d1.setDay(17);
    std::cout << d1.formatDate() << std::endl; 

    d1.setMonth(5);
    std::cout << d1.formatDate() << std::endl; 

    Date d2(29, 13, 2024); // invalid month, should set to 1
    std::cout << d2.formatDate() << std::endl;

    d2.setYear(2025);
    std::cout << d2.formatDate() << std::endl; 

    return 0;
}
