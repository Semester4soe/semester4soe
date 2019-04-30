
#include <iostream>
#include<string.h>
using namespace std;

struct node{
	char k[20];
	char m[20];
	node *lc, *rc;
}*root;

class DictionaryBST{
	public:
		DictionaryBST()
		{
			root=0;
		}
		void create();
		int search(char *);
		void display(node*);
		void display_rev(node*);
		int update(char *);
		void del(char *);
		node * del(node *,char *);
		node *min(node*);
};

int main()
{
	char a;
	int ch;
	char x[20];
	DictionaryBST d;

	do
	{
		cout<<"\nMenu\n1.Create\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Add new node\nEnter your choice::";
		cin>>ch;
		switch(ch)
		{
			case 1:d.create();
			break;

			case 6:
			cout << "Add new item to BST:";
			d.create();
			break;

			case 2:
			cout<<"Dictionary Contents: ";
			cout<<"\n Ascending order :";
			d.display(root);
			cout<<"\n Descending order :";
			d.display_rev(root);
			break;

			case 3:
			cout<<"\nEnter Keyword which u want to search:";
			cin>>x;

			if( d.search(x) == 1)
				cout<<"\nKeyword Found";
			else
				cout<<"\nKeyword Not Found";
			break;

			case 4:
			cout<<"\nEnter Keyword which meaning  want to update:";
			cin>>x;

			if(d.update(x) == 1)
				cout<<"\nMeaning Updated";
			else
				cout<<"\nMeaning Not Found";
			break;

			case 5:
			cout<<"\nEnter Keyword which meaning  want to delete:";
			cin>>x;
			root = d.del(root,x);
			cout<<"\n Updated DictionaryBSTtionary ::\n";
			d.display(root);
		}
		cout<<"\n Display Main menu (y/n)??";
		cin>>a;
	} while(a=='y');
	return 0;
}


void DictionaryBST :: display(node *n)
{
    if(n!=0)
    {
        display(n->lc);
        cout<<"\n Key Word :"<<n->k;
        cout<<"\t Meaning :"<<n->m;
        display(n->rc);
    }
}

void DictionaryBST :: display_rev(node *n)
{
    if(n!=0)
    {
        display_rev(n->rc);
        cout<<"\n Key Word :"<<n->k;
        cout<<"\t Meaning :"<<n->m;
        display_rev(n->lc);
    }
}


void DictionaryBST :: create()
{
	node *temp=0, *r=0;
	char ch='y';
	while(ch=='y')
	{
		temp = new node();

		cout<<"\nEnter Keyword: ";
		cin>>temp->k;
		cout<<"\nEnter Meaning: ";
		cin>>temp->m;
		temp->lc = temp->rc = 0;


		if(root == 0)
			root = temp;
		else{
			r=root;
			while(1)
			{
				if(strcmp(temp->k,r->k)<0)
				{
					if(r->lc==0)
					{
						r->lc = temp;
						break;
					}
					else
						r=r->lc;
				}

				else if(strcmp(temp->k,r->k)>0)
				{
					if( r->rc == 0 ){
						r->rc = temp;
						break;
					}
					else
						r = r->rc;
				}
			}
		}

		cout<<"Want to add more items(y/n)";
		cin>>ch;
    }
}

int DictionaryBST::search(char *temp)
{
	node *r;
	r=root;
	int c=0;
	while(r != 0)
	{
		c++;
		if(strcmp (temp,r->k) == 0)
		{
			cout<<"\n No of Comparisons:"<<c;
			return 1;
		}
		else if(strcmp (temp, r->k) < 0)
			r = r->lc;
		else if (strcmp (temp, r->k) > 0)
			r = r->rc;
	}
	return -1;
}


int DictionaryBST :: update(char *temp)
{
	node *r;
	r = root;

	while(r != 0)
	{
		if(strcmp (temp,r->k) == 0)
		{
			cout<<"\nEnter New Meaning of Keyword "<< r->k;
			cout <<" : ";
			cin>>r->m;
			return 1;
		}
		if(strcmp (temp, r->k) < 0)
			r = r->lc;
		if(strcmp (temp, r->k) > 0)
			r = r->rc;
	}
	return -1;
}

node* DictionaryBST :: del(node * r,char temp[20])
{
	node *t;

	if(r == 0)
	{
		cout<<"\nElement Not Found";
		return r;
	}

	if (strcmp(temp,r->k) < 0)
	{
		r->lc = del(r->lc, temp);
		return r;
	}
	if (strcmp(temp,r->k) > 0)
	{
		r->rc = del(r->rc, temp);
		return r;
	}


	if (r->lc==0 && r->rc==0)
	{
		t = r;
		delete t;
		return 0;
	}

	if(r->rc==0)
	{
		t = r;
		r = r->lc;
		delete t;
		return r;
	}
	else if(r->lc==0)
	{
		t = r;
		r = r->rc;
		delete t;
		return r;
	}


	t = min(r->rc);
	strcpy(r->k,t->k);
	r->rc = del(r->rc, t->k);
	return r;
}

node * DictionaryBST :: min(node *q)
{
	while(q->lc != 0)
	{
		q = q->lc;
	}
	return q;
}
