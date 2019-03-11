/*Programmer: Matthew Moore
Description: Greatest Number
Date: 1-7-19
*/
#include <iostream>
#include <algorithm>	//Allows usage of *max_element
using namespace std;

int main()
{
	double nums[3];

	cout << "Please enter in your first number: ";
	cin >> nums[0];
	cout << endl << "Please enter in your second number: ";
	cin >> nums[1];
	cout << endl << "Please enter in your third number: ";
	cin >> nums[2];

	cout << endl << "The largest value of the three is: " << *max_element(nums, nums+3);	//Gets the max element from the array
	cout << endl << endl;

	system("pause");
	return 0;
}