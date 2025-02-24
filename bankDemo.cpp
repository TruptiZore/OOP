
#include <iostream>
#include <vector>
#include <iomanip> // For formatting output
#include <ctime> // Include for time functions
#include <string>

using namespace std;

struct Transaction {
    string type;
    double amount;
    string timestamp; // You might want to use a proper time library for this
};

class BankAccount {
private:
    double balance;
    vector<Transaction> transactions;

public:
    BankAccount(double initialBalance = 0) : balance(initialBalance) {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back({"Deposit", amount, getCurrentTimestamp()});
        cout << "Deposite successful. Current balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            transactions.push_back({"Withdrawal", amount, getCurrentTimestamp()});
            cout << "Withdrawal successful. Current balance: " << balance << endl;
        }
    }

    void printLast10Transactions() const {
        int numTransactions = transactions.size();
        int count = 0;

        if (numTransactions == 0) {
            cout << "No transactions yet." << endl;
            return;
        }

        cout << "\nLast 10 Transactions:" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << setw(15) << "Type" << setw(15) << "Amount" << setw(20) << "Timestamp" << endl; // Formatting
        cout << "--------------------------------------------------" << endl;


        for (int i = numTransactions - 1; i >= 0 && count < 10; i--) {
            cout << setw(15) << transactions[i].type << setw(15) << transactions[i].amount
                 << setw(20) << transactions[i].timestamp<<endl;
            count++;
        }
        cout << "--------------------------------------------------" << endl;

    }

    double getBalance() const {
        return balance;
    }

private:
    string getCurrentTimestamp() const { // A simple timestamp (replace with a proper library)
        time_t now = time(0);
        char* dt = ctime(&now);
        return dt; // Be aware that ctime includes a newline at the end. You might need to remove it.
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;

    do {
        cout << "\nMini Bank Menu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Print Last 10 Statements" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.printLast10Transactions();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

