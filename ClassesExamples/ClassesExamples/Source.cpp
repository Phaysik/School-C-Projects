/*Programmer: Matthew Moore
Description: Class Example
Date: 2-25-19
*/
#include <iostream>
using namespace std;

class CAdd {
	private:
		int x, y;

	public:
		void add(int, int);
		int ret() { return x + y; }
};

void CAdd::add(int a, int b) {
	x = a;
	y = b;
}

int main()
{
	CAdd myObject;

	myObject.add(4, 2);

	cout << myObject.ret() << endl;

	system("pause");
	return 0;
}