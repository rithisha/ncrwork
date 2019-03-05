#include<iostream>
#include<stdio.h>
using namespace std;
#include "mylib.h"
int main()
{
	int a, b;
	cout << "enter values"<<endl;
	cin >> a>>b;
	int addition = add(a, b);
	int subtraction = subtract(a, b);
	printf("result from dll : addition - %d,subtraction - %d", addition, subtraction);
	system("pause");
	return 0;
}