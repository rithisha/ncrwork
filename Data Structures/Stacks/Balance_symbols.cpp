#include<iostream>
using namespace std;
struct stack1
{
	int top;
	char *s;
	int size;
};
class stackk
{
	struct stack1 sta;
public:
	stackk();
	void push(int);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void display();
	void getsize(int);

};
stackk::stackk()
{
	sta.top = -1;
	sta.size = 0;
	sta.s = NULL;
}
void stackk::getsize(int n)
{
	sta.size = n;
	sta.s = new char[n];
}
bool stackk::isFull()
{
	return (sta.top == sta.size - 1);
}
bool stackk::isEmpty()
{
	return (sta.top == -1);
}
void stackk::push(int ele)
{
	if (!isFull())
	{
		sta.s[++sta.top] = ele;
	}
	else
	{
		cout << "stack is full" << endl;
	}
}
int stackk::pop()
{
	int x = -999;
	if (!isEmpty())
	{
		x = sta.s[sta.top--];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;
}
int stackk::peek()
{

	int x = -999;
	if (!isEmpty())
	{
		x = sta.s[sta.top];
	}
	else
	{
		cout << "stack is empty" << endl;
	}
	return x;

}
void stackk::display()
{
	for (int i = 0; i <= sta.top; i++)
	{
		cout << sta.s[i] << endl;
	}
}
void main()
{
	int n, ch, ele, x,i,flag=0;
	stackk st;

	char str[50];
	cout << "enter n" << endl;
	cin >> n;
	st.getsize(n);
	cout << "enter string" << endl;
	cin >> str;

	for (i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
		case '(':
		case '{':
		case '[':st.push(str[i]);
			break;
		case ')':
		case ' ]':
		case '}':
			if ((str[i] == ')'&&st.peek() == '(') || (str[i] == ']'&&st.peek() == '[') || (str[i] == '}'&&st.peek() == '{'))
			{
				x = st.pop();
				//cout << "deleted" << x << endl;
			}
			else
			{
				flag = 1;
				break;
			}
			break;
		default:continue;
		}
	}
	//if (str[i] == '\0'&&st.isEmpty())
	if(flag==0)
	  {
		cout << "balanced" << endl;
	}
	else
		cout << "unbalanced"<<endl;

	//getchar();
	system("pause");
}
