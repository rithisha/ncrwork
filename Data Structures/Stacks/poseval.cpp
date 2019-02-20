#include<iostream>
using namespace std;
struct stack1
{
	int top;
	int *s;
	int size;
};
class stackk
{
public:
	struct stack1 sta;
	stackk();
	void push(int);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void display();
	void getsize(int);
	int checkprec(char);

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
	sta.s = new int[n];
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
		sta.s[++sta.top] = ele;//sta.sta[top
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
void main()
{
	stackk st;
	int a, b,n;
	char str[100],ch;
	cout << "enter size" << endl;
	cin >> n;
	st.getsize(n);
	cout << "enter string" << endl;
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++)
	{
		ch = str[i];
		switch (ch)
		{
		
		case '+':a = st.pop() ;
			b = st.pop() ;
			st.push(a + b);
			break; 
		case '-':a = st.pop() ;
			b = st.pop() ;
			st.push(b - a);
			break;
		case '*':a = st.pop() ;
			b = st.pop() ;
			st.push(a * b);
			break;
		case '/':a = st.pop();
			b = st.pop() ;
			st.push(b / a);
			break;
		/*case '[':
		case '{':
		case '(':
		case '}':
		case ']':
		case ')':continue;*/
		default:st.push(ch-'0');
			break;
		}
	}
	cout << st.peek();
	system("pause");
}