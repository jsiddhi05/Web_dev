#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    string depositorName;
    int accountNumber;
    string accountType;
    double balance;

public:
    // Parameterized constructor
    Bank(string name, int accNum, string type, double initialBalance) {
        depositorName = name;
        accountNumber = accNum;
        accountType = type;
        balance = initialBalance;
    }

    // Member function to deposit an amount
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    // Member function to withdraw an amount
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        }
    }

    // Member function to display name and balance
    void display() {
        cout << "Depositor Name: " << depositorName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    // Creating an object of Bank with parameterized constructor
    Bank account("Siddhi", 123456789, "Savings", 1000.00);

    // Deposit some amount
    account.deposit(500.00);

    // Withdraw some amount
    account.withdraw(200.00);

    // Display depositor name and balance
    account.display();

    return 0;
}
