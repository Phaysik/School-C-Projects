/*Programmer: Matthew Moore
Description: IP Addresses
Date: 2-1-19
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Prototypes
string Binary(string);
string getClass(string);

int main()
{
	// Output file
	ifstream myfile("ip.txt");
	string line, lineCopy, segment, trueBinary, classBin;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			for (size_t i = 0; i < 4; i++)	// Get all 4 of the 8 digit parts of the string
			{
				string substring = line.substr(0 + (i * 8), 8);

				lineCopy = Binary(substring);

				trueBinary += lineCopy + ".";	// For display purposes
				segment += lineCopy;	// For getting the class
			}
			classBin = getClass(segment);
			trueBinary = trueBinary.substr(0, trueBinary.length() - 1);
			cout << trueBinary << " " << classBin << endl;

			segment = "", trueBinary = "";
		}

		cout << endl;

		myfile.close();	// Close the file
	}
	else {
		cout << "Can't open ip.txt as input." << endl;
	}

	system("pause");
	return 0;
}

string getClass(string segment) {	// Get the class of the ip address
	if (stoi(segment.substr(0, 3)) < 128) {
		return "[CLASS A]";
	}
	else if (stoi(segment.substr(0, 3)) < 192) {
		return "[CLASS B]";
	}
	else if (stoi(segment.substr(0, 3)) < 224) {
		return "[CLASS C]";
	}
	else if (stoi(segment.substr(0, 3)) < 240) {
		return "[CLASS D]";
	}
	else {
		return "[CLASS E]";
	}
}

string Binary(string binaryStr) {	// Convert the string to binary
	int num = stoi(binaryStr);
	int decimalVal = 0;
	int base = 1;
	int temp = num;

	while (temp)
	{
		int last_digit = temp % 10;
		temp = temp / 10;

		decimalVal += last_digit*base;

		base = base * 2;
	}

	return to_string(decimalVal);
}
