#include<iostream>
using namespace std;
struct node {
	int data;
	struct node* next;
};
class stack_list {
	struct node *start;
public:
	stack_list();
	void insertfirst(int);
	int deletefirst();
	void travel_back();
	
};
stack_list::stack_list()
{
	start = NULL;
}
void stack_list::insertfirst(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	if (start != NULL)
	{
		
		temp->next = start;
		start = temp;
	}
	else
	{
		start = temp;
		temp->next = NULL;
	}
}
int stack_list::deletefirst()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		x = temp->data;
		if (start->next != NULL)
		{
			start = temp->next;
			delete temp;
		}
		else
		{
			start = NULL; delete temp;
		}
	}
	else
		cout << "list is empty" << endl;
	return x;
}
void print(struct node *temp) {
	if (temp != NULL) {
		print(temp->next);
		cout << temp->data << "->";
	}
}
void stack_list::travel_back()
{
	
	struct node *temp = start;
	print(start);
	cout << "NULL" << endl;

}

int main()
{
	stack_list sl; //we  dont allocate mem using getsize since using LLs
	int ele, n,x;
	while (1)
	{
		cout << "1.push\t2.pop\t3.display\t4.exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:cout << "enter element to be pushed\n" << endl;
			cin >> ele;
			sl.insertfirst(ele);
			break;
		case 2:x=sl.deletefirst();
			cout << "del element is " << x << endl;
			break;
		case 3:sl.travel_back();
			break;
		case 4:exit(0);
		}

	}
	system("pause");
	return 0;
}
