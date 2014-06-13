#include "testApp.h"
#include "Config.h"

#define STEP 5

//--------------------------------------------------------------
void testApp::setup() {

    ofSetLogLevel(OF_LOG_VERBOSE);
	
    openNIDevice.setup();
    openNIDevice.setLogLevel(OF_LOG_VERBOSE);
	openNIDevice.setSkeletonProfile(XN_SKEL_PROFILE_ALL);
	openNIDevice.setResolution(WINDOW_WIDTH, WINDOW_HEIGHT, 30);
    openNIDevice.addDepthGenerator();
    openNIDevice.addImageGenerator();
	openNIDevice.addUserGenerator();
	openNIDevice.setMaxNumUsers(1);
	openNIDevice.setMirror(true);
	openNIDevice.setRegister(true);
    openNIDevice.start();
	openNIDevice.setFrame(30);

	verdana.loadFont(ofToDataPath("NanumGothicBold.ttf"), 24);
	
	//-----------------------object manager
	m_ObjectManager = new ObjectManager();
	m_ObjectManager->Init();

	//-----------------------timer
	m_PreviousTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void testApp::update(){
    openNIDevice.update();
	if (openNIDevice.getNumTrackedUsers() == 0)
	{
		//-----------------------timer
		m_PreviousTime = ofGetElapsedTimeMillis();
		return;
	}
	
	//---------------------update timer
	m_CurrentTime = ofGetElapsedTimeMillis();
	float diff = ( m_CurrentTime - m_PreviousTime ) / 1000;
	m_PreviousTime = m_CurrentTime;

	m_ObjectManager->Update(diff, m_LeftHandPosition, m_RightHandPosition);

	if( m_ObjectManager->IsAllBroken() )
	{
		string msg = " WIN! ";
		verdana.drawString(msg, ofRandom(0, WINDOW_WIDTH), ofRandom(0, WINDOW_HEIGHT));
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0x151515);
	openNIDevice.drawImage(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	RenderSkeleton();

	string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate());
	verdana.drawString(msg, 20, ofGetHeight() - 26);

	m_ObjectManager->Render();
}

void testApp::RenderSkeleton()
{
	int numUsers = openNIDevice.getNumTrackedUsers();

	for ( int i = 0 ; i < numUsers; ++i )
	{
		openNIDevice.drawSkeleton(i);
		ofxOpenNIUser &user = openNIDevice.getTrackedUser(i);

		if (!user.isSkeleton())
		{
			break;
		}

		ofxOpenNIJoint leftHand = user.getJoint(JOINT_LEFT_HAND);
		ofxOpenNIJoint leftShoulder = user.getJoint(JOINT_LEFT_SHOULDER);
		ofxOpenNIJoint rightHand = user.getJoint(JOINT_RIGHT_HAND);
		ofxOpenNIJoint rightShoulder = user.getJoint(JOINT_RIGHT_SHOULDER);

		m_LeftHandPosition.x = leftHand.getProjectivePosition().x-15;
		m_LeftHandPosition.y = leftHand.getProjectivePosition().y-15;
		m_RightHandPosition.x = rightHand.getProjectivePosition().x-15;
		m_RightHandPosition.y = rightHand.getProjectivePosition().y-15;
	}
}

//--------------------------------------------------------------
void testApp::exit(){
    openNIDevice.stop();
	delete m_ObjectManager;
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
	m_RightHandPosition.x = x + 100;
	m_RightHandPosition.y = y;
	m_LeftHandPosition.x = x - 100;
	m_LeftHandPosition.y = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

