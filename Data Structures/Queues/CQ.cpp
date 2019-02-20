#include<iostream>
using namespace std;
struct cquu {
	int f;
	int r;
	int *cq;
	int size;
};

class cqueue
{
	struct cquu qu;
public:
	cqueue();
	void enque(int);
	int deque();
	void getsize(int);
	bool overflow();
	bool underflow();
	void display();
};
cqueue::cqueue()
{
	qu.f = -1;
	qu.r = -1;
	qu.size = 0;
	qu.cq = NULL;
}
bool cqueue::overflow()
{
	return (qu.f == ((qu.r + 1) % qu.size));
}
bool cqueue::underflow()
{
	return (qu.f == -1);
}
void cqueue::enque(int ele)
{
	//if (qu.r == qu.size - 1) { cout << "overflow" << endl; }
	if (!overflow())
	{
		if (qu.r == qu.f && qu.f == -1)
		qu.f = 0;
			qu.r = (qu.r + 1) % qu.size;
			//qu.f = (qu.f + 1) % qu.size;
			qu.cq[qu.r] = ele;	
	}
	else
	{
		cout << "queue full" << endl;
	}
}
int cqueue::deque()
{
	int temp = -999;
	//if (qu.r == -1) { cout << "underflow" << endl; }
	if (!underflow())
	{
		if (qu.r == qu.f)
		{

			temp = qu.cq[qu.f];
			qu.f = qu.r = -1;
		}
		else
		{
			temp = qu.cq[qu.f];
			qu.f = (qu.f + 1) % qu.size;

		}

	}
	else
		cout << "no elements" << endl;
	return temp;
}
void cqueue::display()
{
	int i;
	if (qu.r == -1 && qu.f == -1) { cout << "list empty" << endl; }
	else
	{
		for ( i = qu.f; i!=qu.r; i=(i+1)%(qu.size))
			cout << qu.cq[i];
			cout<<qu.cq[i];
	}
}
void cqueue::getsize(int n)
{
	qu.size = n;
	qu.cq = new int[n];
}
void main()
{
	int x, ch, n, ele;
	cqueue q1;
	cout << "enter n" << endl;
	cin >> n;
	q1.getsize(n);

	while (n != 0)
	{
		cout << "enter choice" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "enter ele to be inserted" << endl;
			cin >> ele;
			q1.enque(ele);
			break;
		case 2: x = q1.deque();
			cout << "deleted ele" << x << endl;
			break;
		case 3:q1.display();
			break;
		case 4:exit(0);
		}
	}
	system("pause");
}