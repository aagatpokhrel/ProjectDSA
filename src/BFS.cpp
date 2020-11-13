#include "BFS.h"
#include <random>

void BFS::setup() {
	boundingBox.width = ofGetWidth() - 100;
	boundingBox.height = ofGetHeight() - 200;
	boundingBox.x = 50;
	boundingBox.y = 50;

	currentFill = ofColor::yellow;
	doneFill = ofColor::blue;
	discoveredFill = ofColor::red;
	undiscoveredFill = ofColor::grey;

	for (int i = 0; i < NODES_NUM; i++)
	{
		Node node(i);
		node.setup(ofVec2f(graph[i][0], graph[i][1]), undiscoveredFill);
		graphVec.push_back(node);
	}

	for (int i = 0; i < NODES_NUM; i++)
	{
		for (int j = 0; j < NODES_NUM; j++)
		{
			if (adjMat[i][j] == 1) {
				auto src = &graphVec.at(i);
				auto dest = &graphVec.at(j);

				src->addAdjNode(dest);
				//dest->addAdjNode(*src);

			}
		}
	}

}

void BFS::update() {
	Sleep(500);
	draw();
	Sleep(500);
}

void BFS::draw() {
	//ofPushMatrix();
	//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	/*ofNoFill();
	ofSetColor(ofColor::white);
	ofDrawRectangle(boundingBox);*/

	/*for (stackFrontier.it = stackFrontier.stack.begin(); stackFrontier.it != stackFrontier.stack.end(); ++stackFrontier.it) {
		stackFrontier.it->draw();
	}*/

	for (graph_it = graphVec.begin(); graph_it != graphVec.end(); ++graph_it)
	{
		graph_it->draw();
	}

	//ofPopMatrix();
}



void BFS::start() {
	//draw();
	//update();
	//Sleep(2000);

	//dfs algorithm
	int randIndex = rand() % graphVec.size();
	queueFrontier.push(&graphVec[randIndex]);

	/*for (int i = 0; i < stackFrontier.stack.size(); i++)
	{
		stackFrontier.stack[i]->fillColor = ofColor::red;
	}*/

	while (!queueFrontier.empty()) {
		Node* poppedNode = queueFrontier.pop();
		poppedNode->fillColor = currentFill;
		poppedNode->isExplored = true;

		for (int i = 0; i < poppedNode->adjNodes.size(); i++)
		{
			auto adjNode = poppedNode->adjNodes[i];
			if (!adjNode->isExplored && !queueFrontier.containsNode(adjNode))
			{
				queueFrontier.push(adjNode);
				adjNode->fillColor = discoveredFill;

				update();
			}
		}
		poppedNode->fillColor = doneFill;
		poppedNode->edgeFillColor = ofColor::darkGreen;
		update();

		//std::cout << poppedNode->state << " done." << std::endl;
	}
}