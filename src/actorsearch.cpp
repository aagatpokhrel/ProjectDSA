#include "actorsearch.h"

ActorSearch::ActorSearch(int& screenNum) :State(screenNum) {
	font.load("font.ttf", 32);
	backBtn = "Back";
	backX = ofGetWidth() - font.stringWidth(backBtn) - 40;
	backY = ofGetHeight() - font.stringHeight(backBtn) - 40;
	backRect = ofRectangle(backX, backY- font.stringHeight(backBtn)-10, font.stringWidth(backBtn), font.stringHeight(backBtn));
	
	startBtn = "Start";
	startX = 40;
	startY = ofGetHeight() - font.stringHeight(startBtn) - 40;
	startRect = ofRectangle(startX, startY - font.stringHeight(startBtn) - 10, font.stringWidth(startBtn), font.stringHeight(startBtn));

	soundPlayer.load(ofToDataPath("Assets/Sound/menuSelect.wav"));

	sourceinputField.setup("Actor's Name", "Emma Watson");
	sourceinputField.setBorderColor(ofColor::red);
	sourceinputField.setPosition(100, 850);
	sourceinputField.setSize(400, 100);
	destinputField.setup("Actor's Name", "Jennifer Lawrence");
	destinputField.setBorderColor(ofColor::red);
	destinputField.setPosition(600, 850);
	destinputField.setSize(400, 100);

}
void ActorSearch::update() {
	source = sourceinputField;
	destination = destinputField;
	dfs.update();
}

//--------------------------------------------------------------
void ActorSearch::draw() {
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(130);
	if (isBackSelect)
	{
		ofSetColor(0, 128, 0);
	}
	font.drawString(backBtn, backX, backY);
	ofSetColor(130);
	if (isStartSelect)
	{
		ofSetColor(0, 128, 0);
	}
	font.drawString(startBtn, startX, startY);
	ofSetColor(130);
	sourceinputField.draw();
	destinputField.draw();
	dfs.draw();
}

//--------------------------------------------------------------
void ActorSearch::keyPressed(int key) {
	if (key == ' ') {
		//dfs.start();
	}
}
//--------------------------------------------------------------
void ActorSearch::keyReleased(int key) {

}

//--------------------------------------------------------------
void ActorSearch::mouseMoved(int x, int y) {
	if (backRect.inside(x, y)) {
		isBackSelect = true;
	}
	else if (startRect.inside(x, y)) {
		isStartSelect = true;
	}
	else {
		isBackSelect = false;
		isStartSelect = false;
	}
}

//--------------------------------------------------------------
void ActorSearch::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ActorSearch::mousePressed(int x, int y, int button) {
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (backRect.inside(x, y)) {
			dfs.reset();
			screenNum = 0;
			dfs.reset();
			soundPlayer.play();
		}
	}
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (startRect.inside(x, y)) {

			soundPlayer.play();
			dfs.start(source,destination);
		}
	}
	//std::cout << x << "\t" << y << "\n
}

//--------------------------------------------------------------
void ActorSearch::mouseReleased(int x, int y, int button) {

}