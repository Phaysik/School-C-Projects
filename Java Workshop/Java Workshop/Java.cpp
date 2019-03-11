/*Programmer: Matthew Moore
Description: Java Workshop
Date: 1-9-19
*/
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
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
		else if (stod(val) < 0 || stod(val) > 24)
		{
			cout << "Please enter in a value between the range of 0-24: ";
			cin >> val;
		}
		else
		{
			break;
		}
	}
}

double GetSum(double val, string week)
{
	const double hourPay = 10, more8 = 1.5, saturday = 1.25, sunday = .5;

	double pay = 0;

	if (week == "Sunday")
	{
		if (val > 8)
		{
			pay += fmod(val, 8) * more8;	//fmod get modulus on double
		}
		pay += ((val * hourPay) * sunday) + (val * hourPay);
	}
	else if (week == "Saturday")
	{
		if (val > 8)
		{
			pay += fmod(val, 8) * more8;
		}

		pay += ((val * hourPay) * saturday) + (val * hourPay);
	}
	else
	{
		if (val > 8)
		{
			pay += fmod(val, 8) * more8;
		}

		pay += val * hourPay;
	}

	return pay;
}

int main()
{
	const double more40 = 2.5;

	double sum = 0, totHours = 0;

	string uInput;

	string weekdays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	for (string week : weekdays)
	{
		cout << "Please enter in how many hours you worked on " << week << ": ";
		cin >> uInput;

		ValidateInt(uInput);

		sum += GetSum(stod(uInput), week);
		totHours += stod(uInput);
	}

	if (totHours > 40)
	{
		sum += fmod(totHours, 40) * more40;
	}

	cout << endl << "Pay for this week is: $" << fixed << setprecision(2) << sum;

	cout << endl << endl;

	system("pause");
	return 0;
}