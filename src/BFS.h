#pragma once
#include "Queue.h"
#include "Stack.h"
#include <vector>
#include "Graph.h"

class BFS
{
public:
	BFS();
	void update();
	void draw();
	void start(string, string);
	void reset();

	ofColor foundFill;
	ofColor doneFill;
	ofColor discoveredFill;

	Queue queueFrontier;
	Queue duplicateQueue;
	Node* destNode;
	ofRectangle boundingBox;
	Graph graph;
	string source, destination;
	ofTrueTypeFont font;
	string display;
	std::map<string, int> actors;
	vector<int> moviesNum;
	vector<string> movies;
	std::array<std::vector<int>, 19> stars;
};

