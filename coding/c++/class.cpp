#include <iostream>
#include <string>

using namespace std;

class Bank {
private:
    string depositorName;
    int accountNumber;
    char accountType;
    double balance;

public:
    // Member function to set initial values
    void setData(string name, int accNum, char accType, double initialBalance) {
        depositorName = name;
        accountNumber = accNum;
        accountType = accType;
        balance = initialBalance;
    }

    // Member function to deposit an amount
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of " << amount << endl;
    }

    // Member function to withdraw an amount after checking balance
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal of :" << amount <<endl;
        } else {
            cout << "Insufficient balance. Withdrawal failed.\n";
        }
    }

    // Member function to display name and balance
    void display() {
        cout << "Depositor Name: " << depositorName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Bank account;

    // Setting initial values
    account.setData("Siddhi", 123456789, 'S', 1000.0);

    // Depositing and withdrawing
    account.deposit(500.0);
    account.withdraw(200.0);

    // Displaying account details
    account.display();

    return 0;
}
