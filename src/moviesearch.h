#pragma once
#include "state.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "binarysearch.h"
class MovieSearch :
    public State
{
public:
	MovieSearch(int& screenNum);
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void onTextChange(std::string str);
private:
	ofTrueTypeFont font;
	std::string backBtn;
	int backX, backY;
	ofRectangle backRect;

	std::string searchBtn;
	int searchX, searchY;
	ofRectangle searchRect;

	BinarySearch bns;

	std::thread t1;
	//ofxPanel gui;
	ofxTextField inputField;
	string searchKey;
	bool isSearchSelect = false;
	bool isBackSelect = false;
};

