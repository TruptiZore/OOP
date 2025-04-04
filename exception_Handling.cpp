#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Account 
{
	private:
	    string name;
	    int balance;
	
	public:
	
	    Account(string accountName, int initialDeposit) 
	    {
	        name = accountName;
	        balance = initialDeposit;
	        cout<< "Creating Account for "<<name<< " with Initial Deposit: ?"<<balance<<endl;
	    }
	
	    void deposit(int amount) 
	    {
	        balance += amount;
	        cout<< "Depositing ?"<<amount<< " into " <<name<< "'s Account" <<endl;
	    }
	
	    void withdraw(int amount) 
	    {
	        try 
	        {
	            if (amount > balance) 
	            {
	                throw runtime_error("Insufficient funds!");
	            }
	            balance -= amount;
	            cout<< "Withdrawing ?" <<amount<< " from " <<name << "'s Account" <<endl;
	        } 
	        catch (const runtime_error& e) 
	        {
	            cout<< "Error: " <<e.what()<<endl;
	        }
	    }
	
	    void transfer(Account& toAccount, int amount) 
	    {
	        try 
	        {
	            if (amount > balance) 
	            {
	                throw runtime_error("Insufficient funds!");
	            }
	            balance -= amount;
	            toAccount.balance += amount;
	            cout<< "Transferring ?" <<amount<< " from " <<name<< " to " <<toAccount.name<<endl;
	            cout<< "New Balance of " <<name<< ": ?" <<balance<<endl;
	            cout<< "New Balance of " <<toAccount.name <<": ?"<<toAccount.balance <<endl;
	        } 
	        catch (const runtime_error& e) 
	        {
	            cout<< "Error: " <<e.what()<<endl;
	        }
	    }
	
	    void divideBalance(int divisor) 
	    {
	        try 
	        {
	            if (divisor == 0) 
	            {
	                throw runtime_error("Cannot divide by zero!");
	            }
	            double result = static_cast<double>(balance) / divisor;
	            cout<< "Dividing Balance by " <<divisor<< ": ?" <<result<<endl;
	        } 
	        catch (const runtime_error& e) 
	        {
	            cout<< "Error: " <<e.what()<<endl;
	        }
	    }
};

int main() 
{
    string name1, name2;
    int initialDeposit1, initialDeposit2, amount, divisor;

    cout<< "Enter name of first account holder: ";
    cin>>name1;
    cout<< "Enter initial deposit for " <<name1<< ": ?";
    cin>>initialDeposit1;

    Account account1(name1, initialDeposit1);

    cout<< "Enter name of second account holder: ";
    cin>>name2;
    cout<< "Enter initial deposit for " <<name2<< ": ?";
    cin>>initialDeposit2;

    Account account2(name2, initialDeposit2);

    // Depositing money
    cout<< "Enter amount to deposit into " <<name1<< "'s account: ?";
    cin>>amount;
    account1.deposit(amount);

    // Withdrawing money
    cout<< "Enter amount to withdraw from " <<name1<< "'s account: ?";
    cin>>amount;
    account1.withdraw(amount);

    // Transferring money
    cout<< "Enter amount to transfer from " << name1 << " to " <<name2<< ": ?";
    cin>>amount;
    account1.transfer(account2, amount);

    // Dividing balance
    cout<< "Enter number to divide balance of " <<name1<< ": ";
    cin>>divisor;
    account1.divideBalance(divisor);

    return 0;
}
