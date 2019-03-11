#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int cupNum;
	int plateNum;
	float cupCost;
	float plateCost;
	float cupTot;
	float plateTot;
	float subTot;
	float total;
	const double tax = .055;

	cout << "How many cups are ordered? ";
	cin >> cupNum;
	cout << endl << "How many plates are ordered? " ;
	cin >> plateNum;

	cout << endl << "What is the cost of the cups? ";
	cin >> cupCost;
	cout << endl << "What is the cost of the plates? ";
	cin >> plateCost;

	plateTot = plateNum * plateCost;
	cupTot = cupNum * cupCost;
	subTot = plateTot + cupTot;
	total = (subTot * tax) + subTot;

	cout << endl << "Cost of plates: $" << plateTot << endl << endl;
	cout << "Cost of cups: $" << cupTot << endl << endl;
	cout << "Subtotal: $" << subTot << endl << endl;
	cout << "Total: $" << total << endl << endl;

	system("pause");

	return 0;
}