#include "Graph.h"

extern float graph[NODES_NUM][2] = {
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

extern int adjMat[NODES_NUM][NODES_NUM] = {
	{0,1,1,1,0},
	{1,0,0,0,0},
	{1,0,0,0,0},
	{1,0,0,0,1},
	{0,0,0,1,0}
};
//
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