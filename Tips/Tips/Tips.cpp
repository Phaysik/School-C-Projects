/*Programmer: Matthew Moore
Description: Tips
Date: 1-3-19
*/
#include <iostream>
#include <stdlib.h>	//Allow clearing of screen
using namespace std;

int main()
{
	//Variables
	float bill;
	const double tax1 = .1;
	const double tax2 = .15;
	const double tax3 = .2;

	cout << "Please enter how much the bill cost: ";
	cin >> bill;

	system("cls");	//Clear screen

	cout << "Your total bill is: $" << bill << endl;
	cout << endl << "The bill plus a 10% tip is: $" << (bill * tax1) + bill;
	cout << endl << "The bill plus a 15% tip is: $" << (bill * tax2) + bill;
	cout << endl << "The bill plus a 20% tip is: $" << (bill * tax3) + bill << endl << endl;

	system("pause");
	return 0;
}