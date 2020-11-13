#pragma once
#include "ofMain.h"
#include <vector>

class Node
{
public:
	Node(int s);

	void addAdjNode(Node* node);
	bool containsAdjNode(Node* node);

	void setup(ofVec2f centre,ofColor color);
	void update();
	void draw();

	int state;
	std::vector<Node*> adjNodes;
	std::vector<Node*>::iterator it;

	ofVec2f centre;
	ofColor fillColor;
	ofColor edgeFillColor;
	float radius;
	
	ofVec2f contentPos;

	bool isExplored;
};

