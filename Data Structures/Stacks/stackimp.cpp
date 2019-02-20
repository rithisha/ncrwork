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
  //~stackk();

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
	int x=-999;
	if (!isEmpty())
	{
		x=sta.s[sta.top--];
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
void stackk :: display()
{
	for (int i = 0; i <= sta.top; i++)
	{
		cout << sta.s[i] << endl;
     }
}
void main()
{
	int n,ch,ele,x;
	stackk st;
	cout << "enter size" << endl;
	cin >> n;
	st.getsize(n);
	
	while (1)
	{
		cout << "enter your choice" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "enter element to be pushed" << endl;
			cin >> ele;
			st.push(ele);
			break;
		case 2:x = st.pop();
			cout << "deleted element is:" << x << endl;
			break;
		case 3:x = st.peek();
			cout << "top element is :" << x << endl;
			break;
		case 4:st.display();
			break;
		case 5:exit(0);
		}
	}
	getchar();
}