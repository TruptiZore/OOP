#include <iostream>
using namespace std;

// Custom Exceptions
class InsufficientFundsException {};
class InvalidTransactionException {};
class DivideByZeroException {};

// Bank Account class
class BankAccount {
    string name;
    double balance;

public:
    BankAccount(string n, double amount) {
        if (amount < 0) throw InvalidTransactionException();
        name = n;
        balance = amount;
    }

    void deposit(double amount) {
        if (amount < 0) throw InvalidTransactionException();
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
    }

    void transfer(BankAccount &to, double amount) {
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
        to.balance += amount;
    }

    void divideBalance(double number) {
        if (number == 0) throw DivideByZeroException();
        balance /= number;
    }

    void show() {
        cout << name << " Balance: " << balance << endl;
    }
};

int main() {
    try {
        BankAccount rahul("Rahul", 5000);
        BankAccount priya("Priya", 0);

        rahul.deposit(1000);
        rahul.withdraw(7000); // throws InsufficientFundsException

    } catch (InsufficientFundsException) {
        cout << "Not enough money!" << endl;
    } catch (InvalidTransactionException) {
        cout << "Invalid transaction!" << endl;
    } catch (DivideByZeroException) {
        cout << "Can't divide by zero!" << endl;
    }

    try {
        BankAccount rahul("Rahul", 5000);
        BankAccount priya("Priya", 0);

        rahul.transfer(priya, 3000);
        rahul.show();
        priya.show();

        rahul.divideBalance(0); // throws DivideByZeroException

    } catch (...) {
        cout << "Something went wrong!" << endl;
    }

    return 0;
}

