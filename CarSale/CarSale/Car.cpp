/*Programmer: Matthew Moore
Description: Harry's Car Sale
Date: 1-7-19
*/
#include <iostream>
#include <regex>
#include <string>
#include <iomanip>
using namespace std;

double determineCommision(double sale)	//Get commission
{
	if (sale <= 19999.99)
	{
		return (sale * .04);
	}
	else if (sale <= 29999.99)
	{
		return (sale * .05);
	}
	else if (sale <= 39999.99)
	{
		return (sale * .06);
	}
	else if (sale <= 49999.99)
	{
		return (sale * .07);
	}
	else 
	{
		return (sale * .09);
	}
}

int main()
{
	string sales;
	double sale;

	cout << "Please enter in your monthly sales: ";
	cin >> sales;

	while (true)
	{
		if (regex_match(sales, regex("[+]?[0-9]*\\.?[0-9]+")))
		{
			sale = stod(sales);	//Convert to double
			sale = determineCommision(sale);
			break;
		}
		else
		{
			cout << "Your input was not a valid decimal input. Please re-enter: ";
			cin >> sales;
		}
	}

	cout << "Your commission is: $" << fixed << setprecision(2) << sale;
	cout << endl << endl;
	system("pause");
	return 0;
}