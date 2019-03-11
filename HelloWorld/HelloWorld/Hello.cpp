#include <iostream>	//Defines a header 
#include <string>
//#include <cstdio>	-->Will allow usage of getchar()
using namespace std;	//Tells the compiler to use the standard namespace. Namespaces are a relatively recent addition to c++

//global variables
extern int a1 = 5, b1 = 15;
extern int c1 = 75;
extern float f;

int main()	//This is the main function where program execution begins
{
	cout << "Hello World" << endl;	//Causes teh message "Hello World" to display on the screen. Cout is for output --> endl make the text after Hello World print on the next line
	//std::getchar();	--> Will prevent the program from closing on debugging

	int a;

	cout << "Please enter a number: ";
	cin >> a;
	cout << "Your number + 10 is: " << a + 10 << endl;

	string mystring;
	cout << "Please enter your name: ";
	cin >> mystring;
	cout << "Your name is: " << mystring << endl;
	//Variable names, classes, modules, and functions must start with the letters a-z (capital or small is ok) or underscore. No spaces, no keywords, or special characters (%@#$, etc). C++ is case sensitve so dog is not the same as Dog

	//Date Types
	//Boolean - bool, Character - char, Integer - int, Floating Point, Float, Double Floating Point - Double

	cout << "Size of char: " << sizeof(char) << endl;
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of int short: " << sizeof(short int) << endl;
	cout << "Size of int long: " << sizeof(long int) << endl;
	cout << "Size of float: " << sizeof(float) << endl;

	//int a1, b1;
	int c1;
	float f;

	a1 = 10;
	//b1 = 20;
	c1 = a1 + b1;

	cout << "Your value is: " << c1 << endl;

	f = 70.0 / 3.0;
	cout << f << endl;

	return 0;	//Terminates main function and ceases it to return the value 0 to the calling process
}