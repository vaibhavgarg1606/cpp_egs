// Example: of Constant member function
/* 
	Constant member functions are those functions which are denied permission to change the values of the data members of their class.
	To make a member function constant, the keyword “const” is appended to the function prototype and also to the function definition header. 
*/


// adding const after function parameters eg Demo::get_data()


#include<iostream>
using namespace std;

class Demo
{
	int x;
public:
	
void set_data(int a)
{
	x=a;
}


int get_data2() const		// this will cause in error as there is modification in class member or varibale
{
	++x;
	return x;		
}



int get_data() const		 //constant member function
{
	return x;				// here it will not generate any error cause no change to class member is happening 
}

};


int main()
{
Demo d;
	d.set_data(10);
	cout<<endl<<d.get_data();

	return 0;
}
