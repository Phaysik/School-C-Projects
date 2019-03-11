/*Programmer: Matthew Moore
Description: Add them up
Date: 2-12-19
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// Output file
	ifstream myfile("input.txt");
	string line;

	int total = 0;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			total += stoi(line);
		}

		myfile.close();

		cout << "The total value is: " << total << endl;
	}
	else {
		cout << "Can't open input.txt as input." << endl;
	}


	system("pause");
	return 0;
}