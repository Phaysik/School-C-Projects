/*Programmer: Matthew Moore
Description: Piggie Bank
Date: 1-29-19
*/
#include <iostream>
#include <regex>
#include <string>
#include <limits>
using namespace std;
//Prototypes
void DisplayMenu(double*);
void Validate(string*, string);
void altPiggie(double, double*);
void altPiggie(double, double, double*);

int main()
{
	double balance = 50;
	char uInput = ' ';

	while (true) {  //Sentinel
		cout << "If you would like to stop the program please enter 'q': ";
		cin >> uInput;

		if (tolower(uInput) == 'q') {
			break;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input
		DisplayMenu(&balance);
	}

	cout << "Your balance is: " << balance << endl;
	system("pause");
	return 0;
}

void DisplayMenu(double* balance) { //Get amounts
	string depo = "", withdrawl = "";

	Validate(&depo, "Please enter in an amount to deposit: ");
	Validate(&withdrawl, "Please enter in an amount to withdrawl: ");

	if (stod(withdrawl) == 0) {
		altPiggie(stod(depo), balance);
	}
	else {
		altPiggie(stod(depo), stod(withdrawl), balance);
	}
}

void Validate(string* a, string msg) {  //Validate
	cout << msg;
	getline(cin, *a);

	while (!regex_match((*a), regex("[+]?[0-9]*\\.?[0-9]+"))) {
		cout << "Please re-enter in your number: ";
		cin >> (*a);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input
	}
}

void altPiggie(double deposit, double* bal) { //Only deposit
	(*+bal) += deposit;
	cout << "Your new balance is: " << (*+bal) << endl;
}

void altPiggie(double deposit, double withdraw, double* bal) {  //Deposit and withdraw
	(*+bal) += deposit;
	(*+bal) -= withdraw;
	cout << "Your new balance is: " << (*+bal) << endl;
}
