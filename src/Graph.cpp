#include "Graph.h"

Graph::Graph() {
	ofColor undiscoveredFill = ofColor::grey;

	for (int i = 0; i < NODES_NUM; i++)
	{
		Node node(i);
		node.setup(ofVec2f(vertexCentres[i][0], vertexCentres[i][1]), undiscoveredFill);
		graphVec.push_back(node);
	}

	this->addEdge(0, 1);
	this->addEdge(0, 2);
	this->addEdge(0, 3);
	this->addEdge(3, 4);

	for (int i = 0; i < NODES_NUM; i++)
	{
		for (int j = 0; j < adjacenyList[i].size(); j++)
		{
			auto src = &graphVec.at(i);
			auto dest = &graphVec.at(adjacenyList[i].at(j));

			src->addAdjNode(dest);
			dest->addAdjNode(src);

		}
	}
}

void Graph::addEdge(int s, int d) {
	adjacenyList[s].push_back(d);
	adjacenyList[d].push_back(s);
}

//extern int adjMat[NODES_NUM][NODES_NUM] = {
//	{0,1,1,1,0},
//	{1,0,0,0,0},
//	{1,0,0,0,0},
//	{1,0,0,0,1},
//	{0,0,0,1,0}
//};

////float graph[NODES_NUM][2] = {
////		{70, 210},
////		{70, 350},
////		{140, 420},
////		{210, 70 },
////		{210, 210},
////		{210, 490},
////		{280, 140},
////		{280, 280},
////		{350, 70},
////		{350, 350}
////};
//////		[(350, 490),
//////		(2, 5, 9, 13, 14, 15)
//////		],
//////		[(420, 140),
//////		(3, 4, 6, 8, 12, 16, 17)
//////		],
//////		[(420, 280),
//////		(4, 7, 9, 11, 17)
//////		],
//////		[(420, 420),
//////		(9, 10, 15)
//////		],
//////		[(490, 490),
//////		(10, 18, 15)
//////		],
//////		[(560, 420),
//////		(9, 10, 13, 14, 17, 18)
//////		],
//////		[(630, 70),
//////		(17, 11)
//////		],
//////		[(630, 210),
//////		(11, 12, 15, 16, 18)
//////		],
//////		[(700, 420),
//////		(17, 14, 15)
//////		],
//////}