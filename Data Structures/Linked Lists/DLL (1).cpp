#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class __DLL__
{
	struct node *start;
public:
	__DLL__();
	void insertfirst(int);
	void insertlast(int);
	void insertafter(int, int);
	void insertbefore(int, int);
	int deletefirst();
	int deletelast();
	void deletespec(int);
	void travforw();
	void travback();
};
__DLL__::__DLL__()
{
	start = NULL;
}
void __DLL__::insertfirst(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->prev = NULL;
	temp->next = start;
	if (start != NULL)
	{
		start->prev = temp;
	}
	start = temp;
}
void __DLL__::insertlast(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		temp->prev = curr;
		curr->next = temp;
	}
}
void __DLL__::insertafter(int sele, int ele)
{
	struct node *temp;
	struct node *curr;
	curr = start;
	if (start != NULL)
	{
		while (curr->next != NULL&&curr->data != sele)
		{
			curr = curr->next;
		}
		if (curr->next != NULL)
		{
			temp = new node;
			temp->data = ele;
			temp->prev = curr;
			temp->next = curr->next;
			if (curr->next != NULL)
			curr->next->prev = temp;
				curr->next = temp;
		}
		else
		{
			cout << "sele not found" << endl;
		}
	}
	else
	{
		cout << "list is empty" << endl;
	}
}

void __DLL__::insertbefore(int sele, int ele)
{
	struct node *temp;
	struct node *curr;
	curr = start;
	if (start != NULL)
	{
		while (curr != NULL&&curr->data != sele)
		{
			curr = curr->next;
		}
		if (curr != NULL)
		{
			temp = new node;
			temp->data = ele;
			temp->prev = curr->prev;
			temp->next = curr;
			if ((curr->prev) != NULL)
				curr->prev->next = temp;

			else
				start = temp;
			curr->prev = temp;
		}
		else
		{
			cout << "sele not found" << endl;
		}
	}
	else
	{
		cout << "list is empty" << endl;
	}
}
int __DLL__::deletefirst()
{
	int x = -1;
	struct node *temp;
	if (start != NULL)
	{
		temp = start;
		if (temp->next != NULL)
		{
			temp->next->prev = NULL;
		}
		x = temp->data;
		start = temp->next;
		delete temp;

	}
	else { cout << "list empty" << endl; }
	return x;

}
int __DLL__::deletelast()
{
	int x = -1;
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = NULL;
		else
			start = NULL;
		delete curr;
	}
	else
		cout << "list empty" << endl;
	return x;
}
void __DLL__::deletespec(int ele)
{
	if (start != NULL)
	{
		struct node *curr, *temp;
		curr = start;
		while (curr != NULL&&curr->data != ele)
			curr = curr->next;
		if (curr != NULL)
		{
			if (curr->prev != NULL)
				curr->prev->next = curr->next;
			else
				start = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			delete curr;
		}
		else
			cout << "ele not found" << endl;
	}
	else
		cout << "list empty" << endl;

}
void __DLL__::travforw()
{
	struct node *curr;
	curr = start;
	while (curr!= NULL)
	{
		cout << curr->data;
		curr = curr->next;
	}
}
void __DLL__::travback()
{
	struct node *curr;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		while (curr != NULL)
		{
			cout << curr->data;
			curr = curr->prev;
		}
	}
}
int main()
{
	int n, ele, sele;
	__DLL__ l;
	while (1)
	{
		cout << "1.Insert_first\t2.Insert_last\t3.Insert_after\t4.Insert_before\t5.Delete_first\t6.Delete_last\t7.delete_spec\t8.travel_forward\t9.Travel_backward\t10.exit\n";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "enter element to insert: ";
			cin >> ele;
			l.insertfirst(ele);
			break;
		case 2:
			cout << "enter element to insert: ";
			cin >> ele;
			l.insertlast(ele);
			break;
		case 3:
			cout << "enter element to search & insert : ";
			cin >> sele >> ele;
			l.insertafter(sele, ele);
			break;
		case 4:
			cout << "enter element to search & insert : ";
			cin >> sele >> ele;
			l.insertbefore(sele, ele);
			break;
		case 5:
			ele = l.deletefirst();
			if (ele == -1)
				cout << "List is empty\n";
			else
				cout << "Deleted : " << ele << endl;
			break;
		case 6:
			ele = l.deletelast();
			if (ele == -1)
				cout << "List is empty\n";
			else
				cout << "Deleted : " << ele << endl;
			break;
		case 7:
			cout << "enter element to delete: ";
			cin >> ele;
			l.deletespec(ele);
			break;
		case 8:
			l.travforw();
			break;
		case 9:
			l.travback();
			break;
			/*case 10:
			l.Reverse();
			break;*/
		case 10:return 0;
		}
	}

	return 0;
}




