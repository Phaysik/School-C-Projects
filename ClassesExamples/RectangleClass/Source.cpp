/*Programmer: Matthew Moore
Description: Rectangle Class
Date: 2-25-19
*/
#include <iostream>
using namespace std;

//Base Class
class Shape {
public: void setWidth(int w) {
	width = w;
}

public: void setHeight(int h) {
	height = h;
}

protected:
	int width;
	int height;
};

//Base class PaintCost
class PaintCost {
public:
	int getCost(int area) {
		return area * 70;
	}
};

//Derived Class
class Rectangle : public Shape, public PaintCost {
public:
	int getArea() {
		return(width * height);
	}
};

int main()
{
	Rectangle myObject;

	int area;

	myObject.setWidth(5);
	myObject.setHeight(7);

	//Print the area of the object
	cout << "Total area: " << myObject.getArea() << endl;

	cout << "Total paint cost: $" << myObject.getCost(myObject.getArea()) << endl;

	system("pause");
	return 0;
}