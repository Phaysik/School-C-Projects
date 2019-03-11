/*Programmer: Matthew Moore
Description: Salary Application
Date: 1-18-19
*/
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	double salaries[6] = { 25000.68, 25000.68, 55000.00, 70000.44, 80200.32, 90500.55 };

	int uInput;

	cout << "Please enter in a number between 1-6 to display a salary: ";
	cin >> uInput;

	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Bad input. Re-enter: ";
			cin >> uInput;

			continue;
		}
		else if (uInput < 1 || uInput > 6)
		{
			cout << "Bad input. Re-enter: ";
			cin >> uInput;
		}
		else
		{
			break;
		}
	}

	system("pause");
	return 0;
}
