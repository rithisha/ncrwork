#include<iostream>
using namespace std;
struct node {
	int data;
	int coeff; int pwr;
	struct node *next;
};
class polynomial {
	struct node *start;
public:
	polynomial();
	void insert_end(int, int);
	void add_poly(polynomial &, polynomial &);
	void travel_forward();
};
polynomial::polynomial()
{
	start = NULL;
}
void polynomial::insert_end(int d, int p)
{
	struct node *temp,*curr;
	temp = new node;
	temp->next = NULL;
	temp->coeff = d;
	temp->pwr = p;
	temp->next=NULL;
	if (start != NULL)
	{ curr=start;
	while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;


	}
	else
		start = temp;

}
void polynomial::add_poly(polynomial &p1, polynomial &p2)
{
	struct node *cur1, *cur2;
	cur1 = p1.start;
	cur2 = p2.start;
	while (cur1 != NULL&&cur2 != NULL)
	{
		if (cur1->pwr > cur2->pwr)
		{
			insert_end(cur1->coeff, cur1->pwr);
			cur1 = cur1->next;
		}
		else if (cur1->pwr < cur2->pwr)
		{
			insert_end(cur2->coeff, cur2->pwr);
			cur2 = cur2->next;
		}
		else
		{
			insert_end(cur1->coeff + cur2->coeff, cur1->pwr);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
	while (cur1 != NULL)//for the remaining contents of p1 as p2 ended
	{
		insert_end(cur1->coeff, cur1->pwr);
		cur1 = cur1->next;
	}
	while (cur2 != NULL)//for the remaining contents of p2 as p1 ended
	{
		insert_end(cur2->coeff, cur2->pwr);
		cur2 = cur2->next;
	}
}
void polynomial::travel_forward()
{
	struct node *current;
	current = start;
	while(current!=NULL)
	{
		cout << current->coeff << "x^"<<current->pwr<<"+";
		current = current->next;
	}
	cout << "\n";
}
int main()
{
    polynomial p1,p2,p3;
    int c,e,p;
	while (1)
	{
		cout << "enter 1.enter 2.exit for list1\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter element and power";
			cin >> e >> p;
			p1.insert_end(e, p);
		}
		if (c == 2)
			break;
	}
	while (1)
	{
		cout << "enter 1.enter 2.exit for list2\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter element and power";
			cin >> e >> p;
			p2.insert_end(e, p);
		}
		if (c == 2)
			break;
	}
	p3.add_poly(p1, p2);
	p1.travel_forward();
    p2.travel_forward();
	p3.travel_forward();
	return 0;
}
