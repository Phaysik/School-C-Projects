/*Programmer: Matthew Moore
Description: Buying New Tablet
Date: 2-25-19
*/
#include <iostream>
#include <string>
#include <regex>
#include <vector>
using namespace std;
//Prototype
vector<int> GetTabletAndPrice();
void quit(string);
vector<string> Split(string);
void MaxArea(int, int);

int main()
{
	vector<int> tabletPrice = GetTabletAndPrice();
	int tablet = tabletPrice[0];
	int maxPrice = tabletPrice[1];

	MaxArea(tablet, maxPrice);

	system("pause");
	return 0;
}

// Gets the max area
void MaxArea(int tablet, int maxPrice) {
	vector<int> areas;

	for (size_t i = 0; i < tablet; i++)
	{
		string s;
		getline(cin, s);

		vector<string> vals = Split(s);

		if (vals.size() != 3) {
			quit("Must have width, height, and cost on one line.");
		}
		else if (stoi(vals[2]) < 1 || stoi(vals[2]) > 1000000) {
			quit("Price must be within the range of 1-1,000,000.");
		}
		else if (stoi(vals[1]) < 1 || stoi(vals[0]) < 1 || stoi(vals[1]) > 10000 || stoi(vals[0]) > 10000) {
			quit("Width and height must be within the range of 1-10,000.");
		}
		else {
			if (stoi(vals[2]) <= maxPrice) {
				areas.push_back(stoi(vals[0]) * stoi(vals[1]));
			}
		}
	}

	if (areas.size() > 0) {
		cout << endl << *max_element(areas.begin(), areas.end()) << endl;
	}
	else {
		cout << endl << "no tablet" << endl;
	}
}

//Quit the program
void quit(string msg) {
	system("cls");

	cout << msg << endl;

	system("pause");
	exit(0);
}

//Split any vector on whitespace
vector<string> Split(string s) {
	//Split on whitespace
	regex ws_re("\\s+");

	vector<string> result{
		sregex_token_iterator(s.begin(), s.end(), ws_re, -1),{}
	};

	return result;
}

//Get the tablet and price values
vector<int> GetTabletAndPrice() {
	string s;

	getline(cin, s);

	vector<string> result = Split(s);

	//Check ranges of numbers
	if (stoi(result[0]) > 100 || stoi(result[0]) < 1) {
		quit("Tablet number must be within 1-100.");
	}
	else if (stoi(result[1]) > 1000000 || stoi(result[1]) < 1) {
		quit("Your price range must be within 1-1,000,000.");
	}

	vector<int> values;

	//Add int values to vector
	for (size_t i = 0; i < result.size(); i++)
	{
		values.push_back(stoi(result[i]));
	}

	return values;
}