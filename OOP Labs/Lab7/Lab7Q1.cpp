#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

void validateGrade(int grade) {
    if (grade < 0)
        throw invalid_argument("Grade cannot be negative: " + to_string(grade));

    if (grade > 100)
        throw out_of_range("Grade exceeds maximum limit: " + to_string(grade));

    cout << "Grade " << grade << " is valid." << endl;
}

string getLetterGrade(int grade) {
    validateGrade(grade);  

    if (grade >= 90) return "A";
    else if (grade >= 80) return "B";
    else if (grade >= 70) return "C";
    else if (grade >= 60) return "D";
    else return "F";
}

int main() {

    int grades[] = {-5, 110, 95, 72, 58};

    for (int grade : grades) {
        try {
            cout << "Grade " << grade << ": ";
            string letter = getLetterGrade(grade);
            cout << letter << endl;
        }

        catch (invalid_argument& e) {
            cout << "Caught invalid_argument: " << e.what() << endl;
        }

        catch (out_of_range& e) {
            cout << "Caught out_of_range: " << e.what() << endl;
        }

        catch (exception& e) {
            cout << "General exception: " << e.what() << endl;
        }
    }

    return 0;
}
