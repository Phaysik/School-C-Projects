/*Programmer: Matthew Moore
Description: Harry's Car Sale
Date: 1-7-19
*/
#include <iostream>
#include <regex>
#include <string>
#include <iomanip>
using namespace std;

double determineCommision(double points, string membership)	//Get points
{
	if (membership == "standard")
	{
		if (points < 75)
		{
			return (points * .05);
		}
		else if (points < 149.99)
		{
			return (points * .075);
		}
		else
		{
			return (points * .1);
		}
	}
	else if (membership == "plus")
	{
		if (points < 150)
		{
			return (points * .06);
		}
		else
		{
			return (points * .13);
		}
	}
	else
	{
		if (points < 200)
		{
			return (points * .04);
		}
		else
		{
			return (points * .15);
		}
	}
}

int main()
{
	string membership, purchases;
	double Purchases;

	cout << "Please select what membership plan you have: " << endl << endl << "Standard" << endl << "Plus" << endl << "Premium" << endl;
	cin >> membership;
	transform(membership.begin(), membership.end(), membership.begin(), ::tolower);
	cout << endl << "Please enter in your total monthly purchases: ";
	cin >> purchases;

	while (true)
	{
		if (membership != "standard" && membership != "plus" && membership != "premium")
		{
			cout << "Please enter in either standard, plus, or premium for your membership plan: ";
			cin >> membership;
			transform(membership.begin(), membership.end(), membership.begin(), ::tolower);
		}
		else if (regex_match(purchases, regex("[+]?[0-9]*\\.?[0-9]+")))
		{
			Purchases = stod(purchases);	//Convert to double
			Purchases = determineCommision(Purchases, membership);
			break;
		}
		else
		{
			cout << "Your input was not a valid decimal input. Please re-enter: ";
		}
	}

	cout << "The amount of reward points you have earned, based off your " << membership << " plan, " << endl << "is: $" << fixed << setprecision(2) << Purchases;
	cout << endl << endl;

	system("pause");
	return 0;
}