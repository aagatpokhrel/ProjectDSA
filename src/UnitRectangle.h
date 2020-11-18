#pragma once
#include "ofMain.h"

class UnitRectangle : public ofRectangle
{
public:
	UnitRectangle() {
		rectContentFont.load("font.ttf", 16);
	}
	void loadFont(int fs);
	void draw();
	void resizeString();
	float getStringWidth();

	float posX, posY;
	float width, height;
	ofColor fillColor;
	ofTrueTypeFont rectContentFont;
	int fontSize = 16;
	float contentX, contentY;
	string content;

};