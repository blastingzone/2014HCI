#include "ofMain.h"
#include "testApp.h"
#include "MultiTouch.h"
#include "Config.h"

//========================================================================
int main( ){
	ofSetupOpenGL(WINDOW_WIDTH, WINDOW_HEIGHT, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

	char input = NULL;

	printf_s("키넥트 예제를 보고 싶다면 K, 멀티터치 예제를 보고 싶다면 M을 눌러 주십시오.\n");
	input = getchar();

	if (input == 'K' || input == 'k')
	{
		ofRunApp(new testApp());	
	}
	else if (input == 'M' || input == 'm')
	{
		//ofSetFullscreen(true);
		ofRunApp(new MultiTouch());
	}

	return 0;
}
