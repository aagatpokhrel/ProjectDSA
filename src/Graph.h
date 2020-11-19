#pragma once
#include <vector>
#include "Node.h"
#include "ofMain.h"
#define NODES_NUM 19

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
        {210, 490},
        {280, 140},
        {280, 280},
        {350, 70},
        {350, 350},
        {350, 490},
        {420, 140},
        {420, 280},
        {420, 420 },
        {490, 490},
        {560, 420 },
        {630, 70},
        {630, 210 },
        {700, 420}

	};

	/*extern int adjMat[NODES_NUM][NODES_NUM] = {
	{0,1,1,1,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,1},
	{0,0,0,1,0}
	};*/
    ofTrueTypeFont font;
	std::vector<Node> graphVec;
	std::vector<Node>::iterator  graph_it;
	std::vector<int> adjacenyList[NODES_NUM];

	//int adjMat[NODES_NUM][NODES_NUM];
};

/*graph = [
	# Node 0
		[(70, 210), # x, y position
		(1, 2, 4, 6, 7) # adjacent nodes
		],
		# Node 1
		[(70, 350), # Node 1
		(0, 2)
		],
		[(140, 420),
		(0, 1, 5, 9, 10)
		],
		[(210, 70),
		(11, 8, 6)
		],
		[(210, 210),
		(0, 6, 7, 11, 12)
		],
		[(210, 490),
		(2, 10)
		],
		[(280, 140),
		(0, 3, 4, 11)
		],
		[(280, 280),
		(0, 4, 9, 12)
		],
		[(350, 70),
		(11, 3)
		],
		[(350, 350),
		(2, 7, 10, 12, 13, 15)
		],
		[(350, 490),
		(2, 5, 9, 13, 14, 15)
		],
		[(420, 140),
		(3, 4, 6, 8, 12, 16, 17)
		],
		[(420, 280),
		(4, 7, 9, 11, 17)
		],
		[(420, 420),
		(9, 10, 15)
		],
		[(490, 490),
		(10, 18, 15)
		],
		[(560, 420),
		(9, 10, 13, 14, 17, 18)
		],
		[(630, 70),
		(17, 11)
		],
		[(630, 210),
		(11, 12, 15, 16, 18)
		],
		[(700, 420),
		(17, 14, 15)
		],
]*/