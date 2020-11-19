#pragma once
#include "ofMain.h"
#include <string>
#include <fstream>
#include <string>
#include <map>
#include "UnitRectangle.h"
#include <vector>
#include <thread>
//#include <string>
#include <chrono>

class BinarySearch
{
public:
	BinarySearch();
	void update();
	void draw();
	void search(std::string key);
	int compareString(string s1, string s2);
	/*void pause();
	void stop();*/
	void start();
	void reset();
	void manageData();
	//void start();
public:
	std::vector <UnitRectangle> rects;
	std::map<int,string> datas;
	int dataSize;
	float x;
	float y;
	float width;
	float height;
	float arrX;
	bool searchSuccess = false;;
	ofColor fillColor;
	int colorPos = -1;
	int first, last , middle;
	bool isStart = false;
	std::vector <int> animatePos;
	int dummy ;
	ofImage searchImage;
	ofTrueTypeFont font;
	ofTrueTypeFont noMatchFont;
	string decData;

	bool discardLeft = false;
	bool discardRight = false;
	bool playSound = false;

	ofSoundPlayer soundPlayer;
};

