#include "binarysearch.h"

BinarySearch::BinarySearch() {
	
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
			stringstream dummy(field);
			dummy >> id;
			datas.insert(pair<int, string>(id, line));
		}
	}

	dataSize = datas.size();
	first = 0;
	last = dataSize-1;
	middle = (first + last) / 2;
	width = 300.0f;
	height = 80.0f;
	x = ofGetWidth() / 2 - ((width * dataSize) / 2);
	y = ofGetHeight() / 2 - (height / 2)-100;
	for (int i = 0; i < dataSize; i++)
	{
		UnitRectangle unitBox;
		unitBox.posX = x;
		unitBox.posY = y;
		unitBox.width = width;
		unitBox.height = height;
		unitBox.contentY = y + 20;
		unitBox.contentX = x + 20;
		rects.push_back(unitBox);

		x += width;
	}
	dummy = 0;
}
void BinarySearch::manageData() {
	
}
void BinarySearch::update() {
	
}
void BinarySearch::draw() {
	ofNoFill();
	ofEnableSmoothing();

	int count = 0;
	if (!animatePos.empty()) {
		rects.at(dummy).fillColor = ofColor::white;
		dummy = animatePos.back();
		animatePos.pop_back();
		rects.at(dummy).fillColor = ofColor::red;
		
	}
	ofTranslate(rects.at(dummy).posX-600, 0);
	for (int i=0;i<rects.size(); i++)
	{
		rects.at(i).content = datas.at(i+1);
		rects.at(i).draw();
		ofSetColor(ofColor::white);
		std::cout << rects.at(i).posX << "\n";
	}
	if (animatePos.empty()) {
		searchImage.draw(200, y + 200, 200, 300);
	}
	this_thread::sleep_for(chrono::milliseconds(1000));
	
}
void BinarySearch::start() {
	isStart = true;
}
void BinarySearch::search(string key) {
	while (first <= last)
	{
		/*if (isStart) {*/
			animatePos.push_back(middle);
			/*rects.at(middle).fillColor = ofColor::red;*/
			if (datas.at(middle + 1) == key)
			{
				//search successful
				searchSuccess = true;
				bummy = "pics/" + to_string(middle+1) + ".jpg";
				searchImage.load(bummy);
				std::cout << "Success!!!";
				first = 0;
				last = dataSize - 1;
				middle = (first + last) / 2;
				break;
			}
			//key is less than 
			else if (key < datas.at(middle + 1))
			{
				last = middle - 1;
				//dataSize /= 2;
				/*update("less");*/
			}
			else
			{
				first = middle + 1;
				//dataSize /= 2;
				/*update("greater");*/
			}
			middle = (first + last) / 2;
	}
		
	std::reverse(animatePos.begin(), animatePos.end());
}
