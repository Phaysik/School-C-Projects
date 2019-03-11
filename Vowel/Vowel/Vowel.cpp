/*Programmer: Matthew Moore
Description: Vowel or Consonant
Date: 1-7-19
*/
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
	char character;
	string determine;

	cout << "Please enter in a single character: ";
	cin >> character;

	if (regex_match(string(1, character), regex("[abcdefghijklmnopqrstuvwxyz]"))) 
	{
		determine = regex_match(string(1, character), regex("[aeiou]")) ? "vowel" : "consonant";
	}
	else 
	{
		determine = "not a letter";
	}

	cout << endl << "Your input is " << determine;

	cout << endl << endl;
	system("pause");
	return 0;
}