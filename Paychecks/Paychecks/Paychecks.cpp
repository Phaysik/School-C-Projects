/*Programmer: Matthew Moore
Description: Paychecks
Date: 1-4-19
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	double paycheck;
	double percentage;

	cout << "Please enter in how much you earn per paycheck: ";
	cin >> paycheck;
	cout << endl << "Please enter the percenage, as a decimal, that you deposit per year: ";
	cin >> percentage;

	cout << endl << "The total amount you have deposited per year is: $" << ((paycheck * 24) * percentage) + 100 << endl << endl;

	system("pause");

	return 0;
}
