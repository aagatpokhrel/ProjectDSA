#pragma once
class State {
public:
	State(int& m_screen) :screenNum(m_screen) {}
	virtual ~State() {}
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void keyPressed(int key) = 0;
	virtual void keyReleased(int key) = 0;
	virtual void mouseMoved(int x, int y) = 0;
	virtual void mouseDragged(int x, int y, int button)=0;
	virtual void mousePressed(int x, int y, int button) = 0;
	virtual void mouseReleased(int x, int y, int button) = 0;
protected:
	int& screenNum;
};