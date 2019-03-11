/*Programmer: Matthew Moore
Description: Valley Sort
Date: 2-1-19
*/
#include <iostream>
#include <regex>
#include <string>
#include <limits>
#include <sstream>
using namespace std;
//Prototypes
vector<int> ValidateLine(string*, string, int*);

int main()
{
	string uInput = "";
	int counter = 0;
	vector<vector<int>> allLines;

	while (true) {
		if (counter > 9) {
			cout << "You have hit the max limit of 10 inputs." << endl;
			break;
		}

		cout << "If you would like to stop the program please enter in a negative number: ";
		cin >> uInput;

		try {
			if (stoi(uInput) < 0) {
				break;
			}
			else {  // For if the user inputs a number that is greater than a zero
				uInput = "";
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input
			}
		}
		catch (...) { // Catch if user input is not a number
			uInput = "";
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input
		}

		vector<int> line = ValidateLine(&uInput, "Please enter in the numbers you would like to valley sort: ", &counter);
		allLines.resize(counter); // Resize the vector
		sort(line.begin(), line.end());  // Sort them in ascending order
		allLines.push_back(line); // Add vector to the 'total' vector
	}

	for (size_t i = 0; i < allLines.size(); i++) {
		if (allLines[i].size() % 2 == 0) { // Even number of values entered
			for (size_t x = 0; x < allLines[i].size() / 2; x++) { // Get the odd indexes
				cout << allLines[i][allLines[i].size() - 1 - (2 * x)] << " ";
			}
			for (size_t x = 0; x < allLines[i].size() / 2; x++) {  // Get the odd indexes
				cout << allLines[i][2 * x] << " ";
			}
		}
		else {  // Odd number of values entered
			for (size_t x = 0; x < allLines[i].size() / 2 + 1; x++) { // Get the even indexes
				cout << allLines[i][allLines[i].size() - 1 - (2 * x)] << " ";
			}
			for (size_t x = 0; x < allLines[i].size() - 1; x += 2) {  // Get the odd indexes
				cout << allLines[i][x + 1] << " ";
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

vector<int> ValidateLine(string* x, string msg, int* counter) {  // Validate
	bool isTrue = true;

	vector<int> vals;

	while (true) {
		cout << msg;
		getline(cin, *x, '\n');

		istringstream iss(*x);

		vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());  // Split the previous string, by spaces, into a vector

		vals.resize(results.size());  // Resize the int vector to be the size of the input

		for (int i = 0; i < results.size(); i++) {
			if (!(regex_match((results[i]), regex("\\d+")))) { //Validate for all numbers
				cout << "One input was not a whole number." << endl;

				isTrue = false;

				break;
			}
			else { isTrue = true; }
		}

		if (isTrue == true) {
			for (int i = 0; i < results.size(); i++) {
				vals[i] = stoi(results[i]); // Add the numbers to the array to return
			}

			*counter += 1;
			return vals;
		}
	}
}
