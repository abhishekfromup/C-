// tree_implementation.cpp

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int key;
	struct Node* left, *right;
};

struct Node* newNode(int);
void insertNewNode(struct Node*, int);
void inorder(struct Node*);

struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;

	return temp;
}

void insertNewNode(struct Node* root, int key)
{
	queue <struct Node*> q;
	struct Node* temp = root;
	q.push(temp);

	while ( !q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp->left)
			q.push(temp->left);
		else
		{
			temp->left = newNode(key);
			break;
		}

		if (temp->right)
			q.push(temp->right);

		else 
		{
			temp->right = newNode(key);
			break;
		}
	}
}

void inorder(struct Node* root)
{
	if (!root)
		return;

	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


int main()
{
	struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
 
    cout << "Inorder traversal before insertion:";
    inorder(root);
 
    int key = 12;
    insertNewNode(root, key);
    insertNewNode(root, 100);
    insertNewNode(root, 80);
 
    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);

	return 0;
}