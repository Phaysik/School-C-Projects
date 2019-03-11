/*Programmer: Matthew Moore
Description: Post-Test Loop
Date: 1-9-19
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;

void RegNum(string num)	//Validate Num
{
	while (true)
	{
		if (!regex_match(num, regex("[-+]?[0-9]*\\.?[0-9]+")))
		{
			cout << "Please re-enter in your number: ";
			cin >> num;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	string num;

	cout << "Please enter in a starting number: ";
	cin >> num;

	RegNum(num);

	cout << endl;

	for (double i = stod(num); i < stod(num) + 10; i++)
	{
		double farenheight = (i * 9) / 5 + 32;
		cout << i << " Celsius - " << farenheight << " Fahrenheit" << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}