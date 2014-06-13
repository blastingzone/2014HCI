#include "ManipulatedBar.h"

ManipulatedBar::ManipulatedBar()
{
	init();
}

ManipulatedBar::~ManipulatedBar()
{

}

void ManipulatedBar::Render()
{
	//ofFill();
	ofPushMatrix();
		ofTranslate(m_LeftPoint);
		ofRotateZ(-m_Rotate/3);
		for (int i = 0; i < 30; i++){
			ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
			ofRect(ofRandom(0, m_RightPoint.distance(m_LeftPoint)),ofRandom(-10, 10),ofRandom(10,30),ofRandom(10,30));
		}
	ofPopMatrix();
}

void ManipulatedBar::Update( float dt, ofPoint LHandPos, ofPoint RHandPos )
{
	SetHandsPoint(LHandPos, RHandPos);
	float thickness = abs(LHandPos.y - RHandPos.y);
	UpdateCollisionBox(LHandPos.x, LHandPos.y, RHandPos.x - LHandPos.x , (thickness > 30.f ? thickness : 30.f) );
}

void ManipulatedBar::init()
{
	SetHandsPoint(ofPoint(300.f, 300.f), ofPoint(400.f, 300.f));
	m_Rotate = 0.f;
}

void ManipulatedBar::SetHandsPoint( ofPoint posLeft, ofPoint posRight )
{
	m_LeftPoint = posLeft;
	m_RightPoint = posRight;
	if( (m_RightPoint.x - m_LeftPoint.x) == 0)
	{
		m_Rotate = 0;
	}
	else
	{
		m_Rotate = atanf((m_RightPoint.y - m_LeftPoint.y) / (m_RightPoint.x - m_LeftPoint.x));
	}
}

