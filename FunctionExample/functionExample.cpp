/*Programmer: Matthew Moore
   Description: Function Examples
   Date: 1-23-19
*/
#include <iostream>
using namespace std;
//Prototype
int max(int a, int b);
void max2(int &a, int b);

int main(int argc, char const *argv[]) {
  int num1, num2;

  cout << "Enter number 1: " << endl;
  cin >> num1;

  cout << "Enter number 2: " << endl;
  cin >> num2;

  num1 = max(num1, num2);

  cout << endl << "The largest number is: " << num1 << endl;

  max2(num1, num2);

  cout << endl << "Max2 the largest number is: " << num1 << endl << endl;

  system("pause");
  return 0;
}

int max(int a, int b) { //Header
  //Body
  return (a > b) ? a : b;
}

void max2(int &a, int b) {
  a = (a > b) ? a : b;
}
