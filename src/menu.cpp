#include "menu.h"

Menu::Menu(int& screenNum) :State(screenNum) {
	font.load("font.ttf", 32);
	title = "VISUALIZER DSA";
	str = "Search Movies From : ";
	text1 = "Movie Collection (Binary Search)";
	text2 = "Actors (Depth First Search)";
	exitBtn = "Exit";
	cen_x = (ofGetWidth() - font.stringWidth(str)) / 2;
	cen_y = (ofGetHeight() - font.stringHeight(str)) / 2;
	exitX = ofGetWidth() - font.stringWidth(exitBtn) - 40;
	exitY = ofGetHeight() - font.stringHeight(exitBtn) - 40;
	rect1 = ofRectangle(cen_x, cen_y + 60 - font.stringHeight(str), font.stringWidth(str), font.stringHeight(str));
	rect2 = ofRectangle(cen_x, cen_y + 100 - font.stringHeight(str), font.stringWidth(str), font.stringHeight(str));
	rect3 = ofRectangle(exitX, exitY- font.stringHeight(exitBtn)-10, font.stringWidth(exitBtn), font.stringHeight(exitBtn));

}
void Menu::update() {
	
}

//--------------------------------------------------------------
void Menu::draw() {
	ofSetBackgroundColor(0,0,0);
	ofSetColor(255, 10, 10);
	
	font.drawString(title, (ofGetWidth() - font.stringWidth(title)) / 2,cen_y-300);
	ofSetColor(245, 50, 80);
	font.drawString(str, cen_x,cen_y);
	ofSetColor(130);
	if (isText1Select)
		ofSetColor(0, 128, 0);
	font.drawString(text1, cen_x, cen_y+60);
	ofSetColor(130);
	if (isText2Select)
		ofSetColor(0, 128, 0);
	font.drawString(text2, cen_x, cen_y + 100);
	ofSetColor(130);
	if (isExitSelect)
		ofSetColor(0, 128, 0);
	font.drawString(exitBtn, exitX, exitY);
	
}

//--------------------------------------------------------------
void Menu::keyPressed(int key) {
	
}

//--------------------------------------------------------------
void Menu::keyReleased(int key) {

}

//--------------------------------------------------------------
void Menu::mouseMoved(int x, int y) {
	if (rect1.inside(x, y)) {
		isText1Select = true;
	}
	else if (rect2.inside(x, y)) {
		isText2Select = true;
	}
	else if (rect3.inside(x, y)) {
		isExitSelect = true;
	}
	else {
		isText1Select = false;
		isText2Select = false;
		isExitSelect = false;
	}
}

//--------------------------------------------------------------
void Menu::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void Menu::mousePressed(int x, int y, int button) {
	if (button == OF_MOUSE_BUTTON_LEFT) {
		
		if (rect1.inside(x, y)) {
			screenNum = 1;
		}
		if (rect2.inside(x, y)) {
			screenNum = 2;
		}
		if (rect3.inside(x, y)) {
			OF_EXIT_APP(0);
		}
	}
}

//--------------------------------------------------------------
void Menu::mouseReleased(int x, int y, int button) {

}