#include<iostream>
using namespace std;
struct node {
	int data;
	struct node* next;
};
class q_list {
	struct node *start;
public:
	q_list();
	void insertlast(int);
	int deletefirst();
	void travel_forw();

};
q_list::q_list()
{
	start = NULL;
}
void q_list::insertlast(int ele)
{
	struct node *temp,*curr;
	curr = start;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start != NULL)
	{
		while (curr->next != NULL)
			curr = curr->next;

		curr->next = temp;
		
	}
	else
	{
		start = temp;
		temp->next = NULL;
	}
}
int q_list::deletefirst()
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

void q_list::travel_forw()
{
	struct node *curr;
	curr = start;
	while (curr->next!= NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
	cout << curr->data;
	
}

int main()
{
	q_list ql; //we  dont allocate mem using getsize since using LLs
	int ele, n, x;
	while (1)
	{
		cout << "1.enque\t2.deque\t3.display\t4.exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:cout << "enter element to be enqueued\n" << endl;
			cin >> ele;
			ql.insertlast(ele);
			break;
		case 2:x = ql.deletefirst();
			cout << "del element is " << x << endl;
			break;
		case 3:ql.travel_forw();
			break;
		case 4:exit(0);
		}

	}
	system("pause");
	return 0;
}
