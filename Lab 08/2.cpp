#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNo, double bal) {
        accountNumber = accNo;
        balance = bal;
    }

    friend class Manager;
    friend void transferFunds(Account&, Account&, double);
};

class Manager {
public:
    void deposit(Account& acc, double amount) {
        acc.balance += amount;
    }

    void withdraw(Account& acc, double amount) {
        if (acc.balance >= amount) {
            acc.balance -= amount;
        }
    }

    void displayAccount(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber
             << ", Balance: " << acc.balance << endl;
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
    }
}

int main() {
    Account acc1(1001, 5000), acc2(1002, 3000);
    Manager mgr;

    mgr.deposit(acc1, 1000);
    mgr.withdraw(acc2, 500);
    transferFunds(acc1, acc2, 2000);

    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);

    return 0;
}
