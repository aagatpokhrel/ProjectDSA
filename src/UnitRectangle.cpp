#include "UnitRectangle.h"

void UnitRectangle::draw() {
	//drawing th rectangle with fill
	ofFill();
	ofSetColor(fillColor);
	ofDrawRectangle(posX, posY, width, height);

	//drawing the stroke color of rectangle
	ofNoFill();
	ofSetColor(ofColor::black);
	ofDrawRectangle(posX, posY, width, height);

	//draw the content
	font.drawString(content, contentX, contentY);
}