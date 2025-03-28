#include<iostream>
using namespace std;
int main()
{
	int n,d,r;
	
	cout<<"Enter two integer values = ";
	cin>>n>>d;
	
	/*r=n/d;
	cout<<"Result = "<<r;
	*/
	
	try {
		
		if(d==0) {
			throw d;	
		}
		r =n/d;
		cout<<"Result = "<<r;
	}
	catch(int e) {
		
		cout<<"d = "<<e<<endl;
		cout<<"DivideByZeroError Exception"<<endl;
	}
	
	return 0; 
}
