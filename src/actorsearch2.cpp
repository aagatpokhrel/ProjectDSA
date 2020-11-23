#include "actorsearch2.h"

ActorSearch2::ActorSearch2(int& screenNum) :State(screenNum) {
	font.load("font.ttf", 32);
	backBtn = "Back";
	backX = ofGetWidth() - font.stringWidth(backBtn) - 40;
	backY = ofGetHeight() - font.stringHeight(backBtn) - 40;
	backRect = ofRectangle(backX, backY - font.stringHeight(backBtn) - 10, font.stringWidth(backBtn), font.stringHeight(backBtn));

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
void ActorSearch2::update() {
	source = sourceinputField;
	destination = destinputField;
	bfs.update();
}

//--------------------------------------------------------------
void ActorSearch2::draw() {
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
	bfs.draw();
}

//--------------------------------------------------------------
void ActorSearch2::keyPressed(int key) {
	if (key == ' ') {
		//dfs.start();
	}
}
//--------------------------------------------------------------
void ActorSearch2::keyReleased(int key) {

}

//--------------------------------------------------------------
void ActorSearch2::mouseMoved(int x, int y) {
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
void ActorSearch2::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ActorSearch2::mousePressed(int x, int y, int button) {
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (backRect.inside(x, y)) {
			bfs.reset();
			screenNum = 0;
			bfs.reset();
			soundPlayer.play();
		}
	}
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (startRect.inside(x, y)) {

			soundPlayer.play();
			bfs.start(source, destination);
		}
	}
}

//--------------------------------------------------------------
void ActorSearch2::mouseReleased(int x, int y, int button) {

}