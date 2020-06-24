#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int key;
	vector<Node*> child;
};

class Tree
{
private:
	Node* root;
	static int id;

	void clear(Node *&root);
	void addLeaf(Node *root, int boss);
	void removeLeaf(Node* root, int boss);
	Node* findNewBoss(Node* root);
	int DFS(Node* root);
	void pushUp(Node* root);
	Node* findBoss(int boss);
public:
	Tree();
	~Tree();

	void add(int boss);
	void delBoss(int boss);
	void remove(int boss);
	
};

/*struct idDFS
{
	int id;
	int dfsH;
	idDFS(int id = -1, int dfsH = -1);
};*/
