/*Programmer: Matthew Moore
Description: Functions
Date: 1-23-19
*/
#include <iostream>
#include <regex>
#include <string>
using namespace std;
//Prototype
void say_hello(int);
void Validate(string*, string);
void Product(int, int);
void Half(int);

int main()
{
	string uInput;

	Validate(&uInput, "Please enter your number: ");

	say_hello(stoi(uInput));

	string num1, num2;

	Validate(&num1, "Please enter your first number: ");
	Validate(&num2, "Please enter your second number: ");

	Product(stoi(num1), stoi(num2));

	string number;

	Validate(&number, "Please enter in a number: ");

	Half(stoi(number));

	system("pause");
	return 0;
}

void Validate(string* x, string msg) {  //Validate
	cout << msg;
	cin >> (*x);

	while (!regex_match((*x), regex("\\d+"))) {
		cout << "Please re-enter in your number: ";
		cin >> (*x);
	}
}

void say_hello(int val) { //Say hello a certain number of times
	while (val--) {
		cout << "Hello" << endl;
	}
}

void Product(int val1, int val2) {  //Multiple both numbers together
	cout << val1 << " * " << val2 << " is " << (val1 * val2) << endl;
}

void Half(int number1) {  //Print until number is 1
	cout << number1 << endl;
	do {
		number1 /= 2;
		cout << number1 << endl;
	} while (number1 != 1);
}
