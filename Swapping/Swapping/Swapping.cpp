/*Programmer: Matthew Moore
Description: Swapping
Date: 1-7-19
*/
#include <iostream>
using namespace std;

int main()
{
	double num1, num2, temp;
	
	cout << "Please enter in your first number: ";
	cin >> num1;
	cout << endl << "Please enter in your second number: ";
	cin >> num2;

	cout << endl << "Your first number was: " << num1 << endl << "Your second number was: " << num2;

	temp = num1;
	num1 = num2;
	num2 = temp;

	cout << endl << "First number swapped is: " << num1 << endl << "Second number swapped is: " << num2 << endl << endl;

	system("pause");
	return 0;
}