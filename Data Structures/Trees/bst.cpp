#include<iostream>
#include<math.h>
//#define max(a,b) (a>b)?a:b
using namespace std;
struct node
{
	struct node *left;
	struct node *right;
	int data;
};
class BST
{
	struct node *start;
public:
	BST();
    void insert_(int);
    void delete_(int);
	void inorder();
	void preorder();
	void postorder();
	int FindMax();
	int FindMin();
	int height();
	int NLN();
	int NNLN();
	friend int findmax(struct node *);
	friend int findmin(struct node *);
    friend void print_postorder(struct node*);
    friend void print_preorder(struct node *);
    friend void print_inorder(struct node *);
	friend int find_height(struct node *);
	friend int no_leafs(struct node*);
	friend int no_nonleafs(struct node*);
	friend struct node* insert_ele(int,node*);
	friend struct node* delete_ele(int,node*);

};
BST::BST()
{
	start = NULL;
}
int no_leafs(struct node *curr)
{
	if (curr == NULL)
		return 0;
	else if (curr->left == NULL&&curr->right == NULL)
		return 1;
	else
        return(no_leafs(curr->left) + no_leafs(curr->right));
}
int BST::NLN()
{
    return no_leafs(start);
}

int no_nonleafs(struct node *curr)
{
	if (curr == NULL)
		return 0;
	else if (curr->left == NULL&&curr->right == NULL)
		return 0;
	else
        return(no_nonleafs(curr->left) + no_nonleafs(curr->right)+1);
}
int BST::NNLN()
{
    return no_nonleafs(start);
}
int find_height(struct node *curr)
{
    if (curr == NULL)
		return -1;
	else
		return(max(find_height(curr->left), find_height(curr->right)) + 1);
}


int BST::height()
{
	return find_height(start);
}
void print_inorder(struct node *curr)
{
	if (curr != NULL)
	{
		print_inorder(curr->left);
		cout << curr->data;
		print_inorder(curr->right);
	}

}
void BST::inorder()
{
	if (start != NULL)
	{
		print_inorder(start);
	}
}
void print_preorder(struct node *curr)
{
	if (curr != NULL)
	{
		cout << curr->data;
		print_preorder(curr->left);
		print_preorder(curr->right);
	}

}
void BST::preorder()
{
	if (start != NULL)
	{
		print_preorder(start);
	}
}
void print_postorder(struct node *curr)
{
	if (curr != NULL)
	{
		print_postorder(curr->left);
		print_postorder(curr->right);
		cout << curr->data;
	}

}
void BST::postorder()
{
	if (start != NULL)
	{
		print_postorder(start);
	}
}
int findmax(struct node *curr)
{

    if(curr!=NULL)
    {
        while(curr->right!=NULL)
            curr=curr->right;
        return(curr->data);
    }
}
int findmin(struct node *curr)
{

    if(curr!=NULL)
    {
        while(curr->left!=NULL)
            curr=curr->left;
        return(curr->data);
    }
}
int BST::FindMax()
{
	if (start != NULL)
	{
		struct node *curr = start;
		while (curr->right != NULL)
			curr = curr->right;
		return curr->data;
	}
	return -1;

}
int BST::FindMin()
{
	if (start != NULL)
	{
		struct node *curr = start;
		while (curr->left != NULL)
			curr = curr->left;
		return curr->data;
	}
	return -1;
}
struct node* insert_ele(int ele,struct node* curr)
{
    if (curr == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->right = NULL;
		temp->left = NULL;
		return temp;
	}
	else
	{
		if (ele < curr->data)
			curr->left = insert_ele(ele, curr->left);
		else
			curr->right = insert_ele(ele, curr->right);
		return curr;
	}
}
void BST::insert_(int ele)
{
  start=insert_ele(ele,start);
}

struct node* delete_ele(int ele, struct node* curr)
{
	if (curr != NULL)
	{
		if (ele > curr->data)
			curr->right = delete_ele(ele, curr->right);
		else
		{
			if (ele < curr->data)
				curr->left = delete_ele(ele, curr->left);
			else
			{
				if (curr->left != NULL&&curr->right != NULL)
				{
					curr->data = findmax(curr->left);
					curr->left = delete_ele(curr->data, curr->left);
				}
				else
				{
					struct node *temp;
					temp = curr;
					if (curr->left != NULL)
						curr = curr->right;
					else
						curr = curr->left;
					delete temp;
				}
			}
		}
	}
				return curr;
}
void BST::delete_(int ele)
{
    start=delete_ele(ele,start);
}
int main()
{
	BST b;
	//struct node *root = NULL;
	int ch, ele;
	cout<<"1.insert\t2.delete\t3.inorder\t4.preorder\t5.postorder\t6.height\t7.max\t8.min\t9.leafs\t10.non-leafs\t11.exit"<<endl;
	while (1)
	{
		cout << "enter choice" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "enter element to be inserted" << endl;
			cin >> ele;
		    b.insert_(ele);
		    break;
		case 2:cout << "enter element to be deleted" << endl;
		     cin>>ele;
		      b.delete_(ele);
		      break;
       case 3:b.inorder(); cout << "\n";
			break;
		case 4:b.preorder(); cout << "\n";
			break;
		case 5:b.postorder(); cout << "\n";
			break;
        case 6:cout << "Height of bst : " << b.height() << "\n";
			break;
		case 7:cout << "Maximum ele in tree : " << b.FindMax() << "\n";
			break;
		case 8:cout << "Minimum ele in tree : " << b.FindMin() << "\n";
			break;
		case 9:cout << "No of leafs : " << b.NLN() << endl;
			break;
		case 10:cout << "No of non leaf nodes : " << b.NNLN() << endl;
			break;
		}
		if (ch == 11)
			break;

    }
}
