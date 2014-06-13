#include "Album.h"
#include "Pictures.h"

Album::Album()
{
	
}

Album::~Album()
{

}


void Album::Init()
{
	m_AlbumStatus = ALBUM_NORMAL;
	SetPosition(ofRandom(0, WINDOW_WIDTH - ALBUM_WIDTH), ofRandom(0, WINDOW_HEIGHT - ALBUM_HEIGHT));
	UpdateCollisionBox(m_Position.x, m_Position.y, ALBUM_WIDTH, ALBUM_HEIGHT);
	m_AlbumCoverImg.loadImage("Album.png");

	m_previousTapTime = 0.f;

	Pictures* pic_1 = new Pictures();
	pic_1->Init("gods.jpg");
	AddPicture(0, pic_1);

	Pictures* pic_2 = new Pictures();
	pic_2->Init("twogods.jpg");
	AddPicture(1, pic_2);
}

void Album::Render()
{
	ofPushMatrix();
		m_AlbumCoverImg.draw(m_Position.x, m_Position.y, 0, 100, 100);
		switch(m_AlbumStatus)
		{
		case ALBUM_SPREAD:
			{
				for(auto iter : m_PictureList)
				{
					iter->Render();
				}
			}
			break;
		default:
			break;
		};
	ofPopMatrix();
		 
}

void Album::Update( float dt )
{
	switch(m_AlbumStatus)
	{
	case ALBUM_SPREAD:
		break;
	default:
		break;
	};
}



void Album::TapEventHandler()
{
	switch(m_AlbumStatus)
	{
	case ALBUM_NORMAL:
		SpreadChildPictures();
		break;
	case ALBUM_SPREAD:
		DoubleTapEventHandler();
		break;
	default:
		break;
	}
}

void Album::DragEventHandler(float x, float y)
{
	SetPosition(x - ALBUM_WIDTH/2, y - ALBUM_HEIGHT/2);
	UpdateCollisionBox(x - ALBUM_WIDTH/2, y - ALBUM_HEIGHT/2, ALBUM_WIDTH, ALBUM_HEIGHT);
}



void Album::SpreadChildPictures()
{
	for(auto iter : m_PictureList)
	{
		iter->SmartSetPosition(ofRandom(m_Position.x - 200, m_Position.x + 200),
			ofRandom(m_Position.y - 200, m_Position.y + 200));
		iter->SetStatus(PIC_NORMAL);
	}

	m_AlbumStatus = ALBUM_SPREAD;
}


void Album::AddPicture( int id, Pictures* pic )
{
	m_PictureList.push_back(pic);
}

bool Album::IsTouchedMe( float x, float y )
{
	if (m_CollisionBox.minCoordinate.x < x &&
		m_CollisionBox.minCoordinate.y < y &&
		m_CollisionBox.maxCoordinate.x > x &&
		m_CollisionBox.maxCoordinate.y > y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Album::DoubleTapEventHandler()
{
	if (m_previousTapTime == 0.f)
	{
		m_previousTapTime = ofGetElapsedTimeMillis();
	}
	else
	{
		if ( (ofGetElapsedTimeMillis() - m_previousTapTime) < 1000 )
		{
			m_AlbumStatus = ALBUM_NORMAL;
			for(auto iter : m_PictureList)
			{
				iter->SetStatus(PIC_HIDE);
			}
		}

		m_previousTapTime = 0.f;
	}
}

void Album::UpdateChildDistance( float scale )
{
	for(auto iter : m_PictureList)
	{
		ofPoint curPos = iter->GetPosition();

		float x = ( curPos.x - m_Position.x ) * scale;
		float y = ( curPos.y - m_Position.y ) * scale;

		// ¡Ÿ¿Ã±‚
		if(scale < 1.0f)
		{
			x *= -1;
			y *= -1;
		}

		if( (abs(x) < 30 && abs(y) < 30) || (m_Position.distance(curPos) > 400) )
		{
			return;
		}

		iter->SmartSetPosition(curPos.x + x / 200, curPos.y + y / 200);
	}
}
