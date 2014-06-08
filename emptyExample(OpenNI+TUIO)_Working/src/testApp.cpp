#include "testApp.h"

#define STEP 5

//--------------------------------------------------------------
void testApp::setup() {

    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();//FromXML("openni/config/ofxopenni_config.xml");
    openNIDevice.setLogLevel(OF_LOG_VERBOSE);
    openNIDevice.addDepthGenerator();
    openNIDevice.addImageGenerator();   // comment this out
    openNIDevice.start();
    //openNIDevice.addInfraGenerator(); // and uncomment this to see infrared generator
                                        // or press the 'i' key when running

    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
}

//--------------------------------------------------------------
void testApp::update(){
    openNIDevice.update();
}

//--------------------------------------------------------------
void testApp::draw(){

	//ofSetColor(255, 255, 255);

    //openNIDevice.drawDebug(); // draws all generators
    //openNIDevice.drawDepth(0, 0);
    //openNIDevice.drawImage(640, 0);
	ofSetBackgroundColor(200);

	// 센서로부터 각 점의 거리값을 받아서 저장
	ofShortPixels depthMap = openNIDevice.getDepthRawPixels();

	int depthMapIdx = 0;
	// i는 화면의 세로축 / j는 가로축 : 키넥트 해상도가 640 * 480 이므로
	for (unsigned int i = 0; i < 480; i += STEP)
	{
		for (unsigned int j = 0; j < 640; j += STEP)
		{
			// getDepthRawPixels()에 의해 반환되는 값은 2차원 배열이 아닌 1차원 배열의 형태이므로
			// 필요한 거리값을 구하기 위해서는 1차원 배열의 인덱스 값의 계산이 필요
			depthMapIdx = i * 640 + j;
			
			// 800이라는 거리를 기준으로 각 지점의 원의 크기와 색을 다르게 설정
			if (depthMap[depthMapIdx] > 800)
			{
				ofSetColor(100);
				ofEllipse(j * 2, i * 2, 5, 5);
			}
			else
			{
				ofSetColor(196, 15, 132);
				ofEllipse(j * 2, i * 2, 10, 10);
			}
		}
	}

    ofSetColor(0, 255, 0);
	string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate());
	verdana.drawString(msg, 20, ofGetHeight() - 26);

}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    switch (key) {
        case 'i':
            if (openNIDevice.isImageOn()){
                openNIDevice.removeImageGenerator();
                openNIDevice.addInfraGenerator();
                break;
            }
            if (openNIDevice.isInfraOn()){
                openNIDevice.removeInfraGenerator();
                openNIDevice.addImageGenerator();
                break;
            }
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

