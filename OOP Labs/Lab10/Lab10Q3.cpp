#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DiscountCalculator{
private:
    double discount;
    int itemCount;
    double totalOriginal;
    double totalSavings;

public:
    DiscountCalculator(double disc){
        discount = disc;
        itemCount = 0;
        totalOriginal = 0;
        totalSavings = 0;
    }

    void operator()(double price){
        itemCount++;
        totalOriginal += price;

        double saved = price * discount;
        totalSavings += saved;
    }

    void displayStats() const {
        double discountedTotal = totalOriginal - totalSavings;

        cout << "Items: " << itemCount << endl;
        cout << "Original Total: $" << totalOriginal << endl;
        cout << "Discounted Total: $" << discountedTotal << endl;
        cout << "Total Savings: $" << totalSavings << endl;
    }
};

int main(){
    vector<double> prices = {100.0, 250.5, 89.99, 45.0};
    DiscountCalculator calc(0.15); 

    calc = for_each(prices.begin(), prices.end(), calc);

    calc.displayStats();

    return 0;
}