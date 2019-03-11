/*Programmer: Matthew Moore
Description: Area
Date: 1-29-19
*/
#include <iostream>
#include <regex>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;
//Prototypes
void ValidateSR(string*, string);
void ValidateNum(string*, string);
double Area(double);
double Area(double, double);

int main()
{
	string uInput = "", length = "", width = "", square = "";
	cout << "This program will determine the area of either a rectangle or a square." << endl;

	ValidateSR(&uInput, "Please enter a 's' for square, or a 'r' for rectangle: ");

	if (uInput == "s" || uInput == "S") { //Square
		ValidateNum(&square, "Please enter in the length of the square: ");
		cout << endl << "The area of your square is: " << fixed << setprecision(2) << Area(stod(square)) << endl << endl;
	}
	else {  //Rectangle
		ValidateNum(&length, "Please enter in the length of the rectangle: ");
		ValidateNum(&width, "Please enter in the width of the rectangle: ");
		cout << endl << "The area of your rectangle is: " << fixed << setprecision(2) << Area(stod(length), stod(width)) << endl << endl;

	}

	system("pause");
	return 0;
}

void ValidateSR(string* a, string msg) {  //Validate s or r
	cout << msg;
	getline(cin, *a);

	while (!regex_match((*a), regex("[srSR]"))) {
		cout << "Please re-enter in your letter: ";
		cin >> (*a);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input
	}
}

void ValidateNum(string* a, string msg) { //Validate number
	cout << msg;
	getline(cin, *a);

	while (!regex_match((*a), regex("[+]?[0-9]*\\.?[0-9]+"))) {
		cout << "Please re-enter in your number: ";
		cin >> (*a);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input
	}
}

double Area(double side) { //Square
	return side * 2;
}

double Area(double len, double wid) {  // Rectangle
	return len * wid;
}
