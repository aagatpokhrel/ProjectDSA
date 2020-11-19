#include "Node.h"

Node::Node(int s) {
	state = s;
	radius = 35.0f;
	isExploredDummy = false;
	isExplored = false;
	edgeFillColor = ofColor::grey;
}

void Node::addAdjNode(Node* node) {
	adjNodes.push_back(node);
}

bool Node::containsAdjNode(Node* node) {
	for (int i=0;i<adjNodes.size();i++)
	{
		if (node->state == adjNodes[i]->state) {
			return true;
		}
	}
	return false;
}

void Node::setup(ofVec2f ctre,ofColor color) {
	centre = ctre;
	fillColor = color;

	contentPos = ofVec2f(ctre.x - 2, ctre.y - 2);
}

void Node::update() {

}

void Node::draw() {
	ofEnableSmoothing();

	//draw edges
	ofFill();
	ofSetColor(edgeFillColor);
	ofSetLineWidth(2);

	for (int i=0;i<adjNodes.size();i++)
	{
		ofVec2f lineStart = centre;
		ofVec2f lineEnd = adjNodes[i]->centre;
		ofDrawLine(lineStart, lineEnd);
	}
	
	//draw circle
	ofFill();
	ofSetColor(fillColor);
	ofDrawCircle(centre, radius);
	//draw outline
	ofNoFill();
	ofSetColor(ofColor::white);
	ofDrawCircle(centre, radius);

	//draw content of node
	ofSetColor(ofColor::lightGoldenRodYellow);
	ofDrawBitmapString(ofToString(state), contentPos);

}