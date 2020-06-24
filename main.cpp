#include<iostream>
#include"Tree.h"

using namespace std;

int main()
{
	Tree t;
	t.add(1);
	t.add(1);
	t.add(2);
	t.add(4);
	t.add(4);
	t.add(3);
	t.add(2);
	//t.add(5);
	t.delBoss(2);
	return 0;
}