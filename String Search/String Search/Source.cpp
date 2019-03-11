/*Programmer: Matthew Moore
Description: String Search
Date: 2-5-19
*/
#include <iostream>
#include <string>
using namespace std;
//Prototype
void DetermineSubstring(string, string);

int main()
{
	string s1 = "", s2 = "";

	cout << "This program is case sensitive." << endl;
	cout << "Enter the first string: ";
	getline(cin, s1);
	cout << "Add a '\\' before an '*' if you want to interpret the '*' literally." << endl;
	cout << "Otherwise it will assume you want to search between those characters." << endl;
	cout << "Enter the second string: ";
	getline(cin, s2);

	DetermineSubstring(s1, s2);
	system("pause");
	return 0;
}

void DetermineSubstring(string s1, string s2) {
	if (count(s2.begin(), s2.end(), '*') > 0) {	// If there is an asterisk in the second string
		// Initialize values
		int counter = count(s2.begin(), s2.end(), '*'), value = 0, startCount = 0, endCount = 0;
		string start = "", end = "";

		if (counter > 0) {	// If there is more than one asterisk
			for (size_t i = 0; i < count(s2.begin(), s2.end(), '\\'); i++) {
				if (count(s2.begin(), s2.end(), '\\') > i) {
					int pos = s2.find('\\');

					s2.replace(s2.find("\\"), 1, "");	// Replace the '\' with an empty string
					s2[pos] = '.';	// Replace the asterisk after the '\' with a '.'

					i--;
					counter--;
				}
			}

			if (count(s2.begin(), s2.end(), '*') > 1) {	// Quit if more than one non-literal asterisk
				cout << "You can only have one non-literal asterisk." << endl;

				system("pause");
				exit(0);
			}

			value = s2.find('*');	// Get the value of the asterisk that is not literal

			for (size_t i = 0; i < count(s2.begin(), s2.end(), '.'); i++) {	// Change the '.'(s) back to '*'(s)
				if (count(s2.begin(), s2.end(), '.') > i) {
					s2.replace(s2.find("."), 1, "*");
					i--;
				}
			}

			if (counter == 0) {	// If there is only literal asterisks
				if (s1.find(s2) != string::npos) {
					cout << s2 << " is a substring of " << s1 << endl;
				}
				else {
					cout << s2 << " is not a substring of " << s1 << endl;
				}

				system("pause");
				exit(0);
			}

			if (value == 0) {
				start = s2.substr(0, value + 1), end = s2.substr(value + 1);	// Get the first part before the '*' and the second part after the asterisk '*' respectively
			}
			else {
				start = s2.substr(0, value), end = s2.substr(value + 1);	// Get the first part before the '*' and the second part after the asterisk '*' respectively
			}
		}
		else {
			start = s2.substr(0, s2.find('*')), end = s2.substr(s2.find('*') + 1);	// Get the first part before the '*' and the second part after the asterisk '*' respectively
		}

		for (size_t i = 0; i < s1.size(); i++) {
			if (s1[i] == start[startCount]) { // Determine if the character of the first string matches the initial character of the substring from before the asterisk {
				for (size_t x = 0; x < startCount + 1; x++) {
					if (startCount == start.size()) {
						break;
					}
					else if (s1[i] == start[x]) {
						startCount++;
						i++;
					}
					else {
						startCount = 0;
					}
				}
			}

			if (s1[i] == end[endCount] && startCount == start.size()) { // Determine if the character of the first string matches the initial character of the substring from after the asterisk
				for (size_t x = 0; x < endCount + 1; x++) {
					if (endCount == end.size()) {	// Break from the loop
						break;
					}
					else if (s1[i] == end[x]) {
						endCount++;
						i++;
					}
					else {
						endCount == 0;
					}
				}
			}
		}
		if (count(s2.begin(), s2.end(), '*') > 1) {	// Show the user where the end and beginning of the substring is
			s2.replace(value, 1, "->");
		}
		else {
			s2.replace(s2.find('*'), 1, "->");
		}

		if (startCount != start.size() || endCount != end.size()) {	// If the substring was not contained in the original string
			cout << s2 << " is not a substring of " << s1 << endl;
		}
		else {
			cout << s2 << " is a substring of " << s1 << endl;
		}
	}
	else {	// If there is not asterisk in the second string
		if (s1.find(s2) != string::npos) {
			cout << s2 << " is a substring of " << s1 << endl;
		}
		else {
			cout << s2 << " is not a substring of " << s1 << endl;
		}
	}
}