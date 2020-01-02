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
	void addLeaf(Node *&root, int boss);
public:
	Tree();
	~Tree();
	
	void add(int boss);
	void removeLeaf(Node *& root, int boss);
	void remove(int boss);
};

