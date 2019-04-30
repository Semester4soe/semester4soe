
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *L, *R;
}*root,*p,*q;


class BSTree
{
	public:
		BSTree()
		{
			root = NULL;
		}

		void create( int data );
		void insert(node * );
		void inorder( node * );
		void display();
};

void BSTree :: inorder(node * t)
{
	if( t != NULL )
	{
		inorder( t->L );
		cout << t->data << "  " ;
		inorder( t->R );
	}
}

void BSTree :: create( int data )
{
	node *t,*r;
	t = new node;
	t->data = data;
	t->L = t->R = NULL;

	if ( root == NULL )
	{
		root = t;
	}
	else
	{
		r=root;
		while(1)
		{
			if( t->data < r->data )
			{
				if(r->L==0)
				{
					r->L = t;
					break;
				}
				else
					r=r->L;
			}
			else if( t->data > r->data )
			{
				if(r->R==0)
				{
					r->R = t;
					break;
				}
				else
					r=r->R;
				}
		}
	}
}


void BSTree :: insert(node *temp )
{
		p = root;
		q = NULL;
		while( p!= NULL )
		{
			q = p;
			if( temp->data < p->data )
				p = p->L;
			else
				p = p->R;
		}
		if( temp->data < q->data )
			q->L = temp;
		else
			q->R = temp;

}


void BSTree :: display()
{
	node *temp;
	temp = root;
	inorder( temp );
}


int  main()
{
	int data;
	BSTree bt;
	int n;
	cout << "How many nodes you want in a tree?";
	cin >> n;
	for(int i = 0;i < n; i++ )
	{
		cout << "\n Enter node :: ";
		cin >> data;
		bt.create(data);
	}

	bt.inorder(root);
	cout << "\n";
}

