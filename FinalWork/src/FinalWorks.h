#pragma once

#include "ofMain.h"
#include "ofxOpenNI.h"
#include "ofxTuioClient.h"
#include "MusicManager.h"
#include "demoParticle.h"

class FinalWorks : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void exit();

	void InitOpenNIDevices();

	void RenderSkeleton();

	void resetParticles();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

	void touchDown(ofTouchEventArgs & touch);
	void touchMoved(ofTouchEventArgs & touch);
	void touchUp(ofTouchEventArgs & touch);

private:
	ofTrueTypeFont nGothic;

	ofxOpenNI openNIDevice;
	ofxTuioClient tuioClient;

	MusicManager musicManager;

	ofPoint m_GuitarRightHandPrevious;
	ofPoint m_GuitarRightHand;
	ofPoint m_GuitarLeftHand;

	ofPoint m_BassRightHandPrevious;
	ofPoint m_BassRightHand;
	ofPoint m_BassLeftHand;

	float m_PreviousMilliSecond;

	//in->out으로 바뀔 때 연주함
	bool IsBaseInPrevious;
	bool IsGuitarInPrevious;

	float m_GuitarVolume;
	float m_BassVolume;

	// particle system example
	particleMode currentMode;

	vector <demoParticle> p;
	vector <ofPoint> attractPoints;
	vector <ofPoint> attractPointsWithMovement;
};
