/*Programmer: Matthew Moore
Description: Another Way to Multiple
Date: 1-9-19
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;

string ValidateInt(string val)	//Validate Input
{
	while (true)
	{
		if (!regex_match(val, regex("\\d+")))
		{
			cout << "Please enter in a positive whole number: ";
			cin >> val;
		}
		else if (stod(val) < 0 || stod(val) > 24)
		{
			cout << "Please enter in a value between the range of 0-24: ";
			cin >> val;
		}
		else
		{
			return val;
		}
	}
}

int main()
{
	string num1, num2;

	double mult = 0;

	cout << "Please enter in the first number: ";
	cin >> num1;

	num1 = ValidateInt(num1);

	cout << "Please enter in the second number: ";
	cin >> num2;

	num2 = ValidateInt(num2);

	for (double i = 0; i < stod(num2); i++)
	{
		mult += stod(num1);
	}

	cout << endl << num1 << " * " << num2 << " = " << mult;

	cout << endl << endl;

	system("pause");
	return 0;
}