#pragma once
#include "ofMain.h"
#include <vector>

class Node
{
public:
	Node(string s);

	void addAdjNode(Node* node);
	bool containsAdjNode(Node* node);

	void setup(ofVec2f centre,ofColor color);
	void update();
	void draw();

	string state;
	std::vector<Node*> adjNodes;
	std::vector<Node*>::iterator it;

	ofVec2f centre;
	ofColor fillColor;
	ofColor edgeFillColor;
	float radius;
	Node* parent;
	int distFromSource = 1000;
	ofVec2f contentPos;
	bool isExploredDummy;
	bool isExplored;
	ofTrueTypeFont font;
};

