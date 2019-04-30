
#include<iostream>

using namespace std;

struct TreeNode
{
	char data;
	struct TreeNode *left,*right;
}*root;

class StackNode
{
    public:
        TreeNode *tNode;
        StackNode *next;

        StackNode(TreeNode *tNode)
        {
            this->tNode = tNode;
            next = NULL;
        }
};

class ExpressionTree
{
    private:
        StackNode *top;
    public:
        ExpressionTree()
        {
            top = NULL;
        }


	void buildTree(string);
	void insert(char);

        void push(TreeNode *);
	TreeNode* pop();

	void display();
	void inorder(TreeNode *);
	void inorder_nonR(TreeNode *);
	void preorder(TreeNode *);
	void preorder_nonR(TreeNode *);
	void postorder(TreeNode *);
};


void ExpressionTree :: buildTree(string eqn)
{
	for ( int i = eqn.length() - 1; i >= 0; i--)
	{
                insert(eqn[i]);
	}

	root = top->tNode;
}//buildTree


void ExpressionTree :: insert(char ch)
{
	TreeNode *temp = new TreeNode;
	temp->left = temp->right = NULL;
	temp->data = ch;

	if ( ch >='0' && ch <='9')
		push(temp);
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
		temp->left = pop();
		temp->right = pop();
		push(temp);
	}
	else { cout<<"Invalid Expression"<<endl; return;}

}

void ExpressionTree :: push(TreeNode *ptr)
{
	if (top == NULL)
		top = new StackNode(ptr);
	else
	{
		StackNode *nptr = new StackNode(ptr);
		nptr->next = top;
		top = nptr;
	}
}

TreeNode* ExpressionTree :: pop()
{
	if (top == NULL) { cout<<"Stack empty"<<endl; return 0; }
	else {
		TreeNode *ptr = top->tNode;
		top = top->next;
		return ptr;
	}
}

void ExpressionTree::display()
{
	cout<<"\n Inorder : \t\t";
	inorder(root);
	cout<<"\n Inorder Nonrecursive : ";
	inorder_nonR(root);
	cout<<"\n Preorder : \t\t";
	preorder(root);
	cout<<"\n Preorder Nonrecursive : ";
	preorder_nonR(root);
	cout<<"\n Postorder : \t\t";
	postorder(root);
	cout<<"\n";
}

void ExpressionTree :: inorder(TreeNode *ptr)
{
            if (ptr != NULL)
            {
                inorder(ptr->left);
                cout<<"  "<<ptr->data;
                inorder(ptr->right);
            }
}


void ExpressionTree ::preorder(TreeNode *ptr)
{
            if (ptr != NULL){
		cout<<"  "<<ptr->data;
                preorder(ptr->left);
                preorder(ptr->right);
            }
}

void ExpressionTree ::postorder(TreeNode *ptr)
{
            if (ptr != NULL){
                postorder(ptr->left);
                postorder(ptr->right);
		cout<<"  "<<ptr->data;
            }
}

void ExpressionTree :: inorder_nonR(TreeNode *temp){
	top=NULL;
	while(temp!=NULL || top!=NULL)
	{
		while(temp!=NULL) { push(temp); temp=temp->left; }
		temp = pop();
		cout<<"  "<<temp->data;
		temp=temp->right;
	}
}


void ExpressionTree :: preorder_nonR(TreeNode *temp){
	top=NULL;
	while(temp!=NULL || top!=NULL)
	{
		while(temp!=NULL)
		{
			cout<<"  "<<temp->data;
			push(temp);
			temp=temp->left;
		}
		temp = pop();
		temp=temp->right;
	}
}





int main()
{
	string s;
	cout<<"Expression Tree Test"<<endl;
	ExpressionTree et;
	cout<<"\nEnter equation in Prefix form: ";
	cin>>s;
	et.buildTree(s);
	cout <<"Traversals:\n";
	et.display();
	return 0;
}






