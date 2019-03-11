/*Programmer: Matthew Moore
   Description: Overload Functions
   Date: 1-29-19
*/
#include <iostream>
using namespace std;
//Prototype
// int sum(int, int);
// double sum(double, double);

//Prototypes
template <class SomeType>
SomeType sum(SomeType, SomeType);

template <class T>
T addup(T, T);

template <class T, class U>
bool are_equal(T, U);

int main()
{
  cout << sum(10, 20) << '\n';
  cout << sum(1.0, 1.5) << '\n';

  int i = 5, j = 6, k;
  double f = 2.0, g = .5, h;
  k = addup<int>(i, j); //Call the function template using integers
  h = addup<double>(f, g);  //Call the function template using doubles

  cout << k << endl;
  cout << h << endl;

  //k = sum(i, j, 9);
  cout << k << endl;

  if(are_equal(10, 10.0)) {
    cout << "x and y are equal" << endl;
  }
  else {
    cout << "x and y are NOT equal" << endl;
  }

	system("pause");
	return 0;
}

template <class SomeType>
SomeType sum(SomeType a, SomeType b) {
  return a + b;
}

template <class T>
T addup(T a, T b) {
  return a + b;
}

template <class T, class U>
bool are_equal(T a, U b) {
  return (a == b);
}

// int sum(int a, int b) {
//   return a + b;
// }
//
// double sum(double a, double b) {
//   return a + b;
// }
