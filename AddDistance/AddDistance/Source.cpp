/*Programmer: Matthew Moore
Description: Add Distance
Date: 2-25-19
*/
#include <iostream>
#include <string>
using namespace std;

class Distance {
private:
	int feet;
	int inches;

public:
	Distance();

	void getDistance() {
		cout << "How many feet: ";
		cin >> feet;

		cout << "How many inches: ";
		cin >> inches;

		if (inches > 12) {
			inches = 12;
		}
	}

	void showDist() {
		cout << "Feet: " << feet << endl << "Inches: " << inches << endl;
	}

	void addDist(Distance value1, Distance value2) {
		feet += value1.feet;
		inches += value1.inches;
		feet += value2.feet;
		inches += value2.inches;

		feet += inches > 12 ? (inches - inches % 12) / 12: 0;
		inches -= inches > 12 ? (inches - inches % 12) : 0;
	}

	void subDist(Distance value) {
		feet -= value.feet;
		inches -= value.inches;

		feet -= inches < 0 ? 1 : 0;
		inches += inches < 0 ? 12 : 0;
	}
};

Distance::Distance() {
	feet = 0;
	inches = 0;
}

int main()
{
	Distance firstDist;
	Distance secondDist;
	Distance addDistance;

	firstDist.getDistance();

	cout << endl;

	secondDist.getDistance();

	cout << endl;

	cout << "First distance: " << endl;

	firstDist.showDist();

	cout << endl;

	cout << "First distance: " << endl;

	secondDist.showDist();

	addDistance.addDist(firstDist, secondDist);

	cout << endl;
	
	cout << "Adding the two distances: " << endl;

	addDistance.showDist();

	secondDist.subDist(firstDist);

	cout << endl;
	
	cout << "Subtracting the first distance from the second distance: " << endl;

	secondDist.showDist();

	system("pause");
	return 0;
}