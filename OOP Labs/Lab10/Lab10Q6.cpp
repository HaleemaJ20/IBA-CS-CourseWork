#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Expense {
    double amount;
    string category;
};


int main() {

    vector<Expense> expenses = {
        {75.5, "food"},
        {20.0, "transport"},
        {120.0, "entertainment"},
        {45.0, "food"},
        {60.0, "transport"},
        {30.0, "food"},
        {150.0, "entertainment"},
        {25.0, "transport"}
    };

    double threshold = 50;
    vector<Expense> filtered;

    copy_if(expenses.begin(), expenses.end(), back_inserter(filtered),
        [threshold](Expense e) {
            return e.amount > threshold;
        });

    cout << "Expenses above $" << threshold << ":\n";
    for (int i = 0; i < filtered.size(); i++) {
        cout << filtered[i].category << ": $" << filtered[i].amount << endl;
    }

    string target = "food";
    vector<Expense> foodExpenses;

    copy_if(expenses.begin(), expenses.end(), back_inserter(foodExpenses),
        [target](Expense e) {
            return e.category == target;
        });

    int count = count_if(expenses.begin(), expenses.end(),
        [target](Expense e) {
            return e.category == target;
        });

    cout << "\nFood expenses count: " << count << endl;

    double maxAmount = 0;

    for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].category == target && expenses[i].amount > maxAmount) {
            maxAmount = expenses[i].amount;
        }
    }

    cout << "Most expensive in " << target << " category: $" << maxAmount << endl;

    return 0;
}