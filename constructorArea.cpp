#include <iostream>
using namespace std;

class Circle 
{
	private:
	    double radius;
	    double area;

	public:
	
	    Circle(double r)
		{
	        radius = r;
	        area = 3.14*radius*radius;
	        cout<< "Circle object created"<<endl;
	        cout<< "Radius = " << radius <<endl;
	        cout<< "Area of circle = " <<area <<endl;
    	}

	    ~Circle() 
		{
	        cout << "Circle object destroyed"<<endl;
	    }
};

int main() 
{
    double r;
    cout<< "Enter the radius of the circle: ";
    cin>> r;
    
    Circle c(r);

    return 0;
}
