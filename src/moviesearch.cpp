#include "moviesearch.h"
#include <thread>

MovieSearch::MovieSearch(int& screenNum) :State(screenNum) {
	font.load("font.ttf", 32);
	backBtn = "Back";
	backX = ofGetWidth() - font.stringWidth(backBtn) - 40;
	backY = ofGetHeight() - font.stringHeight(backBtn) - 40;
	backRect = ofRectangle(backX, backY- font.stringHeight(backBtn)-10, font.stringWidth(backBtn), font.stringHeight(backBtn));
	searchBtn = "Search";
	searchX = 40;
	searchY = ofGetHeight() - font.stringHeight(searchBtn) - 40;
	searchRect = ofRectangle(searchX, searchY - font.stringHeight(searchBtn) - 10, font.stringWidth(searchBtn), font.stringHeight(searchBtn));
	
	inputField.setup("Search Movie","Enter the search key");
	//inputField.setBackgroundColor(ofColor::white);
	inputField.setBorderColor(ofColor::red);
	//inputField.setDefaultTextColor(ofColor::black);
	inputField.setSize(1000, 50);
	inputField.setUseTTF(true);
	inputField.setPosition(50, 100);

	soundPlayer.load(ofToDataPath("Assets/Sound/menuSelect.wav"));

}
void MovieSearch::update() {
	searchKey = inputField;
	bns.update();
}

//--------------------------------------------------------------
void MovieSearch::draw() {
	
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(130);
	if (isBackSelect) {
		ofSetColor(0, 128, 0);
	}
	font.drawString(backBtn, backX, backY);
	ofSetColor(130);
	if (isSearchSelect) {
		ofSetColor(0, 128, 0);
	}
	font.drawString(searchBtn, searchX, searchY);
	ofSetColor(130);
	inputField.draw();
	
	//cam.begin();
	bns.draw();
	//cam.end();
}

//--------------------------------------------------------------
void MovieSearch::keyPressed(int key) {
	if (key == ' ') {
		//t1 = std::thread(&BinarySearch::search,bns,"Apollo 13");
		//t1.join();
		
	}
}

//--------------------------------------------------------------
void MovieSearch::keyReleased(int key) {

}

//--------------------------------------------------------------
void MovieSearch::mouseMoved(int x, int y) {
	if (backRect.inside(x, y)) {
		isBackSelect = true;
	}
	else if (searchRect.inside(x, y)) {
		isSearchSelect = true;
	}
	else {
		isBackSelect = false;
		isSearchSelect = false;
	}
}

//--------------------------------------------------------------
void MovieSearch::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void MovieSearch::mousePressed(int x, int y, int button) {
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (backRect.inside(x, y)) {
			screenNum = 0;
			soundPlayer.play();
		}
	}
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (searchRect.inside(x, y)) {
			bns.search(searchKey);
			soundPlayer.play();
		}
	}
}

//--------------------------------------------------------------
void MovieSearch::mouseReleased(int x, int y, int button) {

}