#pragma once
#include "Stack.h"
#include <vector>
#include "Graph.h"
#include <array>

class DFS
{
public:
	DFS();
	//void setup();
	void update();
	void draw();
	void start(string, string);
	void reset();
	void algorithm();

	ofColor foundFill;
	ofColor doneFill;
	ofColor discoveredFill;

	Stack stackFrontier;
	Stack duplicateStack;
	ofRectangle boundingBox;
	Graph graph;
	string source, destination;
	Node* destNode;
	ofTrueTypeFont font;
	std::map<string, int> actors;
	vector<int> moviesNum;
	std::array<std::vector<int>, 19> stars;
	string display;
	vector<string> movies;
};

