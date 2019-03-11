/*Programmer: Matthew Moore
Description: Triangle of Asterisks
Date: 1-9-19
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;

void ValidateInt(string val)	//Validate Input
{
	while (true)
	{
		if (!regex_match(val, regex("\\d+")))
		{
			cout << "Please re-enter in a positive whole number: ";
			cin >> val;
		}
		
		else
		{
			break;
		}
	}

}

int main()
{
	string val, asterisk = "", count = "";

	cout << "Please enter in a number from 4-12: ";
	cin >> val;

	ValidateInt(val);

	vector<string> array;	//Create a dynamic array

	array.resize(stoi(val) * 2 - 1);	//Resize array

	for (double i = stod(val); i > 0; i--)
	{
		count = "";

		for (double x = 0; x < i; x++)
		{
			count += ' ';
		}

		asterisk += "*";

		array[stoi(val) - i] = count + asterisk;	//Assign the beginning of the array, the increment up until middle of array
		array[array.size() - (stoi(val) - i + 1)] = count + asterisk;	//Assign the end of the array, then increment down until the middle of array
	}

	cout << endl;

	for (string val : array)
	{
		cout << val << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}