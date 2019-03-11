/*Programmer: Matthew Moore
Description: Coding Test for Chapters 2-8 - Telephone
Date: 1-17-19
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <regex>
#include <map>
#include <iterator>
#include <list>
using namespace std;

int main()
{
	string phone = "", placeHolder = "", phones = "";

	list<string> allPhones;	//Create a list of phone numbers, and the numeric values of the phone numbers

	map<string, int> mymap = {	//Create a key-value pair
		{ "a", 2 },
		{ "b", 2 },
		{ "c", 2 },
		{ "d", 3 },
		{ "e", 3 },
		{ "f", 3 },
		{ "g", 4 },
		{ "h", 4 },
		{ "i", 4 },
		{ "j", 5 },
		{ "k", 5 },
		{ "l", 5 },
		{ "m", 6 },
		{ "n", 6 },
		{ "o", 6 },
		{ "p", 7 },
		{ "r", 7 },
		{ "s", 7 },
		{ "t", 8 },
		{ "y", 8 },
		{ "v", 8 },
		{ "w", 9 },
		{ "x", 9 },
		{ "y", 9 },
	};

	do
	{
		cout << "If you ever want to end the program, enter '-1'." << endl;

		for (int i = 0; i < 10; i++)
		{
			cout << "Please enter in the " << (i + 1) << " character of your phone number: ";
			cin >> placeHolder;

			transform(placeHolder.begin(), placeHolder.end(), placeHolder.begin(), toupper);	//Convert the string to upper

			while (true)
			{
				if (placeHolder == "-1")
				{
					system("cls");

					for (int i = 1; i <= allPhones.size(); i++)
					{
						list<std::string>::iterator it = allPhones.begin();
						advance(it, i - 1);	//Indexing the list

						if (i % 2 == 0)
						{
							cout << "Your phone, with numeric values, is: " << *it << endl << endl;
						}
						else
						{
							cout << "Your phone is: " << *it << endl;

						}
					}

					system("pause");
					exit(0);
				}
				else if (placeHolder.length() > 1)	//Make sure it is only one character
				{
					cout << "There is more than one character. Please re-enter: ";
					cin >> placeHolder;
					transform(placeHolder.begin(), placeHolder.end(), placeHolder.begin(), toupper);

					continue;
				}
				else if (!regex_match(placeHolder, regex("[A-PR-Y0-9]")))	//Will only allow a-p, r-y, and 0-9 characters to be entered
				{
					cout << "That is an invalid character. Please re-enter: ";
					cin >> placeHolder;
					transform(placeHolder.begin(), placeHolder.end(), placeHolder.begin(), toupper);

					continue;
				}
				else
				{
					break;
				}
			}

			phone += placeHolder;
		}

		placeHolder = "";

		phones = "";

		for (int i = 0; i < phone.length(); i++) {
			if (i == 3 || i == 6)	//Add dashes to the phone numbers
			{
				phones += "-";
				placeHolder += "-";
			}

			map<string, int>::iterator it = mymap.find(string(1, tolower(phone.at(i))));	//Finds the key, if it exists

			if (it != mymap.end())
			{
				//element found;
				int b3 = it->second;	//Get the value of the key
				placeHolder += to_string(b3);
			}
			else
			{
				placeHolder += phone.at(i);	//If the phone.at(i) is a number
			}

			phones += phone.at(i);
		}

		//Add the phones to the list
		allPhones.push_back(phones);
		allPhones.push_back(placeHolder);

		cout << "Your phone number is: " << phones << endl;

		cout << "Your phone number, converted to numbers, is: " << placeHolder << endl << endl;

		phones = "", placeHolder = "", phone = "";

	} while (true);

	system("pause");
	return 0;
}