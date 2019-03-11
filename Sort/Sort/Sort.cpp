/*Programmer: Matthew Moore
Description: Sort Them
Date: 1-29-19
*/
#include <iostream>
#include <regex>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;
//Prototypes
template <class Type> void sort(Type*, int);

int main()
{
	int ints[3] = { 6, 2, 7 };
	double doubles[3] = { 2.5, 1.2, 6.4 };
	string strings[3] = { "albert", "john", "gallon" };

	sort(ints, (sizeof(ints) / sizeof(*ints)));
	sort(doubles, (sizeof(doubles) / sizeof(*doubles)));
	sort(strings, (sizeof(strings) / sizeof(*strings)));

	for (int i = 0; i < (sizeof(ints) / sizeof(*ints)); i++) {
		cout << ints[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < (sizeof(doubles) / sizeof(*doubles)); i++) {
		cout << doubles[i] << " ";

	}
	cout << '\n';
	for (int i = 0; i < (sizeof(strings) / sizeof(*strings)); i++) {
		cout << strings[i] << " ";

	}

	cout << '\n';
	system("pause");
	return 0;
}

template <class Type> void sort(Type* array, int size) {  //Sort array
	for (int i = 0; i < size - 1; i++) {
		Type val1 = array[i];
		Type val2 = array[i + 1];

		if (val1 > val2) {
			array[i] = val2;
			array[i + 1] = val1;
		}
	}
}
