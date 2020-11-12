#pragma once
#include "Stack.h"
#include <vector>
//#include "Graph.cpp"
#define NODES_NUM 5

class DFS
{
public:
	void setup();
	void update();
	void draw();
	void start();

	ofColor currentFill;
	ofColor doneFill;
	ofColor discoveredFill;
	ofColor undiscoveredFill;

	vector<Node> graphVec;
	vector<Node>::iterator graph_it;

	Stack stackFrontier;

	ofRectangle boundingBox;

	float graph[NODES_NUM][2] = {
		{70, 210},
		{70, 350},
		{140, 420},
		{210, 70 },
		{210, 210},
		/*{210, 490},
		{280, 140},
		{280, 280},
		{350, 70},
		{350, 350}*/
	};

	int adjMat[NODES_NUM][NODES_NUM] = {
		{0,1,1,1,0},
		{1,0,0,0,0},
		{1,0,0,0,0},
		{1,0,0,0,1},
		{0,0,0,1,0}
	};
};

