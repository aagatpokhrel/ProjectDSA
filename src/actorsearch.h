#pragma once
#include "state.h"
#include "ofMain.h"
#include "DFS.h"
#include "ofxGui.h"
//#include "BFS.h"

class ActorSearch :
    public State
{
public:
	ActorSearch(int& screenNum);
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

private:
	DFS dfs;
	//BFS bfs;

	ofTrueTypeFont font;
	std::string backBtn;
	int backX, backY;
	ofRectangle backRect;

	std::string startBtn;
	int startX,startY;
	ofRectangle startRect;

	bool isStartSelect = false;
	bool isBackSelect = false;

	ofSoundPlayer soundPlayer;

	ofxTextField sourceinputField;
	ofxTextField destinputField;
	string source;
	string destination;

};

