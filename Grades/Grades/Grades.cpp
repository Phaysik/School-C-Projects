/*Programmer: Matthew Moore
Description: Grades
Date: 1-9-19
*/
#include <iostream>
#include <string>
#include <regex>
using namespace std;

void Projects(string projects[], int i)	//Validate Projects
{
	while (true)
	{
		if (!regex_match(projects[i], regex("[+]?[0-9]*\\.?[0-9]+")))
		{
			cout << "Please re-enter in your project grade: ";
			cin >> projects[i];
		}
		else if (stod(projects[i]) > 50)
		{
			cout << "The maximum score is 50. Please re-enter: ";
			cin >> projects[i];
		}
		else
		{
			break;
		}
	}
}

void Tests(string tests[], int i)	//Validate Tests
{
	while (true)
	{
		if (!regex_match(tests[i], regex("[+]?[0-9]*\\.?[0-9]+")))
		{
			cout << "Please re-enter in your test grade: ";
			cin >> tests[i];
		}
		else if (stod(tests[i]) > 100)
		{
			cout << "The maximum score is 100. Please re-enter: ";
			cin >> tests[i];
		}
		else
		{
			break;
		}
	}
}

int main()
{
	string projects[4];
	string tests[2];

	double sum = 0;
	
	for (int i = 0; i < 6; i++)
	{
		while (i < 4) 
		{
			cout << "Please enter in your project grade: ";
			cin  >> projects[i];

			Projects(projects, i);

			i++;
		}

		while (i > 4 && i < 7)
		{
			cout << "Please enter in your test grade: ";
			cin >> tests[i - 5];

			Tests(tests, i - 5);

			i++;

			if (i == 7) 
			{
				for (int i = 0; i < 6; i++)
				{
					if (i < 4)
					{
						sum += stod(projects[i]);
					}
					else
					{
						sum += stod(tests[i - 4]);
					}
				}
			}
		}
	}

	cout << endl;

	if (sum >= 360)
	{
		cout << "Your points: " << sum << endl << "Your grade: A" << endl;
	}
	else if (sum >= 320)
	{
		cout << "Your points: " << sum << endl << "Your grade: B" << endl;
	}
	else if (sum >= 280)
	{
		cout << "Your points: " << sum << endl << "Your grade: C" << endl;
	}
	else if (sum >= 340)
	{
		cout << "Your points: " << sum << endl << "Your grade: D" << endl;
	}
	else
	{
		cout << "Your points: " << sum << endl << "Your grade: F" << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}


