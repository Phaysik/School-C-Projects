/*Programmer: Matthew Moore
Description: Toll Booth
Date: 2-26-19
*/
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
using namespace std;

//Class
class tollBooth {
	private:
		int numCars;
		double moneyCollected;
	public:
		tollBooth();

		const void payingCar() {
			numCars++;
			moneyCollected += .5;
		}

		const void nopayCar() {
			numCars++;
		}

		void display() {
			cout << "The total amount of cars that have passed is: " << numCars << endl;
			cout << "The total amount of money collected is: $" << fixed << setprecision(2) << moneyCollected << endl;
		}
};

//Constructor
tollBooth::tollBooth() {
	numCars = 0;
	moneyCollected = 0.0;
}

//Prototype
void Menu(tollBooth*);
void ValidateChar(string*);

int main()
{
	tollBooth car;

	while (true)
	{
		system("cls");
		Menu(&car);
	}

	system("pause");
	return 0;
}

//Display the menu
void Menu(tollBooth* car) {
	string uInput = "";
	cout << "\t   ----------------------------------------------------------" << endl;
	cout << "\t\t   P: Paying Car" << endl;
	cout << "\t\t   N: Non-Paying Car" << endl;
	cout << "\t\t   D: Display Total Cars and Total Cash" << endl;
	cout << "\t\t   E: Exit The Program" << endl;
	cout << "\t   ----------------------------------------------------------" << endl;

	cout << "Enter a character: ";
	getline(cin, uInput);

	ValidateChar(&uInput);

	char character = uInput[0];

	//Determine what class method to call
	switch (tolower(character))
	{
	case 'p':
		(*car).payingCar();
		system("pause");
		break;
	case 'n':
		(*car).nopayCar();
		system("pause");
		break;
	case 'd':
		(*car).display();
		system("pause");
		break;
	case 'e':
		system("cls");
		system("pause");

		exit(0);
	}
}

void ValidateChar(string* input) {	// Validate the character for the switch in Menu
	while (true) {
		if ((*input).size() > 1) {
			cout << "Input cannot be greater than one character. Re-enter: ";
			getline(cin, *input);
		}
		else if (!regex_match((*input), regex("[pndePNDE]"))) {
			cout << "Character must match one from the menu. Re-enter: ";
			getline(cin, *input);
		}
		else {
			break;
		}
	}
}