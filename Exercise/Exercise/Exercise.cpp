/*Programmer: Matthew Moore
Description: Exercise
Date: 1-7-19
*/
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
using namespace std;

int main()
{
	string gender, activityLevel, weight;
	double Weight;

	cout << "Please enter in your gender (Male or Female): ";
	cin >> gender;
	transform(gender.begin(), gender.end(), gender.begin(), ::tolower);		//Lowercase the string
	cout << "Please enter in your activity level (Moderate or Relatively): ";
	cin >> activityLevel;
	transform(activityLevel.begin(), activityLevel.end(), activityLevel.begin(), ::tolower);
	cout << "Please enter in your weight: ";
	cin >> weight;

	while (true)
	{
		if (gender != "male" && gender != "female")
		{
			cout << gender;
			cout << "Please enter in either male or female for your gender: ";
			cin >> gender;
		}
		else if (activityLevel != "moderate" && activityLevel != "relatively") 
		{
			cout << "Please enter in either moderate or relatively for your activity level: ";
			cin >> activityLevel;
		}
		else if (!regex_match(weight, regex("[-+]?[0-9]*\.?[0-9]+")))
		{
			cout << "Please enter in a valid decimal number for your weight: ";
			cin >> weight;
		}
		else
		{
			break;
		}
	}

	if (activityLevel == "moderate")
	{
		if (gender == "male")
		{
			Weight = stod(weight);
			Weight *= 15;
		}
		else
		{
			Weight = stod(weight);
			Weight *= 12;
		}
	}
	else
	{
		if (gender == "male")
		{
			Weight = stod(weight);
			Weight *= 13;
		}
		else
		{
			Weight = stod(weight);
			Weight *= 10;
		}
	}
	cout << endl << "Gender: " << gender << endl << "Activity Level: " << activityLevel << endl << "Total daily calories needed: " << fixed << setprecision(2) << Weight;
	cout << endl << endl;

	system("pause");
	return 0;
}