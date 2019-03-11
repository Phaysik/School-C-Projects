/*Programmer: Matthew Moore
Description: Premium Paper
Date: 1-9-19
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;

void ValidateInt(string val)	//Validate Input
{
	while (true)
	{
		if (!regex_match(val, regex("\\d+")))
		{
			cout << "Please re-enter in a positive whole number: ";
			cin >> val;
		}
		else
		{
			break;
		}
	}

}

int main()
{
	string income, expense;
	string stop;

	double totIncome = 0, totExpenses = 0;

	while (true)
	{
		cout << "Please enter in the companies income: ";
		cin >> income;

		ValidateInt(income);

		totIncome += stod(income);

		cout << "If you would like to stop inputting income, please enter in 'stop': ";
		cin >> stop;

		transform(stop.begin(), stop.end(), stop.begin(), ::tolower);	//Lowercase val

		if (stop == "stop")
		{
			break;
		}
	}

	while (true)
	{
		cout << "Please enter in the companies expenses: ";
		cin >> expense;

		ValidateInt(expense);

		totExpenses += stod(expense);

		cout << "If you would like to stop inputting income, please enter in 'stop': ";
		cin >> stop;

		transform(stop.begin(), stop.end(), stop.begin(), ::tolower);	//Lowercase val

		if (stop == "stop")
		{
			break;
		}
	}

	cout << endl << "Total income: $" << totIncome << endl << "Total expenses: $" << totExpenses << endl << "Net profit/loss: $" << totIncome - totExpenses;

	cout << endl << endl;

	system("pause");
	return 0;
}