/*Programmer: Matthew Moore
Description: Tea Time
Date: 2-1-19
*/
#include <iostream>
#include <regex>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;
//Prototypes
void ValidateDouble(string*, string);
void ValidateInt(string*, string);
void ValidateChar(char*, string);

int main()
{
	string pounds = "", priceLB = "";
	char shipFee = ' ';

	ValidateInt(&pounds, "Please enter how many pounds of tea were ordered: ");
	ValidateDouble(&priceLB, "How much is the price per pound of tea: ");
	ValidateChar(&shipFee, "'Y', or 'N' for whether the customer should be charged a shipping fee: ");

	double total = (stoi(pounds) * stod(priceLB));

	if (tolower(shipFee) == 'y') {
		total += 15;
		cout << endl << "The total cost of the purchase is: $" << fixed << setprecision(2) << total << endl << endl;
	}
	else {
		cout << endl << "The total cost of the purchase is: $" << fixed << setprecision(2) << total << endl << endl;
	}

	system("pause");
	return 0;
}

void ValidateDouble(string* a, string msg) {  //Validate double
	cout << msg;
	getline(cin, *a);

	while (!regex_match((*a), regex("[+]?[0-9]*\\.?[0-9]+"))) {
		cout << "Please re-enter the number: ";
		cin >> *a;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input
	}
}

void ValidateInt(string* a, string msg) {  //Validate int
	cout << msg;
	getline(cin, *a);

	while (!regex_match((*a), regex("\\d+"))) {
		cout << "Please re-enter the number: ";
		cin >> *a;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input
	}
}

void ValidateChar(char* a, string msg) {  //Validate char
	cout << msg;
	cin >> *a;

	while (!regex_match(string(1, *a), regex("[YNyn]"))) {
		cout << "Please re-enter the letter: ";
		cin >> *a;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input
	}
}
