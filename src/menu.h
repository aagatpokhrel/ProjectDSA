#pragma once
#include "state.h"
#include "ofMain.h"
#include <string>
class Menu :
    public State
{
public:
	Menu(int& screenNum);
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
private:
	ofTrueTypeFont font;
	std::string str;
	std::string text1;
	std::string text2;
	std::string title;
	std::string exitBtn;
	int posx, posy;
	float cen_x, cen_y;
	float exitX, exitY;
	ofRectangle rect1, rect2, rect3;
};

