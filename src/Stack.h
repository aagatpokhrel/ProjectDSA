#pragma once
#include "Node.h"
#include <vector>

class Stack
{
public:
	void push(Node* nodePtr);
	Node* pop();
	bool empty();
	bool containsNode(Node* node);

	std::vector<Node*> stack;
	std::vector<Node*>::iterator it;
};

