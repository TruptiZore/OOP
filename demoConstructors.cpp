#include<iostream>
using namespace std;

//DEFINING CLASS
class DemoConstructors
{
	private :
		int num1;
		int num2;
	public :

		DemoConstructors()  //DEFAULT CONSTRUCTOR
		{	
			cout<<"HEY, I am Default Constructor!!"<<endl;
			num1 = 10;
			num2 = 15;
		}
		DemoConstructors(int n1, int n2)  //PARAMETERIZED CONSTRUCTOR
		{
			cout<<"HEY, I am Parameterized Constructor!!"<<endl;
			num1 = n1;
			num2 = n2;
		}
		int addition()
		{
			return num1+num2;
		}
};

int main()
{
	//CREATING OBJECTS
	
	//Default Constructor
	DemoConstructors defaultCon;
	cout<<"ADDITION = "<<defaultCon.addition()<<endl;
	
	//PArameterized Constructor
	DemoConstructors paraCon(5, 25);
	cout<<"ADDITION = "<<paraCon.addition()<<endl;
	
	return 0;
}
