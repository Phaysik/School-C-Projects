/*Programmer: Matthew Moore
Description: Leap Year
Date: 1-7-19
*/
#include <iostream>
using namespace std;

int main()
{
	int year;

	cout << "Please enter in a year: ";
	cin >> year;
	cout << endl;

	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			cout << year << " is a leap year.";
		}
		else 
		{
			cout << year << " is not a leap year.";
		}
	}
	else
	{
		if (year % 4 == 0)
		{
			cout << year << " is a leap year.";
		}
		else
		{
			cout << year << " is not a leap year.";
		}
	}

	cout << endl << endl;

	system("pause");
	return 0;
}