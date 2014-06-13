#include "Pictures.h"


Pictures::Pictures()
{
	m_PictureStatus = PIC_HIDE;
	m_PreviousDistance = 0.f;

	m_ImgWidth = PICTURE_WIDTH;
	m_ImgHeight = PICTURE_HEIGHT;
	m_RotationAngle = 0.f;
}


Pictures::~Pictures()
{

}

void Pictures::PinchOrSpreadEventHandler(float distance)
{
	if(m_PreviousDistance == 0.f)
	{
		m_PreviousDistance = distance;
	}
	else
	{
		SetScale(distance / m_PreviousDistance);
		m_PreviousDistance = distance;
	}
}

bool Pictures::IsTouchedMe( float x, float y )
{
	if(m_PictureStatus == PIC_NORMAL)
	{
		if (m_CollisionBox.minCoordinate.x < x &&
			m_CollisionBox.minCoordinate.y < y &&
			m_CollisionBox.maxCoordinate.x > x &&
			m_CollisionBox.maxCoordinate.y > y)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

void Pictures::Init( std::string fileName )
{
	m_PictureImg.loadImage(fileName);
	SetPosition(0, 0);
}

void Pictures::Render()
{
	ofPushMatrix();
		ofTranslate(m_Position.x, m_Position.y, 0);
		ofRotateZ(m_RotationAngle);
		m_PictureImg.draw(-m_ImgWidth/2, -m_ImgHeight/2, 0, m_ImgWidth, m_ImgHeight);
	ofPopMatrix();
}

void Pictures::Update( float dt )
{
	if(m_PictureStatus == PIC_HIDE)
	{
		UpdateCollisionBox(0, 0, 0, 0);
	}
}

void Pictures::SmartSetPosition( float x, float y )
{
	SetPosition(x, y);
	UpdateCollisionBox(x, y, m_ImgWidth, m_ImgHeight);
}

void Pictures::SetScale( float scale )
{
	m_ImgHeight *= scale;
	m_ImgWidth *= scale;
	UpdateCollisionBox(m_Position.x, m_Position.y, m_ImgWidth, m_ImgHeight);
}

void Pictures::TapEventHandler()
{

}


void Pictures::DragEventHandler(float x, float y)
{
	SetPosition(x - m_ImgWidth/2, y - m_ImgHeight/2);
	UpdateCollisionBox(x - m_ImgWidth/2, y - m_ImgHeight/2, m_ImgWidth, m_ImgHeight);
}

void Pictures::SetRotate( float angle )
{
	m_RotationAngle = angle;
}
