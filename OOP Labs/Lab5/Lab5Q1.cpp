#include <iostream>
#include <string>
using namespace std;

//BASE CLASS 

class BankAccount {
protected:
    string accountHolderName;
    double balance;

private:
    string accountNumber;

public:
    BankAccount(string name, double bal, string accNum)
        : accountHolderName(name), balance(bal), accountNumber(accNum) {
        cout << "BankAccount constructor called" << endl;
    }

    void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

//PART A

class SavingsAccount : public BankAccount {
private:
    int withdrawalLimit;
    int withdrawalsThisMonth;
    double minimumBalance;

public:
    SavingsAccount(string name, double bal, string accNum,
                   int limit, double minBal)
        : BankAccount(name, bal, accNum),
          withdrawalLimit(limit),
          withdrawalsThisMonth(0),
          minimumBalance(minBal) {
        cout << "SavingsAccount constructor called" << endl;
    }

    void makeWithdrawal(double amount) {
        if (withdrawalsThisMonth >= withdrawalLimit) {
            cout << "Withdrawal limit exceeded!" << endl;
            return;
        }

        if (withdraw(amount)) {
            withdrawalsThisMonth++;
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void resetMonthlyWithdrawals() {
        withdrawalsThisMonth = 0;
    }

    void displaySavingsInfo() const {
        displayAccountInfo();
        cout << "Withdrawal Limit: " << withdrawalLimit << endl;
        cout << "Withdrawals Used: " << withdrawalsThisMonth << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }

    bool checkMinimumBalance() const {
        return balance >= minimumBalance;
    }
};

//PART B

class FixedDeposit : private BankAccount {
private:
    int durationMonths;
    double maturityAmount;
    double penaltyRate;

public:
    FixedDeposit(string name, double amount, string accNum,
                 int duration, double penalty)
        : BankAccount(name, amount, accNum),
          durationMonths(duration),
          maturityAmount(0),
          penaltyRate(penalty) {
        cout << "FixedDeposit constructor called" << endl;
    }

    void calculateMaturity(double annualRate) {
        maturityAmount = balance *
            (1 + annualRate / 100) *
            (durationMonths / 12.0);

        cout << "Maturity Amount: " << maturityAmount << endl;
    }

    void displayFDInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Deposit Amount: " << balance << endl;
        cout << "Duration (Months): " << durationMonths << endl;
        cout << "Maturity Amount: " << maturityAmount << endl;
    }

    void prematureWithdrawal() {
        double penalty = balance * penaltyRate;
        cout << "Original Amount: " << balance << endl;
        cout << "After Penalty: " << balance - penalty << endl;
    }

    void makeDeposit(double amount) {
        deposit(amount); 
    }
};

//PART C

class CurrentAccount : protected BankAccount {
private:
    double overdraftLimit;
    int transactionCount;
    double transactionFee;

public:
    CurrentAccount(string name, double bal, string accNum,
                   double overdraft, double fee)
        : BankAccount(name, bal, accNum),
          overdraftLimit(overdraft),
          transactionCount(0),
          transactionFee(fee) {
        cout << "CurrentAccount constructor called" << endl;
    }

    void performTransaction(double amount, bool isWithdrawal) {
        if (isWithdrawal) {
            if (amount <= balance + overdraftLimit) {
                balance -= amount;
                transactionCount++;
                cout << "Withdrawal successful: " << amount << endl;
            } else {
                cout << "Transaction failed (Overdraft exceeded)." << endl;
            }
        } else {
            balance += amount;
            transactionCount++;
            cout << "Deposit successful: " << amount << endl;
        }
    }

    void displayCurrentAccountInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
        cout << "Transaction Count: " << transactionCount << endl;
        cout << "Transaction Fee: " << transactionFee << endl;
    }

    int getTransactionCount() const {
        return transactionCount;
    }

    void applyMonthlyFees() {
        double totalFees = transactionCount * transactionFee;
        balance -= totalFees;
        cout << "Monthly Fees Deducted: " << totalFees << endl;
        transactionCount = 0;
    }
};

int main() {

    SavingsAccount savings("Ali Ahmed", 50000, "SA-001", 3, 10000);
    savings.displaySavingsInfo();
    savings.deposit(5000);
    savings.displaySavingsInfo();
    savings.makeWithdrawal(2000);
    savings.makeWithdrawal(3000);
    savings.makeWithdrawal(1000);
    savings.makeWithdrawal(500);
    if (savings.checkMinimumBalance()) {
        cout << "Minimum balance requirement met." << endl;
    } else {
        cout << "WARNING: Below minimum balance!" << endl;
    }
    savings.resetMonthlyWithdrawals();
    savings.displaySavingsInfo();
    savings.displayAccountInfo();
    cout << "Account Number: " << savings.getAccountNumber() << endl;

    cout << "\n----------------------------------------\n" << endl;

    FixedDeposit fd("Sara Khan", 100000, "FD-001", 12, 0.02);
    fd.displayFDInfo();
    fd.calculateMaturity(8.0);
    fd.makeDeposit(20000);
    fd.displayFDInfo();
    fd.calculateMaturity(8.0);
    fd.prematureWithdrawal();

    cout << "\n----------------------------------------\n" << endl;

    CurrentAccount current("Usman Malik", 25000, "CA-001", 10000, 5.0);
    current.displayCurrentAccountInfo();
    current.performTransaction(5000, false);
    current.performTransaction(8000, true);
    current.performTransaction(15000, true);
    current.performTransaction(20000, true);
    current.performTransaction(3000, true);
    current.displayCurrentAccountInfo();
    cout << "Total Transactions: " << current.getTransactionCount() << endl;
    current.applyMonthlyFees();
    current.displayCurrentAccountInfo();

    return 0;
}
