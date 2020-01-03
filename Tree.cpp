#include "Tree.h"
int Tree::id = 1;
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	return temp;
}
void Tree::clear(Node *root) {
	if (!root)
		return;

	for (size_t i = 0; i < root->child.size(); ++i)
		clear(root->child[i]);

	delete root;
}
Tree::Tree()
{
	root = newNode(id);
}

Tree::~Tree()
{
	clear(root);
}

void Tree::addLeaf(Node * root,int boss)
{
	if (!root)
	{
		return;
	}

	if (root->key == boss) {
		++id;
		root->child.push_back(newNode(id));
		return;
	}


	for (size_t i = 0; i < root->child.size(); ++i)
	{
			addLeaf(root->child[i], boss);
	}

}

void Tree::add(int boss)
{
	addLeaf(root, boss);
}

void Tree::removeLeaf(Node * root, int boss)
{
	if (!root)
	{
		return;
	}

	for (size_t i = 0; i < root->child.size(); ++i)
	{
		if (root->child[i]->key == boss)
		{
			root->child.erase(root->child.begin() + i);
			return;
		}
		else
		{
			removeLeaf(root->child[i], boss);
		}
	}
}

void Tree::remove(int boss)
{
	if (root->key == boss) {
		cerr << "Cannot dismiss the Boss.\n";
		return;
	}

	removeLeaf(root, boss);
}
