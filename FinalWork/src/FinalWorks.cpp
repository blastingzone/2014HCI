#include "FinalWorks.h"
#include "Config.h"

void FinalWorks::setup()
{
	IsBaseInPrevious = false;
	IsGuitarInPrevious = false;

	m_GuitarVolume = 0.f;
	m_BassVolume = 0.f;

	musicManager.Init();

	InitOpenNIDevices();

	tuioClient.connect(3333);

	ofAddListener(ofEvents().touchDown, this, &FinalWorks::touchDown);
	ofAddListener(ofEvents().touchMoved, this, &FinalWorks::touchMoved);
	ofAddListener(ofEvents().touchUp, this, &FinalWorks::touchUp);

	nGothic.loadFont(ofToDataPath("NanumGothicBold.ttf"), 24);

	ofSetFrameRate(30);
	ofSetFullscreen(IsFullScreen);

	//particle
	int num = 800;
	p.assign(num, demoParticle());
	currentMode = PARTICLE_MODE_ATTRACT;

	resetParticles();

	m_PreviousMilliSecond = ofGetElapsedTimeMillis();
}

void FinalWorks::update()
{
	m_PreviousMilliSecond = ofGetElapsedTimeMillis();
	openNIDevice.update();
	musicManager.Update();
	musicManager.UpdateBassPosition(m_BassLeftHand.x, m_BassLeftHand.y);
	musicManager.UpdateGuitarPosition(m_GuitarLeftHand.x, m_GuitarLeftHand.y);

	bool currentBassState = musicManager.IsBassInOutState(m_BassRightHand.x, m_BassRightHand.y);
	bool currentGuitarState = musicManager.IsGuitarInOutState(m_GuitarRightHand.x, m_GuitarRightHand.y);

	if (IsGuitarInPrevious)
	{
		if (!currentGuitarState)
		{
			musicManager.PlayGuitar(m_GuitarVolume);
		}
	}
	if (IsBaseInPrevious)
	{
		if (!currentBassState)
		{
			musicManager.PlayBass(m_BassVolume);
		}
	}

	IsGuitarInPrevious = currentGuitarState;
	IsBaseInPrevious = currentBassState;

	//particle
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);
		p[i].update();
	}

	//lets add a bit of movement to the attract points
	for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
		attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
		attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
	}

}

void FinalWorks::draw()
{
	ofSetHexColor(0x353535);
	//openNIDevice.drawImage(0, 0, 640, 480);
	openNIDevice.drawImage(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

// 	string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate());
// 	nGothic.drawString(msg, 20, ofGetHeight() - 26);

	RenderSkeleton();

	ofSetHexColor(0xAAAAAA);
	musicManager.RenderInstruments();

	// particles
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].draw();
	}

	ofSetColor(190);
	if( currentMode == PARTICLE_MODE_NEAREST_POINTS ){
		for(unsigned int i = 0; i < attractPoints.size(); i++){
			ofNoFill();
			ofCircle(attractPointsWithMovement[i], 10);
			ofFill();
			ofCircle(attractPointsWithMovement[i], 4);
		}
	}
// 	string coordinate = "XGUITAR_RIGHT : " + ofToString(m_GuitarRightHand.x) + "   " + ofToString(m_GuitarRightHand.y);
// 	string coordinate2 = "GuitarCollisionCenter : " + ofToString(musicManager.GetGuitarCollisionBoxCenter().x) +  "   " + ofToString(musicManager.GetGuitarCollisionBoxCenter().y);
// 
// 	ofSetHexColor(0xFF0000);
// 
// 	nGothic.drawString(coordinate, 20, ofGetHeight() / 2);
// 	nGothic.drawString(coordinate2, 20, ofGetHeight() / 2 - 100);
}

void FinalWorks::exit()
{
	openNIDevice.stop();
	tuioClient.disconnect();
}

void FinalWorks::keyPressed( int key )
{

}

void FinalWorks::keyReleased( int key )
{

}

void FinalWorks::mouseMoved( int x, int y )
{

}

void FinalWorks::mouseDragged( int x, int y, int button )
{

}

void FinalWorks::mousePressed( int x, int y, int button )
{

}

void FinalWorks::mouseReleased( int x, int y, int button )
{

}

void FinalWorks::windowResized( int w, int h )
{

}

void FinalWorks::touchDown( ofTouchEventArgs & touch )
{
	int number = 0;
	int key = 0;
	float volume = 0.f;

	if (tuioClient.client->getTuioCursors().size() > 0)
	{
		number = tuioClient.client->getTuioCursors().size();
		float leftestX = WINDOW_WIDTH;
		for( auto iter : tuioClient.client->getTuioCursors() )
		{
			leftestX = ( leftestX < iter->getX() ? leftestX : iter->getX() );
			volume += ( iter->getY() ) / number;
		}

		leftestX *= WINDOW_WIDTH;

		for(; leftestX > 0; ++key)
		{
			leftestX -= CHORD_MAJOR_KEY_WIDTH;
		}

		if (IsMajorChord)
		{
			musicManager.ChangeChord((MajorChordType)key);
			musicManager.PlayPiano(volume, number);
		}
		else
		{
			musicManager.ChangeChord((MinorChordType)key);
			musicManager.PlayPiano(volume, number);
		}

		if(volume < 0.3)
		{
			currentMode = PARTICLE_MODE_NOISE;
		}

		if(volume > 0.8)
		{
			currentMode = PARTICLE_MODE_REPEL;
		}
	}
}

void FinalWorks::touchMoved( ofTouchEventArgs & touch )
{
}

void FinalWorks::touchUp( ofTouchEventArgs & touch )
{

}

void FinalWorks::InitOpenNIDevices()
{
	openNIDevice.setup();
	openNIDevice.setLogLevel(OF_LOG_VERBOSE);
	openNIDevice.setSkeletonProfile(XN_SKEL_PROFILE_ALL);
	openNIDevice.setResolution(640, 480, 30);
	openNIDevice.addDepthGenerator();
	openNIDevice.addImageGenerator();
	openNIDevice.addUserGenerator();
	openNIDevice.setMaxNumUsers(5);
	openNIDevice.setMirror(true);
	openNIDevice.setRegister(true);
	openNIDevice.start();
	openNIDevice.setFrame(30);
}

void FinalWorks::RenderSkeleton()
{
	int numUsers = openNIDevice.getNumTrackedUsers();

	for ( int i = 0 ; i < numUsers; ++i )
	{
		openNIDevice.drawSkeleton(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, i);
		ofxOpenNIUser &user = openNIDevice.getTrackedUser(i);

		if (!user.isSkeleton())
		{
			break;
		}

		ofxOpenNIJoint leftHand = user.getJoint(JOINT_LEFT_HAND);
		ofxOpenNIJoint rightHand = user.getJoint(JOINT_RIGHT_HAND);

		float velocity = 0.f;

		switch(i)
		{
		case 0:
			m_GuitarLeftHand.x = leftHand.getProjectivePosition().x * WINDOW_WIDTH / 640;
			m_GuitarLeftHand.y = leftHand.getProjectivePosition().y * WINDOW_HEIGHT / 480;

			m_GuitarRightHand.x = rightHand.getProjectivePosition().x * WINDOW_WIDTH / 640;
			m_GuitarRightHand.y = rightHand.getProjectivePosition().y * WINDOW_HEIGHT / 480;

			velocity = ofDist(m_GuitarRightHandPrevious.x, m_GuitarRightHandPrevious.y, m_GuitarRightHand.x, m_GuitarRightHand.y);
			velocity /= (ofGetElapsedTimeMillis() - m_PreviousMilliSecond);
			m_GuitarVolume = ofMap(velocity, 0, 100, 0.f, 1.0f);
			break;
		case 1:
			m_BassLeftHand.x = leftHand.getProjectivePosition().x * WINDOW_WIDTH / 640;
			m_BassLeftHand.y = leftHand.getProjectivePosition().y * WINDOW_HEIGHT / 480;

			m_BassRightHand.x = rightHand.getProjectivePosition().x * WINDOW_WIDTH / 640;
			m_BassRightHand.y = rightHand.getProjectivePosition().y * WINDOW_HEIGHT / 480;

			velocity = ofDist(m_BassRightHandPrevious.x, m_BassRightHandPrevious.y, m_BassRightHand.x, m_BassRightHand.y);
			velocity /= (ofGetElapsedTimeMillis() - m_PreviousMilliSecond);
			m_BassVolume = ofMap(velocity, 0, 100, 0.f, 1.0f);

			currentMode = PARTICLE_MODE_NEAREST_POINTS;

			break;
		}
	}
}

void FinalWorks::resetParticles()
{
	//these are the attraction points used in the forth demo 
	attractPoints.clear();
	for(int i = 0; i < 4; i++){
		attractPoints.push_back( ofPoint( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) ) );
	}

	attractPointsWithMovement = attractPoints;

	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);		
		p[i].setAttractPoints(&attractPointsWithMovement);;
		p[i].reset();
	}	
}

