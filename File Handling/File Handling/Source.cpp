/*Programmer: Matthew Moore
Description: File Handling
Date: 2-12-19
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// Output file
	ofstream myfile;

	myfile.open("test.txt");

	myfile << "This is a test record for the file." << endl;
	myfile << "This is the second record written to the file." << endl;

	myfile.close();

	// Open and use a file append for output
	ofstream myfile2;

	myfile2.open("test2.txt", ios::app);	// The ios::app creates the file as append

	if (myfile2.is_open()) {
		myfile2 << "This is a test record for the file." << endl;
		myfile2 << "This is the second record written to the file." << endl;
	}
	else {
		cout << "Unable to open file test2.txt." << endl;
	}

	myfile.close();

	// Read a file in
	string line;
	ifstream myfile3("test2.txt");

	if (myfile3.is_open()) {
		while (getline(myfile3, line)) {
			cout << line << endl;
		}

		myfile3.close();
	}
	else {
		cout << "Can't open test2.txt as input." << endl;
	}

	system("pause");
	return 0;
}