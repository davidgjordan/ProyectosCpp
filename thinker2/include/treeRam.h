#ifndef TREERAM_H_
#define TREERAM_H_

#include <cstdio>

using namespace std;

struct Node
{
	float _byte;
	Node* _left;
	Node* _right;

	Node();
	~Node();
	Node* CreateNode(const float byte);
	void Add(Node*& tree, const float byte);
	bool Search(const Node* tree, const float byte);
	int countNodes(const Node* tree);
	void Clear(Node*& tree);
	void show(const Node* tree, const int counter);
};

#endif	//TREERAM_H_