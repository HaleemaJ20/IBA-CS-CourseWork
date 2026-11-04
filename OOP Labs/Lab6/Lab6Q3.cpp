#include <iostream>
using namespace std;

class IPaymentProcessor {
public:
    virtual bool processPayment(double amount) = 0;
    virtual bool refundPayment(double amount) = 0;
    virtual void displayPaymentDetails() = 0;
    virtual string getPaymentMethod() = 0;
    virtual ~IPaymentProcessor() {}
};

class CreditCardProcessor : public IPaymentProcessor {
private:
    string cardNumber;
    string cardHolderName;
    string expiryDate;
    string cvv;
    double balance;

public:
    CreditCardProcessor(string num, string name, string exp, string c,
                        double bal)
        : cardNumber(num), cardHolderName(name),
          expiryDate(exp), cvv(c), balance(bal) {}

    bool processPayment(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    bool refundPayment(double amount) override {
        balance += amount;
        return true;
    }

    void displayPaymentDetails() override {
        cout << "Credit Card (****"
             << cardNumber.substr(cardNumber.length() - 4)
             << ")\nHolder: " << cardHolderName
             << "\nBalance: " << balance << endl;
    }

    string getPaymentMethod() override {
        return "Credit Card";
    }
};

class DebitCardProcessor : public IPaymentProcessor {
private:
    string cardNumber;
    string accountHolderName;
    string bankName;
    double availableBalance;

public:
    DebitCardProcessor(string num, string name,
                       string bank, double bal)
        : cardNumber(num), accountHolderName(name),
          bankName(bank), availableBalance(bal) {}

    bool processPayment(double amount) override {
        double total = amount + (amount * 0.02);
        if (availableBalance >= total) {
            availableBalance -= total;
            return true;
        }
        return false;
    }

    bool refundPayment(double amount) override {
        double total = amount + (amount * 0.02);
        availableBalance += total;
        return true;
    }

    void displayPaymentDetails() override {
        cout << "Debit Card (****"
             << cardNumber.substr(cardNumber.length() - 4)
             << ")\nBank: " << bankName
             << "\nAvailable Balance: "
             << availableBalance << endl;
    }

    string getPaymentMethod() override {
        return "Debit Card";
    }
};

class MobileWalletProcessor : public IPaymentProcessor {
private:
    string walletID;
    string phoneNumber;
    string walletProvider;
    double walletBalance;

public:
    MobileWalletProcessor(string id, string phone,
                          string provider, double bal)
        : walletID(id), phoneNumber(phone),
          walletProvider(provider), walletBalance(bal) {}

    bool processPayment(double amount) override {
        if (walletBalance >= amount) {
            walletBalance -= amount;
            walletBalance += amount * 0.05; 
            return true;
        }
        return false;
    }

    bool refundPayment(double amount) override {
        walletBalance += amount;
        return true;
    }

    void displayPaymentDetails() override {
        cout << "Mobile Wallet (" << walletProvider
             << ")\nWallet ID: " << walletID
             << "\nBalance: " << walletBalance << endl;
    }

    string getPaymentMethod() override {
        return "Mobile Wallet";
    }
};

class PaymentGateway {
public:
    void processTransaction(IPaymentProcessor* processor,
                            double amount,
                            double &totalSuccess) {

        cout << "\nUsing: "
             << processor->getPaymentMethod() << endl;

        if (processor->processPayment(amount)) {
            cout << "Payment of " << amount
                 << " successful.\n";
            totalSuccess += amount;
        } else {
            cout << "Payment failed (insufficient balance).\n";
        }

        processor->displayPaymentDetails();
    }
};

int main() {

    IPaymentProcessor* payments[3];

    payments[0] = new CreditCardProcessor(
        "1234567890123456", "Ali", "12/28", "123", 5000);

    payments[1] = new DebitCardProcessor(
        "9876543210987654", "Sara", "HBL", 3000);

    payments[2] = new MobileWalletProcessor(
        "W001", "03001234567", "PayPal", 2000);

    PaymentGateway gateway;

    double totalSuccessfulTransactions = 0;

    gateway.processTransaction(payments[0], 1000, totalSuccessfulTransactions);
    gateway.processTransaction(payments[1], 500, totalSuccessfulTransactions);
    gateway.processTransaction(payments[2], 1000, totalSuccessfulTransactions);
    gateway.processTransaction(payments[2], 5000, totalSuccessfulTransactions);

    cout << "\nProcessing Refund of 500...\n";
    payments[0]->refundPayment(500);
    payments[0]->displayPaymentDetails();

    cout << "\nTotal Successful Transaction Amount: "
         << totalSuccessfulTransactions << endl;

    cout << "\nFinal Payment Method Details:\n";
    for (int i = 0; i < 3; i++) {
        payments[i]->displayPaymentDetails();
    }

    for (int i = 0; i < 3; i++) {
        delete payments[i];
    }

    return 0;
}
