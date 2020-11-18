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

	vector<Node*> queue;
	vector<Node*>::iterator it;
};


