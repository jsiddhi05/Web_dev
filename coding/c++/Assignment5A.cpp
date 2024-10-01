#include <iostream>
using namespace std;

class Bank
{
private:
    string Name_of_depositor, Type_of_account;
    long int Account_number;
    float Balance_amt_in_acc, deposited_amt, withdrawl_amt;

public:
    void setData()
    {
        cout << "Enter the name of Account holder: ";
        cin >> Name_of_depositor;
        cout << "Enter the account number: ";
        cin >> Account_number;
        cout << "Enter the type of account: ";
        cin >> Type_of_account;
        cout << "Enter balance amount in the account: ";
        cin >> Balance_amt_in_acc;
    }

    void deposit()
    {
        cout << "Enter the amount to be deposited: ";
        cin >> deposited_amt;
        Balance_amt_in_acc = Balance_amt_in_acc + deposited_amt;
        cout << "The amount deposited successfully" << endl;
        cout << "The current balance is " << Balance_amt_in_acc << endl;
    }

    void withdraw()
    {
        cout << "Enter the amount to be withdrawl: ";
        cin >> withdrawl_amt;
        if (withdrawl_amt > Balance_amt_in_acc)
        {
            cout << "Enter valid amount" << endl;
        }
        else
        {
            Balance_amt_in_acc = Balance_amt_in_acc - withdrawl_amt;
            cout << "The amount withdrawl successfully" << endl;
            cout << "The current balance is " << Balance_amt_in_acc << endl;
        }
    }

    void display()
    {
        cout<<"The name of account holder is: "<<Name_of_depositor<<endl;
        cout<<"The current balance is "<<Balance_amt_in_acc<<endl;
    }
};

int
main()
{
    Bank b1, b2, b3;
    b1.setData();
    b1.deposit();
    b1.withdraw();
    b1.display();
    return 0;
}