#pragma once
#include <vector>
#include "Node.h"
#include "ofMain.h"
#define NODES_NUM 5

class Graph {
public:
	Graph();
	void addEdge(int s, int d);

	float vertexCentres[NODES_NUM][2] = {
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

	/*extern int adjMat[NODES_NUM][NODES_NUM] = {
	{0,1,1,1,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,1},
	{0,0,0,1,0}
	};*/

	std::vector<Node> graphVec;
	std::vector<Node>::iterator  graph_it;
	std::vector<int> adjacenyList[NODES_NUM];

	//int adjMat[NODES_NUM][NODES_NUM];
};