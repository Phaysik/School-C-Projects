/*Programmer: Matthew Moore
Description: Right Triangle Checker
Date: 1-9-19
*/
#include <iostream>
#include <string>
#include <regex>
#include <math.h>
using namespace std;

void ValidateInt(string val)	//Validate Input
{
	while (true)
	{
		if (!regex_match(val, regex("\\d+")))
		{
			cout << "Please enter in a positive whole number: ";
			cin >> val;
		}
		else
		{
			break;
		}
	}
}

string DetermineHigher(int num1, int num2)	//Check if second number is smaller than the first number
{
	while (true)
	{
		if (num2 < num1)
		{
			cout << num2 << " is smaller than " << num1 << " Try again. ";
			cin >> num2;
		}
		else
		{
			return to_string(num2);

			break;
		}
	}
}

string DetermineTriangle(int num1, int num2, int num3)	//Determine if it's a right triangle
{
	if (pow(num1, 2) + pow(num2, 2) == pow(num3, 2))
	{
		return "Yes! These sides do make a right triangle.";
	}
	else
	{
		return "No! These sides do not make a right triangle.";
	}
}

int main()
{
	string num1, num2, num3;

	cout << "Please enter in the first number: ";
	cin >> num1;

	ValidateInt(num1);

	cout << "Please enter in the second number: ";
	cin >> num2;

	ValidateInt(num2);

	num2 = DetermineHigher(stoi(num1), stoi(num2));

	cout << "Please enter in the third number: ";
	cin >> num3;

	ValidateInt(num3);

	num3 = DetermineHigher(stoi(num2), stoi(num3));

	cout << endl << "Your three sides are " << num1 << " " << num2 << " " << num3;

	cout << endl << DetermineTriangle(stoi(num1), stoi(num2), stoi(num3));

	cout << endl << endl;

	system("pause");
	return 0;
}