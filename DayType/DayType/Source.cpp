/*Programmer: Matthew Moore
Description: Day Type
Date: 3-7-19
*/
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>
using namespace std;

class DayType {
private:
	map<int, string> dict;
	string startDate;
	int key;
public:
	DayType();

	// Set current date and the current date key value
	void setStart(int inp) {
		key = inp;
		startDate = dict[key];
	}

	// Return days
	string currDate() {
		return "The current day is: " + startDate;
	}

	string returnDay() {
		return startDate;
	}

	string returnNext() {
		return dict[(key + 1) % 7];
	}

	string returnPrev() {
		return dict[(7 + (key - 1)) % 7];
	}

	string returnAddDays(int count) {
		return dict[(key + count) % 7];
	}

};

DayType::DayType() {
	dict = { {0, "Sunday"}, { 1, "Monday" }, { 2, "Tuesday" }, { 3, "Wednesday" }, { 4, "Thursday" }, { 5, "Friday" }, { 6, "Saturday" }, };
	startDate = "";
	key = 0;
}

// Prototype
void ValidateInput(string*);
void ValidateNum(string*);

int main()
{
	string uInput;

	cout << "Input a number that relates to the position of the week. (Sunday = 0, 0-6) ";
	getline(cin, uInput);

	ValidateInput(&uInput);

	system("cls");

	DayType date;

	date.setStart(stoi(uInput));

	cout << "The current day is: " << date.currDate() << endl;

	string next = date.returnNext();

	cout << "The next day is: " << next << endl;

	string prev = date.returnPrev();

	cout << "The previous day was: " << prev << endl;

	cout << "How many days would you like to add to the current date: ";
	getline(cin, uInput);

	ValidateNum(&uInput);

	cout << date.returnDay() << " + " << uInput << " days is: " << date.returnAddDays(stoi(uInput)) << endl;

	system("pause");
	return 0;
}

// Validate the addition of numbers to the current day
void ValidateNum(string* input) {
	while (!regex_match((*input), regex("\\d+"))) {
		cout << "Wrong input, must be a positive whole number. Re-enter: ";
		getline(cin, (*input));
	}
}

// Validate the user input to be between the range of 0-6
void ValidateInput(string* input) {
	while (true)
	{
		if ((*input).length() != 1) {
			cout << "Wrong input, must be one character. Re-enter: ";
			getline(cin, (*input));
		}
		else if (!regex_match((*input), regex("[0-6]"))) {
			cout << "Wrong input, must be 0-6. Re-enter: ";
			getline(cin, (*input));
		}
		else {
			break;
		}
	}
}