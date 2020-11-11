#pragma once
#include "ofMain.h"

class UnitRectangle : public ofRectangle
{
public:
	UnitRectangle() {
		
		font.load("font.ttf",16);
	}
	void draw();

	float posX, posY;
	float width, height;
	ofColor fillColor;
	ofTrueTypeFont font;
	float contentX, contentY;
	string content;

};