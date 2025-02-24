#include<iostream>
using namespace std;

class BankAccount
{
    private :
        int acc_no;
        int balance;
        string acc_name;
    public:   
        BankAccount()
        {
            acc_no = 123456;
            acc_name = "Trupti Zore";
            balance = 50000;
        }
		//ACCESSOR METHOD TO GET INFORMATION ABOUT BANK CUSTOMER 
        void getinfo()
        {
            cout << "Account Name : " << acc_name << endl;
            cout << "Account Number : " << acc_no << endl;
            cout << "Balance : " << balance << endl;
        }

        // DEFINING INNER CLASS OR NESTED CLASS
        class Transaction
        {
            public:
            	// MEMBER FUNCTION FOR DEPOSITE AMOUNT
                void deposite(BankAccount &obj) 
                {
                    int amt;
                    cout << "Enter Amount You Want To Deposit - ";
                    cin >> amt;
                    obj.balance += amt;
                    cout << endl << "Total Balance After Deposit : " << obj.balance << endl;
                }
				
				//MEMBER FUNCTION FOR WITHDRAW AMOUNT
                void withdraw(BankAccount &obj)  
                {
                    int amt;
                    cout << "Enter Amount You Want To Withdraw - ";
                    cin >> amt;
                    if(amt <= obj.balance)
                    {
                        obj.balance -= amt;
                        cout << endl << "Total Balance After Withdrawal : " << obj.balance << endl;
                    }
                    else
                    {
                        cout << "Insufficient balance!" << endl;
                    }
                }
        };
};

int main()
{
	//CREATE OUTER CLASS OBJECT
    BankAccount bank;
    bank.getinfo();
    
    // CREATE INNER CLASS OBJECT 
    BankAccount::Transaction transaction;
    
    // CAALING DEPOSITE AND WITHDRAW FUNCTIONS
    transaction.deposite(bank); 
    transaction.withdraw(bank);
    
    return 0;
}


