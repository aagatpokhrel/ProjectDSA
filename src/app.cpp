#include "app.h"
#include "menu.h"
#include "moviesearch.h"
#include "actorsearch.h"
#include "actorsearch2.h"

//--------------------------------------------------------------
void App::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	screenNum = 0;
	std::unique_ptr<State> menu(new Menu(screenNum));
	std::unique_ptr<State> movieSearch(new MovieSearch(screenNum));
	std::unique_ptr<State> actorSearch(new ActorSearch(screenNum));
	std::unique_ptr<State> actorSearch2(new ActorSearch2(screenNum));
	
	states.push_back(std::move(menu));
	states.push_back(std::move(movieSearch));
	states.push_back(std::move(actorSearch));
	states.push_back(std::move(actorSearch2));
}

//--------------------------------------------------------------
void App::update(){
	states[screenNum]->update();
}

//--------------------------------------------------------------
void App::draw(){
	states[screenNum]->draw();
}

//--------------------------------------------------------------
void App::keyPressed(int key){
	states[screenNum]->keyPressed(key);
}

//--------------------------------------------------------------
void App::keyReleased(int key){
	states[screenNum]->keyReleased(key);
}

//--------------------------------------------------------------
void App::mouseMoved(int x, int y ){
	states[screenNum]->mouseMoved(x,y);
}

//--------------------------------------------------------------
void App::mouseDragged(int x, int y, int button){
	states[screenNum]->mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void App::mousePressed(int x, int y, int button){
	states[screenNum]->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void App::mouseReleased(int x, int y, int button){
	states[screenNum]->mouseReleased(x, y, button);
}

