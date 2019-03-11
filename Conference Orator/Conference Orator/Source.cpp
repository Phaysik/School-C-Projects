/*Programmer: Matthew Moore
Description: Conference Orator
Date: 2-13-19
*/
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <iomanip>
using namespace std;
// Prototypes
void Menu(int, vector<string>, vector<string>, vector<string>, vector<double>);
void ValidateChar(string*);
void AddInfo(int*, vector<string>*, vector<string>*, vector<string>*, vector<double>*);
void DisplayInfo(int*, vector<string>*, vector<string>*, vector<string>*, vector<double>*);
void Search(int*, vector<string>*, vector<string>*, vector<string>*, vector<double>*);
void Delete(int*, vector<string>*, vector<string>*, vector<string>*, vector<double>*);
void ChangeInfo(int*, vector<string>*, vector<string>*, vector<string>*, vector<double>*);
void VPhone(string*, string);
void VPrice(double*, string);
void VSearch(string*, string);

int main()
{
	int counter = 0;

	vector<string> names, phoneNum, topic;
	vector<double> cost;

	Menu(counter, names, phoneNum, topic, cost);

	system("pause");
	return 0;
}

void Menu(int counter, vector<string> name, vector<string> phone, vector<string> topics, vector<double> costs) {
	string uInput = "";
	cout << "\t   ----------------------------------------------------------" << endl;
	cout << "\t\t   A: Add Information" << endl;
	cout << "\t\t   P: Display All Information" << endl;
	cout << "\t\t   S: Search For A Particular Orator Or Topic" << endl;
	cout << "\t\t   D: Delete An Orator" << endl;
	cout << "\t\t   C: Change The Information For An Orator" << endl;
	cout << "\t\t   E: Exit The Program" << endl;
	cout << "\t   ----------------------------------------------------------" << endl;

	cout << "Enter a character: ";
	getline(cin, uInput);

	ValidateChar(&uInput);

	char choice = uInput[0];

	switch (tolower(choice))	// Determine which method to go to
	{
	case 'a':
		counter++;
		AddInfo(&counter, &name, &phone, &topics, &costs);
		break;
	case 'p':
		DisplayInfo(&counter, &name, &phone, &topics, &costs);
		break;
	case 's':
		Search(&counter, &name, &phone, &topics, &costs);
		break;
	case 'd':
		Delete(&counter, &name, &phone, &topics, &costs);
		break;
	case 'c':
		ChangeInfo(&counter, &name, &phone, &topics, &costs);
		break;
	case 'e':
		ofstream myfile;

		myfile.open("orator.txt");

		for (size_t i = 0; i < name.size(); i++)
		{
			myfile << "Name: " << name[i] << endl << '\t';
			myfile << "Phone Number: " << phone[i] << endl << '\t';
			myfile << "Topic: " << topics[i] << endl << '\t';
			myfile << "Cost: $" << fixed << setprecision(2) << costs[i] << endl << endl;
		}

		system("cls");
		system("pause");

		exit(0);
	}
}

void ValidateChar(string* input) {	// Validate the character for the switch in Menu
	while (true) {
		if ((*input).size() > 1) {
			cout << "Re-enter: ";
			getline(cin, *input);
		}
		else if (!regex_match((*input), regex("[apsdecAPSDCE]"))) {
			cout << "Re-enter: ";
			getline(cin, *input);
		}
		else {
			break;
		}
	}
}

void VPhone(string* phone, string msg) {	// Validate phone number to be 10 characters and also all digits
	while (true) {
		cout << msg;
		getline(cin, *phone, '\n');

		if ((*phone).size() != 10) {
			cout << "Error: Must be 10 characters." << endl;
		}
		else if (!(regex_match((*phone), regex("^[0-9]+")))) {
			cout << "Error: Must be all numbers." << endl;
		}
		else {
			break;
		}
	}
}

void VPrice(double* cost, string msg) {	// Validate price to be a positive number
	while (true) {
		cout << msg;
		string val;
		getline(cin, val, '\n');

		if (!(regex_match(val, regex("[+]?[0-9]*\\.?[0-9]+")))) {
			cout << "Error: Must be postive number." << endl;
		}
		else {
			*cost = stod(val);
			break;
		}
	}
}

void VSearch(string* input, string msg) {	// Validate the character for the switch in Search
	while (true) {
		cout << msg;
		getline(cin, *input, '\n');

		if (!(regex_match((*input), regex("[otOT]")))) {
			cout << "Error: Must be an 'o' or a 't'." << endl;
		}
		else {
			break;
		}
	}
}

void AddInfo(int* count, vector<string>* names, vector<string>* phoneNums, vector<string>* topics, vector<double>* cost) {	// Add info to the vectors
	if ((*count) > 14) {	// Don't allow more info to be added
		cout << "You cannot add more conference orators." << endl;

		system("pause");
		system("cls");

		Menu((*count), (*names), (*phoneNums), (*topics), (*cost));
	}
	else {
		system("cls");
		
		string name;
		string phone;
		string topic;
		double price = 0;

		cout << "Enter an orator's name: ";
		getline(cin, name);

		VPhone(&phone, "Enter the orator's phone number: ");

		cout << "Enter the orator's topic: ";
		getline(cin, topic);

		VPrice(&price, "Enter the orator's cost: ");

		// Add values to vectors

		(*names).push_back(name);
		(*phoneNums).push_back(phone);
		(*topics).push_back(topic);
		(*cost).push_back(price);

		system("cls");

		Menu((*count), (*names), (*phoneNums), (*topics), (*cost));
	}
}

void DisplayInfo(int* count, vector<string>* names, vector<string>* phoneNums, vector<string>* topics, vector<double>* cost) {	// Display all the orators and their information
	system("cls");

	for (size_t i = 0; i < (*names).size(); i++)
	{
		cout << "Name: " << (*names)[i] << endl << '\t';
		cout << "Phone Number: " << (*phoneNums)[i] << endl << '\t';
		cout << "Topic: " << (*topics)[i] << endl << '\t';
		cout << "Cost: $" << fixed << setprecision(2) << (*cost)[i] << endl << endl;
	}

	system("pause");
	system("cls");

	Menu((*count), (*names), (*phoneNums), (*topics), (*cost));
}

void Search(int* count, vector<string>* names, vector<string>* phoneNums, vector<string>* topics, vector<double>* cost) {	// Search and display all orators and their topics given proper input
	string uInput;
	string name;
	string topic;

	VSearch(&uInput, "If you would like to search for an orator, enter an 'o',\nelse if you would like to search for a topic, enter an 't': ");

	char choice = uInput[0];

	switch (tolower(choice))
	{
	case 'o':
		cout << "Enter in the orator's name: ";
		getline(cin, name, '\n');

		system("cls");

		for (size_t i = 0; i < (*names).size(); i++)	// Show all orators that match the user's input
		{
			if (name == (*names)[i]) {
				cout << "Name: " << (*names)[i] << endl << '\t';
				cout << "Phone Number: " << (*phoneNums)[i] << endl << '\t';
				cout << "Topic: " << (*topics)[i] << endl << '\t';
				cout << "Cost: $" << fixed << setprecision(2) << (*cost)[i] << endl << endl;
			}
		}

		break;
	case 't':
		cout << "Enter in the orator's topic: ";
		getline(cin, topic, '\n');

		system("cls");

		for (size_t i = 0; i < (*topics).size(); i++)	// Show all topics that match the user's input
		{
			if (topic == (*topics)[i]) {
				cout << "Name: " << (*names)[i] << endl << '\t';
				cout << "Phone Number: " << (*phoneNums)[i] << endl << '\t';
				cout << "Topic: " << (*topics)[i] << endl << '\t';
				cout << "Cost: $" << fixed << setprecision(2) << (*cost)[i] << endl << endl;
			}
		}

		break;
	}

	system("pause");
	system("cls");

	Menu((*count), (*names), (*phoneNums), (*topics), (*cost));
}

void Delete(int* count, vector<string>* names, vector<string>* phoneNums, vector<string>* topics, vector<double>* cost) {	// Delete orator information
	string name;
	string phone;
	string topic;
	double price = 0;

	system("cls");

	cout << "All information must match to delete an orator and their information." << endl;

	cout << "Enter an orator's name: ";
	getline(cin, name);

	VPhone(&phone, "Enter the orator's phone number: ");

	cout << "Enter the orator's topic: ";
	getline(cin, topic);

	VPrice(&price, "Enter the orator's cost: ");

	system("cls");

	for (size_t i = 0; i < (*names).size(); i++)
	{
		if (name == (*names)[i] && phone == (*phoneNums)[i] && topic == (*topics)[i] && price == (*cost)[i]) {	// If the user inputs matched all values in vectors, delete the information
			cout << "Successfully deleted the following orator and their information: " << endl << endl;

			cout << "Name: " << (*names)[i] << endl << '\t';
			cout << "Phone Number: " << (*phoneNums)[i] << endl << '\t';
			cout << "Topic: " << (*topics)[i] << endl << '\t';
			cout << "Cost: $" << fixed << setprecision(2) << (*cost)[i] << endl << endl;

			(*names).erase((*names).begin() + i);
			(*phoneNums).erase((*phoneNums).begin() + i);
			(*topics).erase((*topics).begin() + i);
			(*cost).erase((*cost).begin() + i);

			system("pause");
			system("cls");

			*count--;

			Menu((*count), (*names), (*phoneNums), (*topics), (*cost));
		}
	}

	cout << "The information entered did not match any orator and their information. No info was deleted." << endl << endl;

	system("pause");
	system("cls");

	Menu((*count), (*names), (*phoneNums), (*topics), (*cost));
}

void ChangeInfo(int* count, vector<string>* names, vector<string>* phoneNums, vector<string>* topics, vector<double>* cost) {	// Change the information of an orator and their information
	string name;
	string phone;
	string topic;
	double price = 0;

	system("cls");

	cout << "All information must match to change an orator and their information." << endl;

	cout << "Enter an orator's name: ";
	getline(cin, name);

	VPhone(&phone, "Enter the orator's phone number: ");

	cout << "Enter the orator's topic: ";
	getline(cin, topic);

	VPrice(&price, "Enter the orator's cost: ");

	system("cls");

	for (size_t i = 0; i < (*names).size(); i++)
	{
		if (name == (*names)[i] && phone == (*phoneNums)[i] && topic == (*topics)[i] && price == (*cost)[i]) {	// If user input matches all the values in vectors
			// Get new values
			cout << "Enter in new information for the orator: " << endl << endl;

			cout << "Enter an orator's name: ";
			getline(cin, name);

			VPhone(&phone, "Enter the orator's phone number: ");

			cout << "Enter the orator's topic: ";
			getline(cin, topic);

			VPrice(&price, "Enter the orator's cost: ");

			system("cls");

			cout << "This is the old orator's information: " << endl << endl;

			cout << "Name: " << (*names)[i] << endl << '\t';
			cout << "Phone Number: " << (*phoneNums)[i] << endl << '\t';
			cout << "Topic: " << (*topics)[i] << endl << '\t';
			cout << "Cost: $" << fixed << setprecision(2) << (*cost)[i] << endl << endl;

			// Reassign values to the vector
			(*names)[i] = name;
			(*phoneNums)[i] = phone;
			(*topics)[i] = topic;
			(*cost)[i] = price;

			cout << "This is the new orator's information: " << endl << endl;

			cout << "Name: " << (*names)[i] << endl << '\t';
			cout << "Phone Number: " << (*phoneNums)[i] << endl << '\t';
			cout << "Topic: " << (*topics)[i] << endl << '\t';
			cout << "Cost: $" << fixed << setprecision(2) << (*cost)[i] << endl << endl;

			system("pause");
			system("cls");

			Menu((*count), (*names), (*phoneNums), (*topics), (*cost));
		}
	}

	cout << "The information entered did not match any orator and their information. No info was changed." << endl << endl;

	system("pause");
	system("cls");

	Menu((*count), (*names), (*phoneNums), (*topics), (*cost));
}
