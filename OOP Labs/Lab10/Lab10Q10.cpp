#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Product {
    string name;
    double price;
    int rating;
    int stock;
};

void display(vector<Product>& products) {
    for (int i = 0; i < products.size(); i++) {
        cout << products[i].name << " "
             << products[i].rating << "* "
             << "$" << products[i].price
             << " Stock: " << products[i].stock << endl;
    }
}

int main() {

    vector<Product> products = {
        {"Laptop", 999.99, 5, 5},
        {"Mouse", 25.99, 5, 50},
        {"Keyboard", 79.99, 4, 20},
        {"Monitor", 199.99, 4, 10},
        {"Phone", 699.99, 5, 8},
        {"Tablet", 299.99, 3, 15},
        {"Headphones", 149.99, 4, 25},
        {"Speaker", 89.99, 3, 30}
    };

    int primary, order;

    cout << "Primary: 1-Price 2-Rating 3-Stock\n";
    cin >> primary;

    cout << "Order: 1-Asc 2-Desc\n";
    cin >> order;

    sort(products.begin(), products.end(),
        [primary, order](Product a, Product b) {

            if (primary == 1) { 
                if (a.price != b.price)
                    return (order == 1) ? a.price < b.price : a.price > b.price;
            }

            else if (primary == 2) { 
                if (a.rating != b.rating)
                    return (order == 1) ? a.rating < b.rating : a.rating > b.rating;
            }

            else if (primary == 3) { 
                if (a.stock != b.stock)
                    return (order == 1) ? a.stock < b.stock : a.stock > b.stock;
            }

            return a.name < b.name;
        });

    cout << "\nSorted Result:\n";
    display(products);

    return 0;
}