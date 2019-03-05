#include<iostream>
using namespace std;
#include "C:\Users\Rithisha\Desktop\ncr training\ncrwork\Windows_internals\Windows\Project23_static\mystatic.h"
int main()
{
	double a, b;
	cout << "enter values" << endl;
	cin >> a >> b;
	cout << "sum is" << functions_math::add(a, b) << endl;
	cout << "difference is" << functions_math::subtraction(a, b) << endl;
	cout << "product is" << functions_math::multiply(a, b) << endl;
	cout << "quotient is" << functions_math::divide(a, b) << endl;
}