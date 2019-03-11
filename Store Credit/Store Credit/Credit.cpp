/*Programmer: Matthew Moore
Description: Store Credit
Date: 1-23-19
*/
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <limits>
using namespace std;
// Prototype
void ValidateCredit(string*, string);
void ValidateItemCount(string*, string);
vector<int> ValidatePrices(string*, string, string);
vector<int> GetAnswer(vector<int>, int);

int main()
{
	string credit = "";

	ValidateCredit(&credit, "Please enter the credit amount you have at the store: ");

	string itemCount = "";

	ValidateItemCount(&itemCount, "Please enter the amount of items you wish to purchase: ");

	string items = "";

	vector<int> itemPrices = ValidatePrices(&items, "Please enter the prices of your items seperated by a space: ", itemCount);

	vector<int> answer = GetAnswer(itemPrices, stoi(credit));

	cout << endl << "The two closest values to your credit limit is: " << answer[0] << ", " << answer[1] << endl;

	system("pause");
	return 0;
}

void ValidateCredit(string* x, string msg) {  // Validate
	cout << msg;
	getline(cin, *x);

	while (!(regex_match((*x), regex("\\d+")) && stoi(*x) >= 5 && stoi(*x) <= 1000)) {
		cout << "Please re-enter in your number: ";
		cin >> (*x);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input
	}
}

void ValidateItemCount(string* x, string msg) {  // Validate
	cout << msg;
	getline(cin, *x, '\n');

	while (!(regex_match((*x), regex("\\d+")) && stoi(*x) >= 3 && stoi(*x) <= 100)) {
		cout << "Please re-enter in your number: ";
		cin >> (*x);
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input
	}
}

vector<int> ValidatePrices(string* x, string msg, string itemCnt) {  // Validate
	bool isTrue = true;

	vector<int> vals;

	vals.resize(stoi(itemCnt));

	while (true) {
		cout << msg;
		getline(cin, *x, '\n');

		istringstream iss(*x);

		vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());  // Split the previous string, by spaces, into a vector

		if (results.size() != vals.size()) { // Check if the string amount eqauls the item count the user entered
			cout << "You did not enter the correct amount of items." << endl;
			continue;
		}

		for (int i = 0; i < results.size(); i++) {
			if (!(regex_match((results[i]), regex("\\d+")) && stoi(results[i]) >= 1 && stoi(results[i]) <= 1000)) {
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

			return vals;
		}
	}
}

vector<int> GetAnswer(vector<int> prices, int target) {   // Get the closest two numbers that add up to the target credit limit
	vector<int> vals;
	vals.resize(2);

	int difference = 2001;

	for (int i = 1; i <= prices.size(); i++) {
		for (int q = i + 1; q <= prices.size(); q++) {
			if ((prices[i - 1] + prices[q - 1]) == target) {
				vals[0] = i;
				vals[1] = q;

				cout << endl << "The two closest values to your credit limit is: " << vals[0] << ", " << vals[1] << endl;

				system("pause");

				exit(0);  // End the program
			}
			else if (prices[i - 1] + prices[q - 1] > target) { continue; }
			else if ((target - (prices[i - 1] + prices[q - 1])) < difference) {
				vals[0] = i;
				vals[1] = q;
				difference = (target - (prices[i - 1] + prices[q - 1]));
			}

		}
	}

	return vals;
}
