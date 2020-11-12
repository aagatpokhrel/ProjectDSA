#pragma once
#include "Node.h"
#include <vector>

class Queue
{
public:
	void push(Node* node);
	Node* pop();
	bool empty();
	bool containsNode(Node* node);

	std::vector<Node*> queue;
	std::vector<Node*>::iterator it;
};


