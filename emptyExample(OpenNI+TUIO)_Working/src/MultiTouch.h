#pragma once
#include "ofxTuioClient.h"

class Album;
class Pictures;

class MultiTouch : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

	void SqueezeOrSplay(float strength);

	void TabEventHandler(float x, float y);
	void TwoTabEventHandler(TUIO::TuioCursor* one, TUIO::TuioCursor* two);

	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofxTuioClient MyClient;

	void touchDown(ofTouchEventArgs & touch);
	void touchMoved(ofTouchEventArgs & touch);
	void touchUp(ofTouchEventArgs & touch);
private:
	ofGLRenderer m_OpenGLRenderer;

	std::vector<Album*> m_AlbumList;
	Album* m_SelectedAlbum;
	Pictures* m_SelectedPicture;

	float m_CursorInterDistance;
};