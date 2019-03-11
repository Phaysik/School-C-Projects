/*Programmer: Matthew Moore
Description: Math
Date: 1-7-19
*/
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
using namespace std;

int main()
{
	char character;
	string num1, num2;
	double mathComputation;

	cout << "Please enter in your first number: ";
	cin >> num1;
	cout << "Please enter in your second number: ";
	cin >> num2;
	cout << "Please enter in 'a', 's', 'm', or 'd' for what math operand you would like to do: ";
	cin >> character;

	while (true)
	{
		if (!regex_match(num1, regex("[-+]?[0-9]*\\.?[0-9]+")))
		{
			cout << "Please re-enter your first number: ";
			cin >> num1;
		}
		else if (!regex_match(num2, regex("[-+]?[0-9]*\\.?[0-9]+")))
		{
			cout << "Please re-enter your second number: ";
			cin >> num2;
		}
		else if (!(regex_match(string(1, character), regex("[asmd]")) || regex_match(string(1, character), regex("[ASMD]"))))
		{
			cout << "Please enter in a valid character -> 'a', 's', 'm', 'd': ";
			cin >> character;
		}
		else
		{
			break;
		}
	}

	if (character == 'a')
	{
		cout << "Both numbers added together is: " << stod(num1) + stod(num2);
	}
	else if (character == 's')
	{
		cout << "Number 1 minus Number 2 is: " << stod(num1) - stod(num2);
	}
	else if (character == 'd')
	{
		if (stod(num2) == 0)
		{
			cout << "Calculation cannot be done. Divisible by 0.";
		}
		else
		{
			cout << "Number 1 divided by Number 2 is: " <<  stod(num1) / stod(num2);
		}
	}
	else
	{
		cout << "Number 1 times Number 2 is: " <<  stod(num1) * stod(num2);
	}

	cout << endl << endl;

	system("pause");
	return 0;
}