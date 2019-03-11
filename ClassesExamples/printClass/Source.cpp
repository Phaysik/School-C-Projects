/*Programmer: Matthew Moore
Description: Example of Class Overloading
Date: 2-25-19
*/
#include <iostream>
using namespace std;

class PrintData {
public:
	void print(int i) {
		cout << "Printing int: " << i << endl;
	}

	void print(double x) {
		cout << "Printing double: " << x << endl;
	}

	void print(char* j) {
		cout << "Printing character(s): " << j << endl;
	}
};

int main()
{
	PrintData myObject;

	myObject.print(3);
	myObject.print(3.5);
	myObject.print("Sasd");

	system("pause");
	return 0;
}