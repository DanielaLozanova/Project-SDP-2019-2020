#include "Tree.h"
#include<stack>
#include<queue>
int Tree::id = 1;
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	return temp;
}
void Tree::clear(Node *&root) 
{
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

void Tree::addLeaf(Node * root, int boss)
{
	if (!root)
	{
		return;
	}

	if (root->key == boss)
	{
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

void Tree::delBoss(int boss)
{
	if (root->key == boss)
	{
		cerr << "Cannot dismiss the Boss.\n";
		return;
	}
	Node* bossPtr = findBoss(boss);
	if (bossPtr == nullptr)
	{
		cerr << "Such employee does not exist!"<<endl;
		return;
	}
	pushUp(bossPtr);
}
Node* Tree::findBoss(int boss)
{
	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		for (size_t i = 0; i < temp->child.size(); ++i)
		{
			if (temp->child[i]->key == boss)
			{
				return temp->child[i];
			}
			else
			{
				q.push(temp->child[i]);
			}
		}
	}

	return nullptr;
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

Node* Tree::findNewBoss(Node * root)
{
	int height=0;
	int max=0;
	Node* ptrMax = nullptr;
	for (size_t i = 0; i < root->child.size(); ++i)
	{
		height = DFS(root->child[i]);
		if (height > max)
		{
			max = height;
			ptrMax = root->child[i];
		}
	}
	return ptrMax;
}

int Tree::DFS(Node * root)
{
	int curr = -1;
	int max = 0;
	stack<Node*> st;
	st.push(root);
	Node* temp = nullptr;
	while (!st.empty())
	{
		temp = st.top();
		st.pop();
		++curr;
		if (curr > max)
		{
			max = curr;
		}
		if (temp->child.empty()) --curr;
		else
		{
			for (size_t i = 0; i < temp->child.size(); ++i)
			{
				st.push(temp->child[i]);
			}
		}
	}
	return max;
}

void Tree::pushUp(Node * root)
{
	Node* newBoss = findNewBoss(root);
	vector<Node*> restore = newBoss->child;

	root->key = newBoss->key;

	for (int i = 0; i < root->child.size(); ++i)
	{
		if (root->child[i] == newBoss) 
		{
			root->child.erase(root->child.begin() + i);
			break;
		}
	}

	for (int i = 0; i < restore.size(); ++i)
	{
		root->child.push_back(restore[i]);
	}
}


void Tree::remove(int boss)
{
	if (root->key == boss)
	{
		cerr << "Cannot dismiss the Boss.\n";
		return;
	}

	removeLeaf(root, boss);
}


