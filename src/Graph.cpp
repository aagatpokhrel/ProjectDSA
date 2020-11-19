#include "Graph.h"

Graph::Graph() {
	ofColor undiscoveredFill = ofColor::grey;
	font.load("font.ttf", 16);
	ofFile file;
	file.open(ofToDataPath("people.csv"), ofFile::ReadWrite, false);
	string line;
	int pos;
	int i = 0;
	if (!file.is_open())
	{
		printf(" can't open the file ");
		return;
	}
	while (getline(file, line))
	{
		while ((pos = line.find(',')) >= 0)
		{
			line = line.substr(pos + 1);
		}
		Node node(line);
		node.setup(ofVec2f(vertexCentres[i][0], vertexCentres[i][1]), undiscoveredFill);
		graphVec.push_back(node);
		i++;
	}

	this->addEdge(100, 101);
	this->addEdge(101, 107);
	this->addEdge(100, 107);
	this->addEdge(101, 103);
	this->addEdge(101,108);
	this->addEdge(103,108);
	this->addEdge(103,106);
	this->addEdge(103, 106); 
	this->addEdge(103, 104);
	this->addEdge(103, 105);
	this->addEdge(108, 109);
	this->addEdge(108, 110);
	this->addEdge(109, 110);
	this->addEdge(110, 112);
	this->addEdge(102, 111);
	this->addEdge(102, 100);
	this->addEdge(102, 116);
	this->addEdge(109, 112);
	this->addEdge(113, 114);
	this->addEdge(113, 115);
	this->addEdge(114, 101);
	this->addEdge(115, 118);
	this->addEdge(116, 117);

	for (int count= 0; count <= i; count++)
	{
		for (int j = 0; j < adjacenyList[count].size(); j++)
		{
			auto src = &graphVec.at(count);
			auto dest = &graphVec.at(adjacenyList[count].at(j));

			src->addAdjNode(dest);
			dest->addAdjNode(src);

		}
	}
}

void Graph::addEdge(int s, int d) {
	adjacenyList[s-100].push_back(d-100);
	adjacenyList[d-100].push_back(s-100);
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