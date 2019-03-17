#include<iostream>
using namespace std;
class Inn
{
	int x, y;
public:
	Inn(int a, int b)
	{
		x = a;
		y = b;
	}
	inline int add()
	{
		return x + y;
	}
	inline int sub()
	{
		return x - y;
	}
	inline int mul()
	{
		return x * y;
	}
	inline int div()
	{
		return x / y;
	}
	inline int mod()
	{
		return x % y;
	}


};
int main()
{
	int num1, num2;
	cout << "enter values to perform operations" << endl;
	cin >> num1 >> num2;
	Inn i(num1, num2);
	cout << "sum :" << i.add() << endl;
	cout << "difference :" << i.sub() << endl;
	cout << "product :" << i.mul() << endl;
	cout << "quotient :" << i.div() << endl;
	cout<<"remainder :"<< i.mod() << endl;
	
	system("pause");
	return 0;
}