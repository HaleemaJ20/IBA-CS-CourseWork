#include <iostream>
#include <string>
using namespace std;

struct student{
    string name;
    int age;
    char grade;
};

int main(){
    student profile;
    profile.name = "Haleema";
    profile.age = 19;
    profile.grade = 'A';

    cout << "Name: " << profile.name << '\n' << "Age: " << profile.age << '\n' << "Grade: " << profile.grade; 
}
