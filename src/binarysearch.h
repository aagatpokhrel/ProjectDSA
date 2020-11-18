#pragma once
#include "ofMain.h"
#include <string>
#include <fstream>
#include <string>
#include <map>
#include "UnitRectangle.h"
#include <vector>
#include <thread>
#include <chrono>
class BinarySearch
{
public:
	BinarySearch();
	void update();
	void draw();
	void search(std::string key);
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
	bool searchSuccess;
	ofColor fillColor;
	int colorPos = -1;
	int first, last , middle;
	bool isStart = false;
	std::vector <int> animatePos;
	int dummy ;
	ofImage searchImage;
	ofTrueTypeFont font;
	string decData;

	bool discardLeft = false;
	bool discardRight = false;
};

