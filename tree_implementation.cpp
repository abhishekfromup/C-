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



    // root->left = newNode(2);
    // root->left->right = newNode(1);
    // root->left->right->left = newNode(5);
    // root->left->right->left->left = newNode(7);
    // root->left->left = newNode(4);
    // root->left->left->right = newNode(19); //
    // root->left->left->left = newNode(8);
    // root->left->left->left->left = newNode(1);
    // root->left->left->left->right = newNode(0);
    // root->left->left->left->right->right = newNode(1);
    // root->left->left->left->right->left = newNode(1);

    // root->right = newNode(3);
    // root->right->left = newNode(4);
    // // root->right->left = newNode(5);
    // root->right->right = newNode(9);
    // root->right->right->right = newNode(9);

    // root->right->right->left = newNode(3);
    // root->right->left->left = newNode(8);
 
    cout << "Inorder traversal before insertion:";
    inorder(root);
 
    // int key = 12;
 
    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);
    findPaths(root);
    cout << "\n\n\n\nTotal Paths: " << path_count/2 << "\n\n";

	return 0;
}