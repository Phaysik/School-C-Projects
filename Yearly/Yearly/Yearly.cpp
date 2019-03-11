/*Programmer: Matthew Moore
   Description: Yearly Expenses
   Date: 1-18-19
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main()
{
  //Create a lot of arrays
  double expenses[15][12];
  double totalMonth[15] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  string costs[15] = {"mortgage/rent", "electricity", "water", "internet", "cell phone/television", "insurance", "car payments", "gas", "trash", "credit card", "food", "property tax", "child support", "student loan", "gasoline"};

  double uInput = 0.0;

  for (int i = 0; i < (sizeof(months) / sizeof(months[0])); i++) {
    for (int x = 0; x < (sizeof(costs) / sizeof(costs[0])); x++) {
      cout << "Please enter in the cost of your " << costs[x] << " bill for " << months[i] << ": ";
      cin >> uInput;

      while(true) //Validation
      {
      	if(cin.fail())
      	{
      		cin.clear();
      		cin.ignore(numeric_limits<streamsize>::max(),'\n');

          cout << "Invalid input. Please re-enter: ";
          cin >> uInput;
      		continue;
      	}
      	else
      	{
      		break;
      	}
      }

      totalMonth[x] += uInput;
      expenses[x][i] = uInput;
    }
  }

  system("cls");

  for (int i = 0; i < (sizeof(costs) / sizeof(costs[0])); i++) {  //Display all the expenses for each bill for every month
    cout << costs[i] << ":" << endl;

    for (int x = 0; x < (sizeof(months) / sizeof(months[0])); x++) {
      cout << months[x] << " = $" << fixed << setprecision(2) << expenses[i][x] << endl;
    }

    cout << endl;
  }

  cout << "To see the total cost for each category ";

  system("pause");
  system("cls");

  for (int i = 0; i < (sizeof(totalMonth) / sizeof(totalMonth[0])); i++) {  //Display the total yearly cost for each bill
    cout << "Total for the " << costs[i] << " bill is: $" << fixed << setprecision(2) << totalMonth[i] << endl;
  }

  cout << endl;

	system("pause");
	return 0;
}
