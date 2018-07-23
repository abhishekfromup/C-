// tree_implementation.cpp

#include <iostream>
#include <queue>

using namespace std;

int path_count = 0, sum = 0, num = 16;

struct Node
{
	int key;
	struct Node* left, *right;
};

struct Node* newNode(int);
void insertNewNode(struct Node*, int);
void inorder(struct Node*);
void findPaths(struct Node*);
void deleteNode(struct Node*, int);
void deleteDeepest(struct Node*, struct Node*);

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

void findPaths(struct Node* root)
{
	if (!root)
		return;

	sum = sum + root->key;

	findPaths(root->left);

	if (sum == num)
	{
		path_count++;
		// sum = sum - root->key;
	}
	

	findPaths(root->right);
	
	if (sum == num)
	{
		path_count++;
		// sum = sum - root->key;
	}
	sum = sum - root->key;
}



void deleteNode(struct Node* root, int del_key)
{
	queue <struct Node*> q;

	q.push(root);
	struct Node* temp, *key_node;

	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp->key == del_key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	int x = temp->key;
	deleteDeepest(root, temp);
	key_node->key = x;
}

void deleteDeepest(struct Node* root, struct Node* del_node)
{
	queue <struct Node*> q;
	q.push(root);
	struct Node* temp;

	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp->left)
		{
			if (temp->left == del_node)
			{
				delete(del_node);
				return;
			}

			else
			{
				q.push(temp->left);
			}
		}

		if (temp->right)
		{
			if (temp->right == del_node)
			{
				delete(del_node);
				return;
			} 		

			else
			{
				q.push(temp->right);
			}
		}
	}
}

int main()
{
	struct Node* root = newNode(1);
	insertNewNode(root, 2);
	insertNewNode(root, 3);
	insertNewNode(root, 4);
	insertNewNode(root, 1);
	insertNewNode(root, 4);
	insertNewNode(root, 4);
	insertNewNode(root, 9);
	insertNewNode(root, 8);
	insertNewNode(root, 9);
	insertNewNode(root, 5);
	insertNewNode(root, 8);
	insertNewNode(root, 0);
	insertNewNode(root, 8);
	insertNewNode(root, 0);
	insertNewNode(root, 0);
	insertNewNode(root, 0);
	insertNewNode(root, 1);

    cout << "Inorder traversal before insertion:";
    inorder(root);
 
    // int key = 12;
 
    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);
    findPaths(root);
    cout << "\n\n\n\nTotal Paths: " << path_count/2 << "\n\n\n\n\n\n";
    path_count = 0;
    deleteNode(root, 3);
    inorder(root);

    findPaths(root);
    cout << "\n\n\n\nTotal Paths: " << path_count/2 << "\n\n";

	return 0;
}