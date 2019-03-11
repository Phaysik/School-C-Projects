/*Programmer: Matthew Moore
Description: Shut the Box
Date: 3-4-19
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <regex>
#include <ctime>
#include <numeric>
#include <sstream>
using namespace std;
// Prototypes
vector<string> Split(string);
vector<string> getPartitions(int);
string pushBack(vector<int>, int);
string pushBack(vector<string>);
bool uniqueCharacters(string);
void GetUnique(vector<string>*);
void GetValid(vector<string>*, vector<string>, char, vector<char>);
void ZeroLeft(vector<string>, vector<char>, int, int*);
bool CheckBoard(vector<char>);
void EraseWhite(vector<string>*);

// For partitions
string pushBack(vector<int> p, int n)
{
	string vals;
	vector<int> forSort;
	for (int i = 0; i < n; i++)
		forSort.push_back(p[i]);

	sort(forSort.begin(), forSort.end());

	for (size_t i = 0; i < forSort.size(); i++)
	{
		vals += to_string(forSort[i]) + " ";
	}

	return vals.substr(0, vals.length() - 1);
}

// For user input
string pushBack(vector<string> p)
{
	string vals;
	vector<int> forSort;
	for (int i = 0; i < p.size(); i++)
		forSort.push_back(stoi(p[i]));

	sort(forSort.begin(), forSort.end());

	for (size_t i = 0; i < forSort.size(); i++)
	{
		vals += to_string(forSort[i]) + " ";
	}

	return vals.substr(0, vals.length() - 1);
}

// Get all the integer partitions of a number
vector<string> getPartitions(int n)
{
	vector<int>p; // An array to store a partition
	p.resize(n);
	vector<string>parts;
	int k = 0;  // Index of last element in a partition 
	p[k] = n;  // Initialize first partition as number itself 

			   // This loop first prints current partition, then generates next 
			   // partition. The loop stops when the current partition has all 1s 
	while (true)
	{
		// print current partition 
		parts.push_back(pushBack(p, k + 1));

		//parts.push_back(pushBack(p, k + 1));

		// Generate next partition 

		// Find the rightmost non-one value in p[]. Also, update the 
		// rem_val so that we know how much value can be accommodated 
		int rem_val = 0;
		while (k >= 0 && p[k] == 1)
		{
			rem_val += p[k];
			k--;
		}

		// if k < 0, all the values are 1 so there are no more partitions 
		if (k < 0)  return parts;

		// Decrease the p[k] found above and adjust the rem_val 
		p[k]--;
		rem_val++;


		// If rem_val is more, then the sorted order is violated.  Divide 
		// rem_val in different values of size p[k] and copy these values at 
		// different positions after p[k] 
		while (rem_val > p[k])
		{
			p[k + 1] = p[k];
			rem_val = rem_val - p[k];
			k++;
		}

		// Copy rem_val to next position and increment position 
		p[k + 1] = rem_val;
		k++;
	}
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

// Determine if the vector is made up of unique characters
bool uniqueCharacters(string str)
{
	vector<string> strung = Split(str);

	for (int i = 0; i < strung.size() - 1; i++) {

		// if at any time, 2 adjacent 
		// elements become equal, 
		// return false 
		if (strung[i] == strung[i + 1]) {
			return false;
		}
	}
	return true;
}

class Box {
private:
	int random;
	int random2;
	string uInput;
	vector<string> addup;
	vector<string> partitions;
	vector<string> checker;
	char val;
	bool play;
public:
	Box();
	// Diplsay the board
	void display(vector<char>* rows) {
		cout << (char)254u << " = closed value." << endl;

		for (size_t i = 0; i < (*rows).size(); i++)
		{
			cout << (*rows)[i] << " ";
		}

		cout << endl;
	}

	// Determine if the player can play
	bool canPlay() {
		return play == true ? 1 : 0;
	}

	// Determine if the last three values are closed
	bool lastThree(vector<char>* rows) {
		if ((*rows)[(*rows).size() - 3] == (char)254u && (*rows)[(*rows).size() - 2] == (char)254u && (*rows)[(*rows).size() - 1] == (char)254u) {
			return true;
		}
		else {
			return false;
		}
	}

	// Roll one dice
	void rollOne(vector<char>* rows, bool* isTrue, int* score) {
		srand(time(0));
		random = (rand() % 6) + 1;
		cout << "Your dice roll is: " << random << endl;
		display(rows);

		closeValue(random, rows, isTrue, score);
	}

	// Roll two dice
	void rollTwo(vector<char>* rows, bool* isTrue, int* score) {
		srand(time(0));
		random = (rand() % 6) + 1;
		random2 = (rand() % 6) + 1;
		random += random2;
		cout << "Your dice roll is: " << random << endl;
		display(rows);

		closeValue(random, rows, isTrue, score);
	}

	// Close a/some value(s) on the board
	void closeValue(int random, vector<char>* rows, bool* isTrue, int* score) {
		partitions = getPartitions(random);
		GetUnique(&partitions);
		GetValid(&partitions, checker, val, (*rows));
		if (partitions.size() == 0) {
			system("cls");
			display(rows);
			play = false;
			(*isTrue) = false;

			ZeroLeft(partitions, (*rows), random, score);
			return;
		}

		cout << "Enter any number(s) that add up to or equal the random number: " << endl;
		getline(cin, uInput);

		// Make sure the vector is only numbers
		while (uInput.find_first_not_of("0123456789 ") == string::npos == 0) {
			cout << "Must be all numbers. Re-enter: ";
			getline(cin, uInput);
		}

		addup = Split(uInput);

		EraseWhite(&addup);

		uInput = pushBack(addup);

		if (addup.size() == 1 && stoi(addup[0]) == random && random == (*rows)[stoi(addup[0]) - 1] - '0') {
			(*rows)[stoi(addup[0]) - 1] = (char)254u;
			system("cls");
			cout << "This is the new board: " << endl;
			display(rows);
			(*isTrue) = false;
		}
		else {
			while ((*isTrue) == true)
			{
				for (size_t i = 0; i < partitions.size(); i++)
				{
					if (uInput == partitions[i]) {
						for (size_t j = 0; j < addup.size(); j++)
						{
							(*rows)[stoi(addup[j]) - 1] = (char)254u;
						}
						system("cls");
						(*isTrue) = false;
						cout << "This is the new board: " << endl;
						display(rows);
						break;
					}
				}
				if ((*isTrue) == true) {
					cout << "Enter any number(s) that add up to or equal the random number: " << endl;
					getline(cin, uInput);

					while (uInput.find_first_not_of("0123456789 ") == string::npos == 0) {
						cout << "Must be all numbers. Re-enter: ";
						getline(cin, uInput);
					}

					addup = Split(uInput);

					EraseWhite(&addup);

					uInput = pushBack(addup);
				}
			}
		}

		if (CheckBoard((*rows)) == 1) {
			system("cls");
			display(rows);
			cout << "You have won the game by clearing the entire board." << endl;

			system("pause");

			exit(0);
		}
	}
};

// Constructor
Box::Box() {
	random = 0;
	random2 = 0;
	uInput = "";
	val = ' ';
	play = true;
}

//Prototypes
void Menu(Box*, vector<char>*, string, int*, bool*);
void ValidateChar(string*);

int main()
{
	vector<char> rows = { (char)254u, (char)254u, '3', (char)254u, '5', (char)254u, '7', (char)254u, '9' };

	Box player;
	Box player2;
	int val = 0;
	bool isTrue = true;
	int player1Score = 0;
	int player2Score = 0;

	while (true)
	{
		if (val % 2 == 0 && player.canPlay() == 1) {
			Menu(&player, &rows, "player one: ", &player1Score, &isTrue);
			isTrue = true;
		}
		else if(player2.canPlay() == 1) {
			Menu(&player2, &rows, "player two: ", &player2Score, &isTrue);
			isTrue = true;
		}
		else if(player.canPlay() == 0 && player2.canPlay() == 0) {
			system("cls");
			cout << "Player ones score is: " << player1Score << endl;
			cout << "Player twos score is: " << player2Score << endl;
			cout << ((player1Score < player2Score) ? "Player one wins!" : (player1Score == player2Score) ? "Both players tied!" : "Player two wins!") << endl;
			break;
		}
		val++;
	}

	system("pause");
	return 0;
}

// Display a menu
void Menu(Box* person, vector<char>* rows, string player, int* playerScore, bool* isTrue) {
	string uInput = "";
	while ((*isTrue) == true)
	{
		system("cls");
		cout << "\t   ----------------------------------------------------------" << endl;
		cout << "\t\t   D: Display Rows" << endl;
		cout << "\t\t   R: Roll 1 Dice" << endl;
		cout << "\t\t   T: Roll 2 Dice" << endl;
		cout << "\t\t   E: Exit The Program" << endl;
		cout << "\t   ----------------------------------------------------------" << endl;

		cout << "Enter a character, " << player;
		getline(cin, uInput);

		ValidateChar(&uInput);
		char character = uInput[0];

		//Determine what class method to call
		switch (tolower(character))
		{
		case 'd':
			(*person).display(rows);
			system("pause");
			break;
		case 'r':
			if ((*person).lastThree(rows) != 1) {
				cout << "7, 8, and 9 must be closed to roll only one dice." << endl;
			}
			else {
				(*person).rollOne(rows, isTrue, playerScore);
			}
			system("pause");
			break;
		case 't':
			(*person).rollTwo(rows, isTrue, playerScore);
			system("pause");
			break;
		case 'e':
			system("cls");
			system("pause");

			exit(0);
		}
	}

}

void ValidateChar(string* input) {	// Validate the character for the switch in Menu
	while (true) {
		if ((*input).size() > 1) {
			cout << "Input cannot be greater than one character. Re-enter: ";
			getline(cin, *input);
		}
		else if (!regex_match((*input), regex("[dDrRtTeE]"))) {
			cout << "Character must match one from the menu. Re-enter: ";
			getline(cin, *input);
		}
		else {
			break;
		}
	}
}

// Get the integer partitions that are unique
void GetUnique(vector<string>* partitions) {
	for (size_t i = 0; i < (*partitions).size(); i++)
	{
		if (!uniqueCharacters((*partitions)[i])) {
			(*partitions).erase((*partitions).begin() + i);
			i--;
		}
	}
}

// Determine if the combination is available on the board
void GetValid(vector<string>* partitions, vector<string> checker, char val, vector<char> rows) {
	string value = "";
	for (size_t i = 0; i < (*partitions).size(); i++)
	{
		checker = Split((*partitions)[i]);
		for (size_t j = 0; j < checker.size(); j++)
		{
			value = checker[j];

			val = value[0];

			if (find(rows.begin(), rows.end(), val) != rows.end()) {
				continue;
			}
			else {
				(*partitions).erase((*partitions).begin() + i);
				i--;
				break;
			}
		}
	}
}

// Determine if there are no possible combination to reach the rolled number
void ZeroLeft(vector<string> partitions, vector<char> rows, int random, int* sum) {
	cout << "There are no possible combinations that reach the rolled value of: " << random << endl;

	for (size_t i = 0; i < rows.size(); i++)
	{
		if (rows[i] != (char)254u) {
			(*sum) += rows[i] - '0';
		}
	}

	cout << "Your score is: " << (*sum) << endl;
}

// Check to see if the entire board is covered
bool CheckBoard(vector<char> rows) {
	for (size_t i = 0; i < rows.size(); i++)
	{
		if (rows[i] != (char)254u) {
			return false;
		}
	}
	return true;
}

// Erase all empty values in the vector
void EraseWhite(vector<string>* addup) {
	for (size_t i = 0; i < (*addup).size(); i++)
	{
		if ((*addup)[i] == "") {
			(*addup).erase((*addup).begin() + i);
		}
	}
}