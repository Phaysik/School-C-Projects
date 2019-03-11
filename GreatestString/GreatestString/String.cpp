/*Programmer: Matthew Moore
Description: Greatest Number
Date: 1-7-19
*/
#include <iostream>
#include <algorithm>	//Allows usage of *max_element
#include <string>
using namespace std;

int main()
{
	string strings[3];

	cout << "Please enter in your first string: ";
	cin >> strings[0];
	cout << endl << "Please enter in your second string: ";
	cin >> strings[1];
	cout << endl << "Please enter in your third string: ";
	cin >> strings[2];

	cout << endl << "The largest value of the three is: " << *max_element(strings, strings + 3);	//Gets the max element from the array
	cout << endl << endl;

	system("pause");
	return 0;
}