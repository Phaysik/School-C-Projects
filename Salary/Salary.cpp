/*Programmer: Matthew Moore
   Description: Salary Application
   Date: 1-18-19
*/
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main()
{
  double salaries[6] = {25000.68, 25000.68, 55000.00, 70000.44, 80200.32, 90500.55};

  int uInput;

  cout << "Please enter in a number between 1-6 to display a salary: ";
  cin >> uInput;

  while(true)
  {
  	if(cin.fail() || (uInput < 1 || uInput > 6))
  	{
  		cin.clear();
  		cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "Bad input. Please re-enter: ";
      cin >> uInput;

  		continue;
  	}
  	else
  	{
  		break;
  	}
  }

  cout << "The salary for number " << uInput << " is $" << fixed << setprecision(2) << salaries[uInput - 1] << endl;

	system("pause");
	return 0;
}
