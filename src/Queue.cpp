#include "Queue.h"

void Queue::push(Node& node) {
	queue.push_back(node);
}

Node Queue::pop() {
	Node node = queue.at(0);
	queue.erase(queue.begin());

	return node;
}

bool Queue::empty() {
	return queue.empty();
}

bool Queue::containsState(int state) {
	for (it = queue.begin(); it != queue.end(); ++it)
	{
		if (it->state == state)
		{
			return true;
		}
	}
	return false;
}