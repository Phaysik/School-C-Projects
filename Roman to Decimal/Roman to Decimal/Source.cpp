/*Programmer: Matthew Moore
Description: Roman Numeral to Decimal Converter
Date: 3-7-19
*/
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>
#include <algorithm>
using namespace std;
vector<char> Split(string);

class Roman {
private:
	string input;
	vector<char> splitInput;
	int romanVal;
	int hold;
	map<char, int> dict;
public:
	Roman();

	void setInput(string inp) {
		input = inp;
		splitInput = Split(input);
	}

	// Return the value of the roman numeral input
	string getValue() {
		while (splitInput.size())
		{
			hold = dict[toupper(splitInput[0])];
			if (splitInput.size() != 1) {
				splitInput.erase(splitInput.begin());
				romanVal += hold * ((hold < dict[toupper(splitInput[0])]) ? -1 : 1);
			}
			else {
				romanVal += hold * ((hold < dict[toupper(splitInput[0])]) ? -1 : 1);
				splitInput.erase(splitInput.begin());
			}
		}
		transform(input.begin(), input.end(), input.begin(), ::toupper);

		return "The decimal value of " + input + " is: " + to_string(romanVal);
	}
};

Roman::Roman() {
	input = "";
	romanVal = 0;
	hold = 0;
	splitInput.resize(input.length());
	dict = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
}

// Prototype
void ValidateInput(string*);

int main()
{
	string uInput;
	cout << "Enter in a set of roman numerals: ";
	getline(cin, uInput);

	ValidateInput(&uInput);

	Roman romanType;

	romanType.setInput(uInput);
	cout << romanType.getValue() << endl;

	system("pause");
	return 0;
}

// Split the string on character
vector<char> Split(string input) {
	return vector<char>(input.begin(), input.end());
}

// Make sure the user inputs valid roman characters
void ValidateInput(string* input) {
	bool loop = true;
	while (loop == true)
	{
		vector<char> inputVals(Split((*input)));

		for (size_t i = 0; i < inputVals.size(); i++)
		{
			if (!regex_match(string(1, inputVals[i]), regex("[iIvVxXlLcCdDmM]"))) {
				cout << "Input is not valid. Re-enter: ";
				getline(cin, (*input));
				loop = false;
				break;
			}
		}
		if (loop == true) { break; }
		else { loop = true; }
	}

}
