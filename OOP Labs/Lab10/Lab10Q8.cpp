#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Order {
    int quantity;
    double pricePerItem;
    string customerType;
};

int main() {

    vector<Order> orders = {
        {2, 50, "regular"},
        {1, 120, "premium"},
        {3, 40, "regular"},
        {5, 30, "premium"},
        {4, 60, "regular"},
        {2, 80, "premium"},
        {1, 90, "regular"},
        {6, 25, "premium"}
    };

    cout << "Total orders: " << orders.size() << endl;

    vector<double> totals;

    transform(orders.begin(), orders.end(), back_inserter(totals),
        [](Order o) {
            return o.quantity * o.pricePerItem;
        });

    cout << "After calculating totals: " << totals.size() << " orders\n";

    vector<double> discounted;

    for (int i = 0; i < orders.size(); i++) {
        double price = totals[i];

        if (orders[i].customerType == "premium") {
            price = price * 0.9; 
        }

        discounted.push_back(price);
    }

    cout << "After discounts: " << discounted.size() << " orders\n";

    vector<double> filtered;

    copy_if(discounted.begin(), discounted.end(), back_inserter(filtered),
        [](double x) {
            return x > 100;
        });

    cout << "After filtering (>$100): " << filtered.size() << " orders\n";

    double revenue = accumulate(filtered.begin(), filtered.end(), 0.0);

    cout << "Total Revenue: $" << revenue << endl;

    return 0;
}