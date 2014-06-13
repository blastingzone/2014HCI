#include "Block.h"
#include "ofGraphics.h"
#include "Config.h"

Block::Block( ofPoint position, float width, float height )
{
	color = ofRandom(0x101010, 0xffffff);
	IsBroken = false;
	SetPosition(position);
	UpdateCollisionBox(position.x, position.y, width, height);
}

Block::~Block()
{

}


void Block::Render()
{
	ofPushMatrix();
		ofSetHexColor(color);
		ofTranslate(m_Position);
		ofRect(0, 0, KINECT_BLOCK_WIDTH, KINECT_BLOCK_HEIGHT);
	ofPopMatrix();
}

void Block::Update( float dt )
{

}

void Block::BreakBlock()
{
	IsBroken = true;
	color = 0x050505;
}
