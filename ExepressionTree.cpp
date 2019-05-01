#include<iostream>
#include<stack>
using namespace std;
#include<string.h>

struct node {

	char data;
	node *left;
	node *right;

};

class exp_tree {

public :

	bool isOperator(char c) {
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			return true;
		else
			return false;

	}
	node* new_node(char data) {
		node *temp = new node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	node* construct_tree(char postfix[]) {

		stack<node *> s;
		node *temp, *temp1, *temp2;

		for (int i = 0; i < strlen(postfix); i++) {

			if (!isOperator(postfix[i])) {

				temp = new_node(postfix[i]);
				s.push(temp);

			}
			else {

				temp = new_node(postfix[i]);
				temp1 = s.top();
				s.pop();
				temp2 = s.top();
				s.pop();
				temp->right = temp1;
				temp->left = temp2;
				s.push(temp);

			}

		}
		temp = s.top();
		s.pop();

		return temp;
	}

	void inorder(node *root) {

		stack<node *> S;
		node *curr = root;

		while (curr != NULL || S.empty() == false) {

			while (curr != NULL) {
				S.push(curr);
				curr = curr->left;
			}
			curr = S.top();
			S.pop();

			cout << " " << curr->data;

			curr = curr->right;

		}

	}
	void preorder(node *root) {

		stack<node *> S;
		S.push(root);

		while (S.empty() == false) {

			node *temp = S.top();
			S.pop();
			cout << " " << temp->data;
			if (temp->right != NULL)
				S.push(temp->right);
			if (temp->left != NULL)
				S.push(temp->left);


		}

	}
};

int main() {

	char postfix[20];
	cout << "Enter the postfix Expression : ";
	cin >> postfix;

	exp_tree object;
	node *root=object.construct_tree(postfix);
	object.inorder(root);
	object.preorder(root);
	cout << endl;
	system("pause");


}

