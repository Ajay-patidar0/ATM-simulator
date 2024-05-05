#include <iostream>
#include <string>
using namespace std;

struct Account {
    string accountNumber;
    string name;
    double balance;
    int pin; 
    Account* next;
};

class ATM {
private:
    Account* head;

public:
    ATM() {
        head = nullptr;
    }

    void createAccount(string accountNumber, string name, double balance, int pin) {
        Account* newAccount = new Account;
        newAccount->accountNumber = accountNumber;
        newAccount->name = name;
        newAccount->balance = balance;
        newAccount->pin = pin;
        newAccount->next = head;
        head = newAccount;
       
    }

    bool verifyPIN(string accountNumber, int pin) {
        Account* current = head;
        while (current != nullptr) {
            if (current->accountNumber == accountNumber && current->pin == pin) {
                return true; 
            }
            current = current->next;
        }
        return false; 
    }

    void deposit(string accountNumber, int pin) {
        if (!verifyPIN(accountNumber, pin)) {
            cout <<"Access denied. Incorrect PIN or account not found." << endl;
            return;
        }

        double amount;
        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        Account* current = head;
        while (current != nullptr) {
            if (current->accountNumber == accountNumber) {
                current->balance += amount;
                cout << "Deposit successful. New balance: " << current->balance << endl;
                return;
            }
            current = current->next;
        }
    }

    void withdraw(string accountNumber, int pin) {
        if (!verifyPIN(accountNumber, pin)) {
            cout << "Access denied. Incorrect PIN or account not found." << endl;
            return;
        }

        double amount;
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        Account* current = head;
        while (current != nullptr) {
            if (current->accountNumber == accountNumber) {
                if (current->balance >= amount) {
                    current->balance -= amount;
                    cout << "Withdrawal successful. New balance: " << current->balance << endl;
                } else {
                    cout << "Insufficient balance." << endl;
                }
                return;
            }
            current = current->next;
        }
    }

    void checkBalance(string accountNumber, int pin) {
        if (!verifyPIN(accountNumber, pin)) {
            cout << "Access denied. Incorrect PIN or account not found." << endl;
            return;
        }

        Account* current = head;
        while (current != nullptr) {
            if (current->accountNumber == accountNumber) {
                cout << "Account Balance: " << current->balance << endl;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    ATM atm;
    atm.createAccount("101","Hars",6200,3949);
    atm.createAccount("102","Ajay",4000,1234);
    atm.createAccount("103","Ayush",4200,2234);

    

    while (true) {
        cout<<"\t\t+------------------+"<<endl;
        cout<<"\t\t|   ATM Simulator  |"<<endl;
        cout<<"\t\t+------------------+"<<endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {

            case 1: {
                string accountNumber;
                int pin;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter PIN: ";
                cin >> pin;
                atm.deposit(accountNumber, pin);
                break;
            }
            case 2: {
                string accountNumber;
                int pin;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter PIN: ";
                cin >> pin;
                atm.withdraw(accountNumber, pin);
                break;
            }
            case 3: {
                string accountNumber;
                int pin;
                cout << "Enter Account Number: ";
                cin >> accountNumber;
                cout << "Enter PIN: ";
                cin >> pin;
                atm.checkBalance(accountNumber, pin);
                break;
            }
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}