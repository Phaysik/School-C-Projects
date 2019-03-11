/*Programmer: Matthew Moore
Description: Hello World Class
Date: 2-25-19
*/
#include <iostream>
using namespace std;

class Hello {
	public:
		void sayHello() {
			cout << "Hello World" << endl;
		}
};
int main()
{
	Hello myObject;

	myObject.sayHello();

	system("pause");
	return 0;
}