#include "ofMain.h"
#include "app.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			
	//ofSetupOpenGL(1024, 768, OF_FULLSCREEN);
	ofRunApp(new App());
}
