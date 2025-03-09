#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;
public:
    Account(int accNum, float bal) : accountNumber(accNum), balance(bal) {}
    virtual void displayDetails() {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;
public:
    SavingsAccount(int accNum, float bal, float rate) : Account(accNum, bal), interestRate(rate) {}
    void displayDetails() override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;
public:
    CheckingAccount(int accNum, float bal, float limit) : Account(accNum, bal), overdraftLimit(limit) {}
    void displayDetails() override {
        Account::displayDetails();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

int main() {
    SavingsAccount savings(1001, 5000.75, 2.5);
    CheckingAccount checking(1002, 1500.25, 1000.0);

    cout << "Savings Account Details:\n";
    savings.displayDetails();

    cout << "\nChecking Account Details:\n";
    checking.displayDetails();

    return 0;
}
