#include "binarysearch.h"

BinarySearch::BinarySearch() {
	soundPlayer.load(ofToDataPath("Assets/Sound/middleAnim.wav"));
	
	font.load("font.ttf", 16);
	ofFile file;
	file.open(ofToDataPath("movies.csv"), ofFile::ReadWrite, false);
	string line;
	int pos;
	if (!file.is_open())
	{
		printf(" can't open the file ");
		return;
	}
	while (getline(file, line))
	{
		while ((pos = line.find(',')) >= 0)
		{
			string field = line.substr(0, pos);
			line = line.substr(pos + 1);
			int id = 0;
			stringstream fummy(field);
			fummy >> id;
			datas.insert(pair<int, string>(id, line));
		}
	}

	dataSize = datas.size();
	first = 0;
	last = dataSize-1;
	middle = (first + last) / 2;
	//width = 250.0f;

	width = (ofGetWidth() - 100) / dataSize;
	height = 80.0f;



	/*x = ofGetWidth() / 2 - ((width * dataSize) / 2);
	y = ofGetHeight() / 2 - (height / 2)-300;*/
	x = 25;
	y = ofGetHeight() / 2 - 150;


	for (int i = 0; i < dataSize; i++)
	{
		UnitRectangle unitBox;
		unitBox.posX = x;
		unitBox.posY = y;
		unitBox.contentY = y + 40;
		unitBox.contentX = x + 10;
		unitBox.content = datas.at(i + 1);
		unitBox.width = unitBox.getStringWidth() + 20;
		unitBox.height = height;
		//unitBox.resizeString();
		rects.push_back(unitBox);

		x += unitBox.width;
	}
	dummy = middle;
}
void BinarySearch::manageData() {
	
}
void BinarySearch::update() {
	if (!animatePos.empty()) {

	}
}
void BinarySearch::draw() {
	ofNoFill();
	ofEnableSmoothing();

	if (!animatePos.empty()) {
		int size = animatePos.size();
		rects.at(dummy).fillColor = ofColor::white;
		dummy = animatePos.back();

		if (size >= 2)
		{
			if (animatePos[size - 1] < animatePos[size - 2]) {
				for (int i = 0; i < dummy; i++)
				{
					rects.at(i).fillColor = ofColor::grey;
				}
			}
			else {
				for (int i = dummy + 1; i < rects.size(); i++)
				{
					rects.at(i).fillColor = ofColor::grey;
				}
			}
		}

		animatePos.pop_back();
		rects.at(dummy).fillColor = ofColor::red;

		if (playSound) {
			soundPlayer.play();
		}
		playSound = true;

		/*if (discardRight)
		{
			for (int i = dummy+1; i < rects.size(); i++)
			{
				rects.at(i).fillColor = ofColor::grey;
			}
			discardRight = false;
		}
		else if (discardLeft) {
			for (int i = 0; i < dummy; i++)
			{
				rects.at(i).fillColor = ofColor::grey;
			}
			discardLeft = false;
		}*/

		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	//int tranPos = (dataSize / 2 - dummy - 2) * 300;
	//ofTranslate(tranPos, 0);
	for (int i=0;i<rects.size(); i++)
	{
		//rects.at(i).content = datas.at(i+1);
		rects.at(i).draw();
		ofSetColor(ofColor::white);
		//std::cout << rects.at(i).posX << "\n";
	}
	if (animatePos.empty() && isStart) { // still buggy
		if (searchSuccess)
		{
			searchImage.draw(200, y + 200, 200, 300);
			font.drawString(decData, 500, y + 220);
		}
		else {
			ofSetColor(ofColor::red);
			noMatchFont.load("font.ttf", 26);
			noMatchFont.drawString("No match found", 800, 800);
		}
		for (int i = 0; i < rects.size(); i++)
		{
			if (i != dummy) {
				rects.at(i).fillColor = ofColor::grey;
			}
		}
		if (playSound) {
			soundPlayer.play();
		}
		playSound = false;
	}
	
}
void BinarySearch::start() {
	//isStart = true;
}

void BinarySearch::reset() {
	first = 0;
	last = dataSize - 1;
	middle = (first + last) / 2;

	isStart = false;
	searchSuccess = false;
	playSound = false;

	animatePos.clear();

	for (int i = 0; i < rects.size(); i++) {
		rects.at(i).fillColor = ofColor::white;
	}
}

int BinarySearch::compareString(string s1, string s2) {
	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

	return s1.compare(s2);
}

void BinarySearch::search(string key) {
	isStart = true;

	while (first <= last)
	{
		/*if (isStart) {*/
			animatePos.push_back(middle);
			/*rects.at(middle).fillColor = ofColor::red;*/
			if (compareString(datas.at(middle + 1),key)==0)
			{
				//search successful
				searchSuccess = true;
				string bummy = "pics/" + to_string(middle+1) + ".jpg";
				searchImage.load(bummy);
				ofFile openDecs;
				string filename = "decs/" + to_string(middle + 1) + ".txt";
				openDecs.open(ofToDataPath(filename), ofFile::ReadWrite, false);
				ofBuffer decs = openDecs.readToBuffer();
				decData = decs.getText();

				//reset();
				break;
			}
			//key is less than 
			else if (compareString(key,datas.at(middle + 1))==-1)
			{
				//discardRight = true;
				last = middle - 1;
				//dataSize /= 2;
				/*update("less");*/
			}
			else
			{
				//discardLeft = true;
				first = middle + 1;
				//dataSize /= 2;
				/*update("greater");*/
			}
			middle = (first + last) / 2;
	}
		
	std::reverse(animatePos.begin(), animatePos.end());
}
