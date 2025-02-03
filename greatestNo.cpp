#include<iostream>
using namespace std;
int main()
{
	int num1,num2,num3;
	cout<<"Enter three values : ";
	cin>>num1>>num2>>num3;
	
	if(num1>num2&&num1>num3)
	{
		cout<<num1<<"is gretest number!";
	}
	else if(num2>num1&&num2>num3)
	{
		cout<<num2<<"is gretest number!";
	}
	else
	{
		cout<<num3<<"is gretest number!";
	}
	
	return 0;
}
