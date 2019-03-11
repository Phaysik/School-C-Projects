/*Programmer: Matthew Moore
Description: Practice Functions
Date: 1-23-19
*/
#include <iostream>
#include <limits>
#include <string>
using namespace std;
//Prototype
double Input();
void Validate(double*, string);
double DoubleNum(double);
void Output(double, double);

int main()
{
	double val = Input();
	double doubleNum = DoubleNum(val);

	Output(val, doubleNum);

	system("pause");
	return 0;
}

double Input() {  //Get Input
	double val;

	Validate(&val, "Please enter in a number: ");

	return val;
}

void Validate(double* x, string msg) {  //Validate
	while (true)
	{
		cout << msg;
		cin >> (*x);
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else
		{
			break;
		}
	}
}

double DoubleNum(double val) {  //Double
	return val * 2;
}

void Output(double val, double doubleVal) { //Display
	cout << endl << "Your value is: " << val << endl;
	cout << "Your value doubled is: " << doubleVal << endl << endl;
}
