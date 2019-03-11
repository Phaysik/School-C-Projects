/*Programmer: Matthew Moore
Description: Random
Date: 3-4-19
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int random = rand();

	cout << "Seed = 1, Random number = " << random << endl;

	srand(time(0));
	random = rand();
	cout << "Seed = " << time(0) << endl << "Random number = " << random << endl;

	cout << "Random number (1-10) = " << (rand() % 10) + 1 << endl;

	system("pause");
	return 0;
}