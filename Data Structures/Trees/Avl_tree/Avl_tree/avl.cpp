#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
class avl
{
	struct node *start;
public:
	avl();
	void insert(int);
	int height();
	void balance();
	void Left();
	void Right();
	void leftRight();
	void Rightleft();
	void inorder();
	int B();
	friend int B1(struct node*);
	friend struct node* LR_rotate(struct node*);
	friend struct node* RL_rotate(struct node*);
	friend struct node* L_rotate(struct node*);
	friend struct node* R_rotate(struct node*);
	friend struct node*  balance1(struct node*);
	friend struct node* ins(struct node*, int);
	friend int height1(struct node*);
	friend void inord(struct node*);
};
avl::avl()
{
	start = NULL;
}
void inord(struct node *curr)
{
	if (curr != NULL)
	{

		inord(curr->left);
		cout << curr->data << " ";
		inord(curr->right);
	}
}
void avl::inorder()
{
	inord(start);
}




struct node* L_rotate(struct node* curr)
{
	struct node *temp;
	temp = curr->right;
	curr->right = temp->left;
	temp->left = curr;
	return temp;
}
void avl::Left()
{
	start = L_rotate(start);
}
struct node* R_rotate(struct node* curr)
{
	struct node *temp;
	temp = curr->left;
	curr->left = temp->right;
	temp->right = curr;
	return temp;
}
void avl::Right()
{
	start = R_rotate(start);
}
struct node* LR_rotate(struct node* curr)
{
	struct node *temp;
	temp = curr->left;
	curr->left = L_rotate(temp);
	return R_rotate(curr);
}
void avl::leftRight()
{
	start = LR_rotate(start);
}
struct node* RL_rotate(struct node* curr)
{
	struct node *temp;
	temp = curr->right;
	curr->right = R_rotate(temp);
	return L_rotate(curr);
}
void avl::Rightleft()
{
	start = RL_rotate(start);
}
int height1(struct node* curr)
{
	if (curr == NULL)
		return -1;
	else if (curr->right == NULL && curr->left == NULL)
		return 0;
	else
		return(max(height1(curr->left), height1(curr->right)) + 1);
}
int B1(struct node *curr)
{
	return(height1(curr->left) - height1(curr->right));
}
struct node* balance1(struct node* curr)
{
	if (B1(curr) > 1)
	{
		if (B1(curr->left) == 1)
			curr = R_rotate(curr);
		else
			curr = LR_rotate(curr);
	}
	else if (B1(curr) < -1)
	{
		if (B1(curr->right) == 1)
			curr = RL_rotate(curr);
		else
			curr = L_rotate(curr);
	}

	return curr;
}
void avl::balance()
{
	start = balance1(start);
}
struct node* ins(struct node *curr, int ele)
{
	if (curr == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		if (ele > curr->data)
		{
			curr->right = ins(curr->right, ele);
		}
		else
		{
			curr->left = ins(curr->left, ele);
		}
		curr = balance1(curr);
		return curr;
	}
}
void avl::insert(int ele)
{
	start = ins(start, ele);
}

int avl::height()
{
	return height1(start);
}

void main()
{
	int ch, ele;
	avl a;
	while (1)
	{
		cout << "enter choice 1.insert element\t2.inorder display\t3.exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "enter element" << endl;
			cin >> ele;
			a.insert(ele); break;
		case 2:
			a.inorder();
			break;
		case 3:exit(0);
		}
	}
}