#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPangram(const std::string& sentence){
    bool seen[26] = {false};
    int count = 0;

    for (char c : sentence){
        if (isalpha(c)){
            c = tolower(c);
            int index = c - 'a';
            if (!seen[index]){
                seen [index] = true;
                count++;
            }
        }
    }
    return count == 26;
}

int main(){
    string s1 = "A quick brown fox jumps over the lazy dog";
    string s2 = "Hello World";

    cout << s1 << ": " << (isPangram(s1) ? "yes" : "no") << endl;
    cout << s2 << ": " <<  (isPangram(s2) ? "yes" : "no") << endl;

    return 0;
}
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