#include "actorsearch.h"

ActorSearch::ActorSearch(int& screenNum) :State(screenNum) {
	font.load("font.ttf", 32);
	backBtn = "Back";
	backX = ofGetWidth() - font.stringWidth(backBtn) - 40;
	backY = ofGetHeight() - font.stringHeight(backBtn) - 40;
	backRect = ofRectangle(backX, backY- font.stringHeight(backBtn)-10, font.stringWidth(backBtn), font.stringHeight(backBtn));
}
void ActorSearch::update() {
	dfs.update();
}

//--------------------------------------------------------------
void ActorSearch::draw() {
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(130);
	font.drawString(backBtn, backX, backY);
	dfs.draw();
}

//--------------------------------------------------------------
void ActorSearch::keyPressed(int key) {
	if (key == ' ') {
		dfs.start();
	}
}
//--------------------------------------------------------------
void ActorSearch::keyReleased(int key) {

}

//--------------------------------------------------------------
void ActorSearch::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ActorSearch::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ActorSearch::mousePressed(int x, int y, int button) {
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (backRect.inside(x, y)) {
			screenNum = 0;
		}
	}
}

//--------------------------------------------------------------
void ActorSearch::mouseReleased(int x, int y, int button) {

}