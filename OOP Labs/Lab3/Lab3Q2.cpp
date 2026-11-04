#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;
    bool isFrozen;

public:
    BankAccount(string accNum, string name, double initialBalance)
        : accountNumber(accNum), holderName(name), balance(initialBalance), isFrozen(false) {}

    void deposit(double amount) {
        if (!isFrozen && amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (!isFrozen && amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void display() const {
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }

    friend class Auditor;
};

class Auditor {
public:
    void inspectAccount(const BankAccount& account) {
        cout << "Account Number: " << account.accountNumber << endl;
        cout << "Holder Name: " << account.holderName << endl;
        cout << "Balance: " << account.balance << endl;
        cout << "Frozen: " << (account.isFrozen ? "Yes" : "No") << endl;
    }

    bool detectSuspiciousActivity(const BankAccount& account) {
        return (account.balance < 0 || account.balance > 1000000);
    }

    void freezeAccount(BankAccount& account) {
        account.isFrozen = true;
    }

    void unfreezeAccount(BankAccount& account) {
        account.isFrozen = false;
    }
};

int main() {
    BankAccount acc1("ACC001", "Ali Khan", 50000);
    BankAccount acc2("ACC002", "Sara Ahmed", 1500000);

    acc1.deposit(10000);
    acc1.withdraw(5000);
    acc1.display();

    Auditor auditor;
    cout << "\n--- Audit Report ---" << endl;
    auditor.inspectAccount(acc1);

    if (auditor.detectSuspiciousActivity(acc2)) {
        cout << "Suspicious activity detected on ACC002!" << endl;
        auditor.freezeAccount(acc2);
    }

    acc2.withdraw(100);
    auditor.unfreezeAccount(acc2);
    acc2.withdraw(100);

    return 0;
}
