#include<stdio.h>
#include<iostream>
using namespace std;
#define SIZE 150
template<class T>//we use templates to make programs generic(applicable to any data types)
class Stack
{
	int top;
	T stack_obj[SIZE];
public:
	Stack()
	{
		top = -1;
	}
	void push(T ele)
	{
		if (top == (SIZE - 1))
		{
			cout << "Overflow";
			return;
		}
		stack_obj[++top] = ele;
	}
	T pop()
	{
		if (top == -1)
		{
			cout << "Underflow";
			return -1;
		}
		else
			return stack_obj[top--];
	}
	T peek()
	{
		if (top == -1)
		{
			cout << "Underflow";
			return -1;
		}
		else
			return stack_obj[top];
	}
	void display()
	{
		int i;
		for (i = 0; i <= top; i++)
			cout << stack_obj[i] << " ";
		cout << "\n";
	}
};
int main()
{
	char element_char;
	int element, size,size_c;
	Stack<int> s;//can be used as an integer stack
	cout << "Integer stack\n";
	cout << "enter size of integer stack\n";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "enter element to be pushed onto integer stack" << endl;
		cin >> element;
		s.push(element);
	}
	s.display();
	cout <<"peek result"<< s.peek() << endl;
	cout <<"element popped"<< s.pop() << endl;
	cout << "Character stack\n";
	Stack<char> s1;//can also be used as char stack because of templates
	cout << "enter size of character stack\n";
	cin >> size_c;
	for (int i = 0; i < size_c; i++)
	{
		cout << "enter element to be pushed onto integer stack" << endl;
		cin >> element_char;
		s1.push(element_char);
	}
	s1.display();
	cout << s1.peek() << endl;
	cout << s1.pop() << endl;
	system("pause");
	return 0;
}