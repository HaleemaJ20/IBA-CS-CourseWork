#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;

    Student(int i = 0, string n = "") : id(i), name(n) {}

    bool operator==(const Student &other) const {
        return id == other.id && name == other.name;
    }
};

template <typename T>
T* findFirst(T arr[], int size, T target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return &arr[i];  
        }
    }
    return nullptr; 
}

int main() {
    Student arr[3] = {
        Student(1, "Ali"),
        Student(2, "Sara"),
        Student(3, "Ahmed")
    };

    Student target(2, "Sara");

    auto result = findFirst(arr, 3, target);

    if (result != nullptr) {
        cout << "Found: " << result->name << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}