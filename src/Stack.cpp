#include "Stack.h"

void Stack::push(Node* nodePtr) {
	stack.push_back(nodePtr);
}

Node* Stack::pop() {
	Node* node = stack.back();
	stack.pop_back();

	return node;
}

bool Stack::empty() {
	return stack.empty();
}

bool Stack::containsNode(Node* node) {
	for (int i=0; i<stack.size();i++)
	{
		if (stack[i]->state==node->state)
		{
			return true;
		}
	}
	return false;
}