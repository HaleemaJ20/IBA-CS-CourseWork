#include <iostream>
#include <string>
using namespace std;

int main() {
    int score;
    cout << "Enter your exam score: ";
    cin >> score;

    string ECA, behavior;
    cout << "Did you participate in extracurricular activities (yes/no): ";
    cin >> ECA;

    cout << "Did you have good behavior during the term (yes/no): ";
    cin >> behavior;

    // Apply bonuses
    if (ECA == "yes") score += 5;
    if (behavior == "yes") score += 5;

    // Cap score at 100
    if (score > 100) score = 100;

    cout << "Final exam score (after bonus): " << score << endl;

    string grade;

    if (score < 50) grade = "F";
    else if (score >= 90) grade = "A";
    else if (score >= 80) grade = "A-";
    else if (score >= 70) grade = "B";
    else if (score >= 60) grade = "C";
    else grade = "D";

    cout << "Your final grade is: " << grade << endl;

    return 0;
}
