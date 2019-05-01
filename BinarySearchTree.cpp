#include<iostream>
#include<queue>
using namespace std;


struct node{
	int data;
	node *left;
	node *right;
};


class treee {

protected :
	node *root;

public :

	node* create(int value) {

		node *temp = new node;
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	node* insert(node *root,int value) {
		char ch;
		if (root == NULL)
			return create(value);
		else {
			if ((root->data)>value) {
				root->left = insert(root->left, value);
			}
			if ((root->data) < value) {
				root->right = insert(root->right, value);	
			}
		}
		return root;
	}
	void preorder(node *root) {

		if (root == NULL)
			return;
		cout <<"-> "<< root->data;
		preorder(root->left);
		preorder(root->right);

	}
	void inorder(node *root) {

		if (root == NULL)
			return;
		inorder(root->left);
		cout << " -> " << root->data;
		inorder(root->right);

	}
	void postorder(node *root) {

		if (root == NULL)
			return;

		postorder(root->left);
		postorder(root->right);
		cout <<" -> "<< root->data;

	}
	void level_wise(node *root) {

		if (root == NULL)
			return;
		//Queue obj;
		queue<node *> q;
		int ht,nC;
		ht = 0;
		nC = 0;
		q.push(root);

		while (1) {
			int nC = q.size();
			if (nC == 0)
				return;
			ht = ht + 1;

			while (nC > 0) {

				node *temp = new node;
				temp = q.front();
				q.pop();
				cout << temp->data;
				if (temp->left != NULL)
					q.push(temp->left);
				if (temp->right != NULL)
					q.push(temp->right);
				nC--;
				cout << "\t";

			}
			cout << "\n";

		}
	}
	void leaf(node *root) {

		if (root == NULL)
			return;
		leaf(root->left);
		if (root->left == NULL && root->right == NULL)
			cout << " -> " << root->data;
		leaf(root->right);

	}
	node* search(node *root,int key) {

		if (root==NULL ||root->data == key)
			return root;
		if (key < (root->data))
			return search(root->left, key);
		if (key > (root->data))
			return search(root->right, key);


	}






};

int main()
{
	int choice,total,val;
	treee object;
	node *root1=NULL;

	do {

		cout <<"\n \n \n 1. Create a tree \n 2. Display tree traversals \n 3. Level Wise Display \n 4. Search \n 5. Delete \n 0. Exit \n \t : ";
		cin >> choice;

		switch (choice) {

		case 1: cout << "\n Enter total nodes : ";
				cin >> total;
				cout << "\n Enter root node : ";
				cin >> val;
				root1 = object.insert(root1, val);

				int i;
				for (i = 0; i < total - 1; i++) {

					cout << "\n Enter value of New  node : ";
					cin >> val;
					root1 = object.insert(root1, val);

				}



			break;

		case 2:	cout << "\n The Preoder traversal of the given tree is : \n \t Start ";
				object.preorder(root1);
				cout << "->END";
				cout << "\n The Inorder traversal of the given tree is : \n \t Start ";
				object.inorder(root1);
				cout << "->END";
				cout << "\n The Postorder traversal of the given tree is : \n \t Start  ";
				object.postorder(root1);
				cout << "->END";

				
			break;

		case 3: cout << "\n The levelwise displayis as follows : " << endl;
				object.level_wise(root1);


			break;


		case 4:   int key;
				  node *temp;
				  cout << "\n Enter the key to be searched : ";
				  cin >> key;
				  temp = object.search(root1, key);
				  if (temp == NULL)
					  cout << "\n NOT FOUND";
				  else
					  cout << "\n FOUND";
				 break;



		}
	} while (choice != 0);


	return 0;
}

