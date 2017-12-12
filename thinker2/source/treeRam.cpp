#include "treeRam.h"

Node::Node()
{

}

Node::~Node()
{

}

Node* Node::CreateNode(const float byte)
{
	Node* newNode = new Node();

	newNode->_byte = byte;
	newNode->_left = NULL;
	newNode->_right = NULL;

	return newNode;
}

void Node::Add(Node*& tree, const float byte)
{
	if (tree == NULL)
	{
		Node* newNode = CreateNode(byte);

		tree = newNode;
	}
	else
	{
		float sizeRoot = tree->_byte;

		if (byte == sizeRoot)
		{
			return;
		}
		else if (byte < sizeRoot)
		{
			Add(tree->_left, byte);
		}
		else if (byte > sizeRoot)
		{
			Add(tree->_right, byte);
		}
	}
}

bool Node::Search(const Node* tree, const float byte)
{
	if (tree == NULL)
	{
		return false;
	}
	else
	{
		float sizeRoot = tree->_byte;

		if (byte == sizeRoot)
		{
			return 1;
		}

		if (byte < sizeRoot)
		{
			return Search(tree->_left, byte);
		}

		if (byte > sizeRoot);
		{
			return Search(tree->_right, byte);
		}
	}
}

int Node::countNodes(const Node* tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	else
	{
		return countNodes(tree->_left) + countNodes(tree->_right) + 1;
	}
}

void Node::Clear(Node*& tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		Clear(tree->_left);
		Clear(tree->_right);

		delete tree;
	}
}

void Node::show(const Node* tree, int counter)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		show(tree->_right, counter + 1);

		for (int space = 0; space < counter; ++space)
		{
			printf("      ");
		}

		printf("%0.2f\n", tree->_byte);

		show(tree->_left, counter + 1);
	}
}