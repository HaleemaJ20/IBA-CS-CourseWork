#include <iostream>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(string accNo, string name, double bal)
        : accountNumber(accNo), accountHolderName(name), balance(bal) {}

    virtual double calculateInterest() = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void displayAccountInfo() = 0;

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNo, string name, double bal,
                   double rate, double minBal)
        : BankAccount(accNo, name, bal),
          interestRate(rate), minimumBalance(minBal) {}

    double calculateInterest() override {
        return balance * interestRate / 100;
    }

    bool withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void displayAccountInfo() override {
        cout << "\nSavings Account\n";
        cout << "Account No: " << accountNumber << endl;
        cout << "Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%\n";
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNo, string name, double bal,
                   double overdraft)
        : BankAccount(accNo, name, bal),
          overdraftLimit(overdraft) {}

    double calculateInterest() override {
        return 0;   
    }

    bool withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void displayAccountInfo() override {
        cout << "\nCurrent Account\n";
        cout << "Account No: " << accountNumber << endl;
        cout << "Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount {
private:
    double interestRate;
    int maturityPeriodMonths;
    bool isMatured;

public:
    FixedDepositAccount(string accNo, string name, double bal,
                        double rate, int months, bool matured)
        : BankAccount(accNo, name, bal),
          interestRate(rate),
          maturityPeriodMonths(months),
          isMatured(matured) {}

    double calculateInterest() override {
        return balance * interestRate * maturityPeriodMonths / 1200;
    }

    bool withdraw(double amount) override {
        if (isMatured) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void displayAccountInfo() override {
        cout << "\nFixed Deposit Account\n";
        cout << "Account No: " << accountNumber << endl;
        cout << "Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << "%\n";
        cout << "Maturity Period: " << maturityPeriodMonths << " months\n";
        cout << "Matured: " << (isMatured ? "Yes" : "No") << endl;
    }
};

int main() {

    // BankAccount obj("001","Ali",1000);
    // ERROR: Cannot instantiate abstract class
    // because it contains pure virtual functions.

    BankAccount* accounts[4];

    accounts[0] = new SavingsAccount("S001","Ali",5000,5,1000);
    accounts[1] = new CurrentAccount("C001","Sara",3000,2000);
    accounts[2] = new FixedDepositAccount("F001","Ahmed",10000,7,12,true);
    accounts[3] = new FixedDepositAccount("F002","Hina",8000,6,6,false);

    double totalInterest = 0;

    for (int i = 0; i < 4; i++) {

        accounts[i]->deposit(500);

        accounts[i]->displayAccountInfo();

        double interest = accounts[i]->calculateInterest();
        cout << "Interest: " << interest << endl;

        totalInterest += interest;

        if (accounts[i]->withdraw(2000))
            cout << "Withdrawal successful\n";
        else
            cout << "Withdrawal failed\n";
    }

    cout << "\nTotal Interest of all accounts: " << totalInterest << endl;

    for (int i = 0; i < 4; i++) {
        delete accounts[i];
    }

    return 0;
}
