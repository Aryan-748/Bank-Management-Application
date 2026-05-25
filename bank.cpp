#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

class BankAccount
{
public:
    int accountNumber;
    string name;
    float balance;

    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream file("bank.txt", ios::app);

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();

        cout << "\nAccount Created Successfully!\n";
    }

    void displayAccount()
    {
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : " << balance << endl;
    }
};

void depositMoney()
{
    int accNo;
    float amount;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    int accountNumber;
    string name;
    float balance;

    while (file >> accountNumber)
    {
        file.ignore();
        getline(file, name);
        file >> balance;

        if (accountNumber == accNo)
        {
            found = true;

            cout << "Enter Deposit Amount: ";
            cin >> amount;

            balance += amount;

            cout << "\nAmount Deposited Successfully!";
            cout << "\nUpdated Balance: " << balance << endl;
        }

        temp << accountNumber << endl;
        temp << name << endl;
        temp << balance << endl;
    }

    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }
}

void withdrawMoney()
{
    int accNo;
    float amount;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    ifstream file("bank.txt");
    ofstream temp("temp.txt");

    int accountNumber;
    string name;
    float balance;

    while (file >> accountNumber)
    {
        file.ignore();
        getline(file, name);
        file >> balance;

        if (accountNumber == accNo)
        {
            found = true;

            cout << "Enter Withdraw Amount: ";
            cin >> amount;

            if (amount <= balance)
            {
                balance -= amount;

                cout << "\nWithdrawal Successful!";
                cout << "\nRemaining Balance: " << balance << endl;
            }
            else
            {
                cout << "\nInsufficient Balance!\n";
            }
        }

        temp << accountNumber << endl;
        temp << name << endl;
        temp << balance << endl;
    }

    file.close();
    temp.close();

    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }
}

void checkBalance()
{
    int accNo;
    bool found = false;

    cout << "\nEnter Account Number: ";
    cin >> accNo;

    ifstream file("bank.txt");

    int accountNumber;
    string name;
    float balance;

    while (file >> accountNumber)
    {
        file.ignore();
        getline(file, name);
        file >> balance;

        if (accountNumber == accNo)
        {
            found = true;

            cout << "\nAccount Number : " << accountNumber;
            cout << "\nCustomer Name  : " << name;
            cout << "\nBalance        : " << balance << endl;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nAccount Not Found!\n";
    }
}

void displayAllAccounts()
{
    ifstream file("bank.txt");

    int accountNumber;
    string name;
    float balance;

    cout << "\n===== ALL ACCOUNTS =====\n";

    while (file >> accountNumber)
    {
        file.ignore();
        getline(file, name);
        file >> balance;

        cout << "\nAccount Number : " << accountNumber;
        cout << "\nCustomer Name  : " << name;
        cout << "\nBalance        : " << balance << endl;
    }

    file.close();
}

int main()
{
    int choice;
    BankAccount account;

    do
    {
        cout << "\n\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            break;

        case 2:
            depositMoney();
            break;

        case 3:
            withdrawMoney();
            break;

        case 4:
            checkBalance();
            break;

        case 5:
            displayAllAccounts();
            break;

        case 6:
            cout << "\nThank You For Using Bank Management System!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

        system("pause");

    } while (choice != 6);

    return 0;
}