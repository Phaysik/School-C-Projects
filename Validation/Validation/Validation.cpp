/*Programmer: Matthew Moore
Description: Validate Input
Date: 1-7-19
*/
#include <iostream>
#include <regex>	//Include regex
#include <string>
using namespace std;

int main()
{
	string num1;
	string num2;

	cout << "Please enter in a integer number: ";
	cin >> num1;

	while (true)
	{
		if(regex_match(num1, regex("\\d+")))	//Match expression with regex
		{
			cout << "Your number is an integer.";
			break;
		}
		else
		{
			cout << "Your number is not an integer. Please re-enter: ";
			cin >> num1;
		}
	}

	cout << endl << endl << "Please enter in a decimal number: ";
	cin >> num2;

	while (true)
	{
		if (regex_match(num2, regex("[-+]?[0-9]*\.?[0-9]+")))
		{
			cout << "Your number is an decimal.";
			break;
		}
		else
		{
			cout << "Your number is not an decimal. Please re-enter: ";
			cin >> num1;
		}
	}

	cout << endl << endl;

	system("pause");
	return 0;
}