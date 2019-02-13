#include<iostream>
using namespace std;
class Inn
{
	int x, y;
public:
	Inn(int a,int b)
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
void main()
{
	Inn i(2, 3);
	cout << i.add() << endl << i.sub() << endl << i.mul() << endl << i.div() << endl << i.mod() << endl;
	getchar();
}