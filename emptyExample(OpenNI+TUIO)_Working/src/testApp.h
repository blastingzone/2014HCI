#ifndef _TEST_APP
#define _TEST_APP

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "ObjectManager.h"

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
    void exit();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void RenderSkeleton();

private:

	ObjectManager* m_ObjectManager;

	ofTrueTypeFont verdana;

	ofxOpenNI openNIDevice;

	ofPoint m_LeftHandPosition;
	ofPoint m_RightHandPosition;

	float m_PreviousTime;
	float m_CurrentTime;
};

#endif
