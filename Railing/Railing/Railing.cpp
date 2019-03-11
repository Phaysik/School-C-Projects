#define _USE_MATH_DEFINES	/* Define _USE_MATH_DEFINES before including math.h to expose these macro
							 * definitions for common math constants.  These are placed under an #ifdef
							 * since these commonly-defined names are not part of the C/C++ standards.
							 */
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
	float diameter;
	float pricePerFoot;

	cout << "What is the diameter of the circle? ";
	cin >> diameter;
	cout << endl << "What is the price of the railing per foot? ";
	cin >> pricePerFoot;

	system("cls");

	cout << "The length of railing you need is: " << (M_PI * diameter);
	cout << endl << "The total price of the railing is: $" << (M_PI * diameter) * pricePerFoot << endl << endl;

	system("pause");
	return 0;
}

