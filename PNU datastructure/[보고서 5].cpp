/* CPP program to convert a Binary tree to BST using sets as containers. */
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

Node* newNode(int data) { // helper function to create a node
	Node* temp = new Node(); 	// dynamically allocating memory
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


void leaf(Node* root) { // function to print leaf node
	if (!(root->left) && !(root->right)) {
		cout << root->data << " ";
		return;
	}
	leaf(root->left);
	leaf(root->right);

}

int main() {
	Node* root = newNode(5);
	root->left = newNode(7);
	root->right = newNode(9);
	root->right->left = newNode(10);
	root->left->left = newNode(1);
	root->left->right = newNode(6);
	root->right->right = newNode(11);

	/* Constructing tree given in the above figure
		5
		/ \
		7	 9
	/\ / \
	1 6 10 11 */
	cout << "The Leaf Node of tree is: " << endl;
	leaf(root);
	return 0;
}
