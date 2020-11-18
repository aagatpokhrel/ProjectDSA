#pragma once

#include "ofMain.h"
#include <vector>
#include <memory>
#include "state.h"

class App : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private:
	int screenNum;
	std::vector<std::unique_ptr<State>> states;
};
