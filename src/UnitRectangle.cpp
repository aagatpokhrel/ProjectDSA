#include "UnitRectangle.h"

//void UnitRectangle::loadFont(int fs) {
//	rectContentFont.load("font.ttf", fs);
//}

//void UnitRectangle::resizeString() {
//	while (getStringWidth() > width) {
//		loadFont(fontSize);
//		fontSize--;
//	}
//}

float UnitRectangle::getStringWidth() {
	return rectContentFont.stringWidth(content);
}

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
	rectContentFont.drawString(content, contentX, contentY);
}