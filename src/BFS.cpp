#include "BFS.h"
#include <random>
#include <algorithm>

BFS::BFS() {
	font.load("font.ttf", 16);
	boundingBox.width = ofGetWidth() - 100;
	boundingBox.height = ofGetHeight() - 200;
	boundingBox.x = 50;
	boundingBox.y = 50;

	foundFill = ofColor::green;
	doneFill = ofColor::blue;
	discoveredFill = ofColor::red;
	ofFile file;
	file.open(ofToDataPath("people.csv"), ofFile::ReadWrite, false);
	string line;
	int pos;
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
			actors.insert(pair<string, int>(line, id));
		}
	}
	file.open(ofToDataPath("stars.csv"), ofFile::ReadWrite, false);
	string markup;
	int index;
	if (!file.is_open())
	{
		printf(" can't open the file ");
		return;
	}
	//vector<int> movieIds;
	while (getline(file, markup))
	{
		while ((index = markup.find(',')) >= 0)
		{
			string field = markup.substr(0, index);
			markup = markup.substr(index + 1);
			int actorId = 0;
			stringstream fummy(field);
			fummy >> actorId;
			int movieId = 0;
			stringstream gummy(markup);
			gummy >> movieId;
			stars[actorId - 100].push_back(movieId);
		}
	}
	file.open(ofToDataPath("movies.csv"), ofFile::ReadWrite, false);
	string lines;
	int position;
	if (!file.is_open())
	{
		printf(" can't open the file ");
		return;
	}
	while (getline(file, lines))
	{
		while ((position = lines.find(',')) >= 0)
		{
			lines = lines.substr(position + 1);
			movies.push_back(lines);
		}
	}
}
void BFS::reset() {
	display = "";
	for (graph.graph_it = graph.graphVec.begin(); graph.graph_it != graph.graphVec.end(); graph.graph_it++)
	{
		graph.graph_it->fillColor = ofColor::grey;
		graph.graph_it->edgeFillColor = ofColor::grey;
		graph.graph_it->isExplored = false;
		graph.graph_it->isExploredDummy = false;
	}
	queueFrontier.queue.clear();
	duplicateQueue.queue.clear();
	moviesNum.clear();
}
void BFS::update() {
}

void BFS::draw() {
	
	if (!duplicateQueue.empty()) {
		Node *poppedNode = duplicateQueue.pop();
		//std::cout << poppedNode->state << "\n";
		poppedNode->edgeFillColor = ofColor::white;
		if (!poppedNode->isExploredDummy && duplicateQueue.containsNode(poppedNode)) {
			poppedNode->isExploredDummy = true;
			poppedNode->fillColor = discoveredFill;
		}
		else if (poppedNode->state == source || poppedNode->state == destination) {
			poppedNode->fillColor = foundFill;
		}
		else if (poppedNode->isExploredDummy) {
			poppedNode->fillColor = doneFill;
		}
		this_thread::sleep_for(chrono::milliseconds(800));
	}
	for (graph.graph_it = graph.graphVec.begin(); graph.graph_it != graph.graphVec.end(); graph.graph_it++)
	{
		graph.graph_it->draw();
	}
	while (!queueFrontier.empty() && duplicateQueue.empty()) {
		Node* newNode = queueFrontier.pop();
		//newNode->edgeFillColor = ofColor::green;
	}
	if (duplicateQueue.empty()) {
		font.drawString(display, 300, 700);
	}
}

void BFS::start(string sour, string dest) {
	source = sour;
	destination = dest;
	int isValid = 0;
	std::map<string, int>::iterator it;
	for (it = actors.begin();it!=actors.end(); it++) {
		if (it->first == source)
			isValid = isValid+1;
		if (it->first == destination)
			isValid = isValid + 1;
	}
	if (isValid != 2) {
		display = "Please Search Properly";
		return;
	}
	int s = 0, d = 0;
	s = actors.at(source) - 100;
	d = actors.at(destination) - 100;
	queueFrontier.push(&graph.graphVec[s]);
	duplicateQueue.push(&graph.graphVec[s]);
	int count = 0;
	while (!queueFrontier.empty()) {
		Node* poppedNode = queueFrontier.pop();
		if (poppedNode->state == destination) {
			destNode = poppedNode;
		}
		poppedNode->isExplored = true;
		count++;
		for (int i = 0; i < poppedNode->adjNodes.size(); i++)
		{
			auto adjNode = poppedNode->adjNodes[i];
			if (count < adjNode->distFromSource) {
				adjNode->parent = poppedNode;
				adjNode->distFromSource = count;
			}
			if (!adjNode->isExplored && !queueFrontier.containsNode(adjNode))
			{
				queueFrontier.push(adjNode);
				duplicateQueue.push(adjNode);
			}
		}
		duplicateQueue.push(poppedNode);
	}
	Node* temp = destNode;
	while (temp->state != source) {
		for (int j = 0; j < stars[actors.at(temp->state) - 100].size(); j++) {
			int dummyId = stars[actors.at(temp->state) - 100][j];
			for (int i = 0; i < stars[actors.at(temp->parent->state) - 100].size(); i++) {
				if (dummyId == stars[actors.at(temp->parent->state) - 100][i]) {
					moviesNum.push_back(dummyId);
					break;
				}
			}
		}
		queueFrontier.push(temp);
		std::cout << temp->state;
		temp = temp->parent;
	}
	queueFrontier.push(temp);

	int degrees = moviesNum.size();
	display += "The degrees of separation is " + to_string(degrees) + "\n";
	for (int i = 0; i < degrees; i++) {
		display += queueFrontier.queue[i]->state + " and " + queueFrontier.queue[i + 1]->state + " star in " + movies[moviesNum[i] - 1] + "\n";
	}

	
}