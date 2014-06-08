#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	shader.load("videoCompositor.vert", "videoCompositor.frag");	
	background.loadImage("hci.png");

	grab.setDeviceID(0);
	grab.initGrabber(320, 240);
	grab.setUseTexture(true);
}

//--------------------------------------------------------------
void testApp::update(){
	//grab.grabFrame();
	grab.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(255, 255, 255);
	shader.begin();

	shader.setUniformTexture("video", grab, 0);
	shader.setUniformTexture("background", background, 1);
	shader.setUniform1f("greenAmt", (float) mouseX / ofGetWidth());
    shader.setUniform1f("redAmt", (float) mouseY / ofGetHeight());
	
	ofPushMatrix();
	
	ofTranslate(70, 60, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex2f(0, 0);
	glTexCoord2f(320, 0);glVertex2f(640, 0);
	glTexCoord2f(320, 240);glVertex2f(640, 480);
	glTexCoord2f(0, 240);glVertex2f(0, 480);
	glEnd();
	
	ofPopMatrix();
	
	shader.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
