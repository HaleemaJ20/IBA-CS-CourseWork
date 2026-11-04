#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class OrderException : public runtime_error {
protected:
    int orderID;
public:
    OrderException(int id, string msg) : runtime_error(msg), orderID(id) {}
    int getOrderID() { return orderID; }
};

class OutOfStockException : public OrderException {
    string productName;
public:
    OutOfStockException(int id, string name)
    : OrderException(id, "Product '" + name + "' is out of stock for order " + to_string(id)) {
        productName = name;
    }
    string getProductName() { return productName; }
};

class PaymentFailedException : public OrderException {
    string reason;
public:
    PaymentFailedException(int id, string r)
    : OrderException(id, "Payment failed for order " + to_string(id) + ": " + r) {
        reason = r;
    }
    string getReason() { return reason; }
};

class DeliveryException : public OrderException {
    string address;
public:
    DeliveryException(int id, string addr)
    : OrderException(id, "Cannot deliver order " + to_string(id) + " to address: " + addr) {
        address = addr;
    }
    string getAddress() { return address; }
};

void checkStock(int orderID, string product, bool inStock) {
    if (!inStock)
        throw OutOfStockException(orderID, product);
}

void processPayment(int orderID, bool paymentSuccess, string reason) {
    if (!paymentSuccess)
        throw PaymentFailedException(orderID, reason);
}

void arrangeDelivery(int orderID, string address, bool deliverable) {
    if (!deliverable)
        throw DeliveryException(orderID, address);
}

void processOrder(int orderID, string product, bool inStock, bool paymentSuccess,
                  string paymentReason, string address, bool deliverable) {

    try {
        checkStock(orderID, product, inStock);
        processPayment(orderID, paymentSuccess, paymentReason);
        arrangeDelivery(orderID, address, deliverable);
        cout << "Order " << orderID << " processed successfully." << endl;
    }
    catch (OrderException &e) {
        cout << "processOrder(): Logging failure for order "
             << orderID << ": " << e.what() << endl;
        throw;
    }
}

int main() {

    try {
        processOrder(1, "Laptop", true, true, "", "Karachi", true);
    }
    catch (...) {}

    try {
        processOrder(2, "Phone", false, true, "", "Karachi", true);
    }
    catch (OutOfStockException &e) {
        cout << e.what() << endl;
        cout << "Product: " << e.getProductName() << endl;
    }
    catch (OrderException &e) {
        cout << e.what() << endl;
    }

    try {
        processOrder(3, "Tablet", true, false, "Card declined", "Lahore", true);
    }
    catch (PaymentFailedException &e) {
        cout << e.what() << endl;
        cout << "Reason: " << e.getReason() << endl;
    }
    catch (OrderException &e) {
        cout << e.what() << endl;
    }

    try {
        processOrder(4, "Headphones", true, true, "", "RemoteArea", false);
    }
    catch (DeliveryException &e) {
        cout << e.what() << endl;
        cout << "Address: " << e.getAddress() << endl;
    }
    catch (OrderException &e) {
        cout << e.what() << endl;
    }

    return 0;
}
