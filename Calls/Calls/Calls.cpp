/*Programmer: Matthew Moore
Description: Billing for Calls
Date: 1-7-19
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int calls;
	double bill = 200;

	cout << "Please enter in how many calls you have made: ";
	cin >> calls;

	if (calls > 200) 
	{
		bill += (calls % 200) * .5;
		calls -= calls % 200;
	}
	if (calls > 150)
	{
		bill += (calls % 150) * .6;
		calls -= calls % 150;
	}
	if(calls > 100)
	{
		bill += (calls % 100) * .7;
		calls -= calls % 100;
	}

	cout << "Your total bill is: $" << fixed << setprecision(2) << bill;

	cout << endl << endl;

	system("pause");
	return 0;
}