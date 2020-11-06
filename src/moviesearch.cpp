#include "moviesearch.h"

MovieSearch::MovieSearch(int& screenNum) :State(screenNum) {
	font.load("font.ttf", 32);
	backBtn = "Back";
	backX = ofGetWidth() - font.stringWidth(backBtn) - 40;
	backY = ofGetHeight() - font.stringHeight(backBtn) - 40;
	backRect = ofRectangle(backX, backY- font.stringHeight(backBtn)-10, font.stringWidth(backBtn), font.stringHeight(backBtn));
}
void MovieSearch::update() {

}

//--------------------------------------------------------------
void MovieSearch::draw() {
	
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(130);
	font.drawString(backBtn, backX, backY);
}

//--------------------------------------------------------------
void MovieSearch::keyPressed(int key) {
	if (key == ' ')
		screenNum = 1;
}

//--------------------------------------------------------------
void MovieSearch::keyReleased(int key) {

}

//--------------------------------------------------------------
void MovieSearch::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void MovieSearch::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void MovieSearch::mousePressed(int x, int y, int button) {
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (backRect.inside(x, y)) {
			screenNum = 0;
		}
	}
}

//--------------------------------------------------------------
void MovieSearch::mouseReleased(int x, int y, int button) {

}