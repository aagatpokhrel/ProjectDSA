#include "DFS.h"
#include <random>

DFS::DFS() {
	boundingBox.width = ofGetWidth() - 100;
	boundingBox.height = ofGetHeight() - 200;
	boundingBox.x = 50;
	boundingBox.y = 50;

	currentFill = ofColor::yellow;
	doneFill = ofColor::blue;
	discoveredFill = ofColor::red;
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
			string field = line.substr(0, pos);
			line = line.substr(pos + 1);
			int id = 0;
			stringstream fummy(field);
			fummy >> id;
			actors.insert(pair<string, int>(line,id));
		}
	}

	/*undiscoveredFill = ofColor::grey;

	for (int i = 0; i < NODES_NUM; i++)
	{
		Node node(i);
		node.setup(ofVec2f(graph[i][0], graph[i][1]),undiscoveredFill);
		graphVec.push_back(node);
	}

	for (int i = 0; i < NODES_NUM; i++)
	{
		for (int j = 0;j <NODES_NUM; j++)
		{
			if (adjMat[i][j] == 1) {
				auto src = &graphVec.at(i);
				auto dest = &graphVec.at(j);

				src->addAdjNode(dest);
				dest->addAdjNode(src);

			}
		}*/
//}
	
}
void DFS::reset() {
	for (graph.graph_it = graph.graphVec.begin(); graph.graph_it != graph.graphVec.end(); graph.graph_it++)
	{
		graph.graph_it->fillColor = ofColor::grey;
		graph.graph_it->edgeFillColor = ofColor::grey;
		graph.graph_it->isExplored = false;
		graph.graph_it->isExploredDummy = false;
	}
}
void DFS::update() {
	//draw();
	//Sleep(1000);
}

void DFS::draw() {
	//ofPushMatrix();
	//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	/*ofNoFill();
	ofSetColor(ofColor::white);
	ofDrawRectangle(boundingBox);*/

	/*for (stackFrontier.it = stackFrontier.stack.begin(); stackFrontier.it != stackFrontier.stack.end(); ++stackFrontier.it) {
		stackFrontier.it->draw();
	}*/

	/*for(graph_it=graphVec.begin();graph_it!=graphVec.end(); ++graph_it)
	{
		graph_it->draw();
	}*/
	if (!duplicateStack.empty()) {
		poppedNode = duplicateStack.pop();
		poppedNode->isExploredDummy = true;
		for (int i = 0; i < poppedNode->adjNodes.size(); i++)
		{
			auto adjNode = poppedNode->adjNodes[i];
			if (!adjNode->isExploredDummy && !stackFrontier.containsNode(adjNode))
			{
				adjNode->fillColor = discoveredFill;
			}
			else if (adjNode->state == source || adjNode->state == destination) {
				adjNode->fillColor = currentFill;
			}
			else {
				continue;
			}
		}
		//poppedNode->fillColor = doneFill;
		poppedNode->edgeFillColor = ofColor::white;
		this_thread::sleep_for(chrono::milliseconds(2000));
	}

	for (graph.graph_it = graph.graphVec.begin(); graph.graph_it != graph.graphVec.end(); graph.graph_it++)
	{
		graph.graph_it->draw();
	}
	if (!duplicateStack.empty()) {
		poppedNode->fillColor = doneFill;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	for (graph.graph_it = graph.graphVec.begin(); graph.graph_it != graph.graphVec.end(); graph.graph_it++)
	{
		graph.graph_it->draw();
	}
	//ofPopMatrix();
}

void DFS::start(string sour, string dest) {
	/*draw();
	update();*/
	//Sleep(2000);
	source = sour;
	destination = dest;
	
	//std::cout << source << destination;
	//dfs algorithm
	int s = actors.at(source)-100;
	int d = actors.at(destination)-100;
	std::cout << s << d;
	stackFrontier.push(&graph.graphVec[s]);
	duplicateStack.push(&graph.graphVec[s]);
	/*for (int i = 0; i < stackFrontier.stack.size(); i++)
	{
		stackFrontier.stack[i]->fillColor = ofColor::red;
	}*/

	while (!stackFrontier.empty()) {
		Node* poppedNode = stackFrontier.pop();
		//poppedNode->fillColor = currentFill;
		poppedNode->isExplored = true;

		for (int i = 0; i < poppedNode->adjNodes.size(); i++)
		{
			auto adjNode = poppedNode->adjNodes[i];
			if (!adjNode->isExplored && !stackFrontier.containsNode(adjNode))
			{
				stackFrontier.push(adjNode);
				duplicateStack.push(adjNode);
				//adjNode->fillColor = discoveredFill;


				//update();
			}
		}

		//poppedNode->fillColor = doneFill;
		//poppedNode->edgeFillColor = ofColor::darkGreen;
		//update();

		//std::cout << poppedNode->state << " done." << std::endl;
	}
}