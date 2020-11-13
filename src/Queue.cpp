#include "Queue.h"

void Queue::push(Node* node) {
	queue.push_back(node);
}

Node* Queue::pop() {
	Node* node = queue.at(0);
	queue.erase(queue.begin());

	return node;
}

bool Queue::empty() {
	return queue.empty();
}

bool Queue::containsNode(Node* node) {
	for (int i=0;i<queue.size();i++)
	{
		if (queue[i]->state == node->state)
		{
			return true;
		}
	}
	return false;
}