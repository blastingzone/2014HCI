#include "MultiTouch.h"
#include "Config.h"
#include "Album.h"
#include "Pictures.h"

void MultiTouch::setup()
{
	ofSetFrameRate(60);
	// Connect
	MyClient.connect(3333);

	ofAddListener(ofEvents().touchDown, this, &MultiTouch::touchDown);
	ofAddListener(ofEvents().touchMoved, this, &MultiTouch::touchMoved);
	ofAddListener(ofEvents().touchUp, this, &MultiTouch::touchUp);

	m_OpenGLRenderer = new ofGLRenderer();

	//------ Album
	for (int i = 0; i < 3; ++i)
	{
		Album* tempAlbum = new Album();
		tempAlbum->Init();
		m_AlbumList.push_back(tempAlbum);
	}

	m_SelectedAlbum = nullptr;
	m_SelectedPicture = nullptr;

	//----- squeeze or splay
	m_CursorInterDistance = 0.f;
}


//--------------------------------------------------------------
void MultiTouch::update(){
	if (m_SelectedAlbum != nullptr && m_SelectedPicture != nullptr)
	{
		m_SelectedPicture = nullptr;
	}
}

//--------------------------------------------------------------
void MultiTouch::draw(){

	//MyClient.drawCursors();
	//MyClient.drawObjects();

	m_OpenGLRenderer.pushMatrix();
	for(auto iter : m_AlbumList)
	{
		iter->Render();
	}

	if (nullptr != m_SelectedAlbum)
	{
		ofPoint check = m_SelectedAlbum->GetPosition();
		ofSetHexColor(0xff0000);
		ofCircle(check, 10.f);
		ofSetHexColor(0xffffff);

	}

	if (nullptr != m_SelectedPicture)
	{
		ofPoint check = m_SelectedPicture->GetPosition();
		ofSetHexColor(0x0000ff);
		ofCircle(check, 10.f);
		ofSetHexColor(0xffffff);
	}

	m_OpenGLRenderer.popMatrix();
}

//--------------------------------------------------------------
void MultiTouch::keyPressed(int key){

}

//--------------------------------------------------------------
void MultiTouch::keyReleased(int key){

}

//--------------------------------------------------------------
void MultiTouch::mouseMoved(int x, int y){
	
}

//--------------------------------------------------------------
void MultiTouch::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void MultiTouch::mousePressed(int x, int y, int button){
	TabEventHandler(x, y);
}

//--------------------------------------------------------------
void MultiTouch::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void MultiTouch::windowResized(int w, int h){

}

//--------------------------------------------------------------
void MultiTouch::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void MultiTouch::dragEvent(ofDragInfo dragInfo){ 

}

void MultiTouch::touchDown( ofTouchEventArgs & touch )
{
	TUIO::TuioCursor* cursor1 = nullptr;
	TUIO::TuioCursor* cursor2 = nullptr;
	TUIO::TuioCursor* cursor3 = nullptr;
	TUIO::TuioCursor* cursor4 = nullptr;
	TUIO::TuioCursor* cursor5 = nullptr;


	// move image
	if ( MyClient.client->getTuioCursors().size() == 1 )
	{
		TabEventHandler(touch.x * WINDOW_WIDTH, touch.y * WINDOW_HEIGHT);
	}

	// up scale / down scale / rotate
	if ( MyClient.client->getTuioCursors().size() == 2 )
	{
		for ( auto *iter : MyClient.client->getTuioCursors() )
		{
			switch ( iter->getCursorID() )
			{
			case 0:
				cursor1 = iter;
				break;
			case 1:
				cursor2 = iter;
				break;
			default:
				break;
			}
		}

		// 规绢内靛
		if (cursor1 == nullptr || cursor2 == nullptr)
		{
			return;
		}

		TwoTabEventHandler(cursor1, cursor2);
	}

	if ( MyClient.client->getTuioCursors().size() > 3 )
	{

		for ( auto *iter : MyClient.client->getTuioCursors() )
		{
			switch ( iter->getCursorID() )
			{
			case 0:
				cursor1 = iter;
				break;
			case 1:
				cursor2 = iter;
				break;
			case 2:
				cursor3 = iter;
				break;
			case 3:
				cursor4 = iter;
				break;
			case 4:
				cursor5 = iter;
				break;
			default:
				break;
			}
		}

		float currentDistance = 0.f;

		if (cursor1 != nullptr && cursor2 != nullptr)
		{
			currentDistance += cursor1->getDistance(cursor2);
		}

		if (cursor2 != nullptr && cursor3 != nullptr)
		{
			currentDistance += cursor2->getDistance(cursor3);
		}

		if (cursor3 != nullptr && cursor4 != nullptr)
		{
			currentDistance += cursor3->getDistance(cursor4);
		}

		if (cursor4 != nullptr && cursor5 != nullptr)
		{
			currentDistance += cursor4->getDistance(cursor5);
		}

		m_CursorInterDistance = currentDistance;
	}
}

void MultiTouch::touchMoved( ofTouchEventArgs & touch )
{
	TUIO::TuioCursor* cursor1 = nullptr;
	TUIO::TuioCursor* cursor2 = nullptr;
	TUIO::TuioCursor* cursor3 = nullptr;
	TUIO::TuioCursor* cursor4 = nullptr;
	TUIO::TuioCursor* cursor5 = nullptr;

	if ( MyClient.client->getTuioCursors().size() == 1 )
	{
		float x = touch.x * PQLAB_WINDOW_WIDTH;
		float y = touch.y * PQLAB_WINDOW_HEIGHT;

		if (nullptr != m_SelectedAlbum)
		{
			m_SelectedAlbum->DragEventHandler(x, y);
		}

		if (nullptr != m_SelectedPicture)
		{
			m_SelectedPicture->DragEventHandler(x, y);
		}
	}

	// up scale / down scale / rotate
	if ( MyClient.client->getTuioCursors().size() == 2 )
	{
		for ( auto *iter : MyClient.client->getTuioCursors() )
		{
			switch ( iter->getCursorID() )
			{
			case 0:
				cursor1 = iter;
				break;
			case 1:
				cursor2 = iter;
				break;
			default:
				break;
			}
		}

		// 规绢内靛
		if (cursor1 == nullptr || cursor2 == nullptr)
		{
			return;
		}

		TwoTabEventHandler(cursor1, cursor2);
	}

	if ( MyClient.client->getTuioCursors().size() > 3 )
	{

		for ( auto *iter : MyClient.client->getTuioCursors() )
		{
			switch ( iter->getCursorID() )
			{
			case 0:
				cursor1 = iter;
				break;
			case 1:
				cursor2 = iter;
				break;
			case 2:
				cursor3 = iter;
				break;
			case 3:
				cursor4 = iter;
				break;
			case 4:
				cursor5 = iter;
				break;
			default:
				break;
			}
		}

		float currentDistance = 0.f;

		if (cursor1 != nullptr && cursor2 != nullptr)
		{
			currentDistance += cursor1->getDistance(cursor2);
		}

		if (cursor2 != nullptr && cursor3 != nullptr)
		{
			currentDistance += cursor2->getDistance(cursor3);
		}

		if (cursor3 != nullptr && cursor4 != nullptr)
		{
			currentDistance += cursor3->getDistance(cursor4);
		}

		if (cursor4 != nullptr && cursor5 != nullptr)
		{
			currentDistance += cursor4->getDistance(cursor5);
		}

		SqueezeOrSplay(currentDistance / m_CursorInterDistance);
		m_CursorInterDistance = currentDistance;
	}
}

void MultiTouch::touchUp( ofTouchEventArgs & touch )
{
	m_SelectedAlbum = nullptr;
	m_SelectedPicture = nullptr;
	m_CursorInterDistance = 0.f;
}

void MultiTouch::SqueezeOrSplay(float strength)
{
	if ( nullptr != m_SelectedAlbum)
	{
		m_SelectedAlbum->UpdateChildDistance(strength);
	}
}

void MultiTouch::TabEventHandler(float x, float y)
{
	for (auto iter : m_AlbumList)
	{
		if ((iter->IsTouchedMe(x, y) ==  true))
		{
			m_SelectedAlbum = iter;
			m_SelectedAlbum->TapEventHandler();
			break;
		}
	}

	for (auto iter : m_AlbumList)
	{
		for(auto picture : iter->m_PictureList)
		{
			if(picture->IsTouchedMe(x, y) == true)
			{
				m_SelectedPicture = picture;
				m_SelectedPicture->TapEventHandler();
				break;
			}
		}
	}
}

void MultiTouch::TwoTabEventHandler(TUIO::TuioCursor* one, TUIO::TuioCursor* two)
{
	for(auto iter : m_AlbumList)
	{
		for(auto picture : iter->m_PictureList)
		{
			if (picture->IsTouchedMe(one->getScreenX(WINDOW_WIDTH), one->getScreenY(WINDOW_HEIGHT))
				|| picture->IsTouchedMe(two->getScreenX(WINDOW_WIDTH), two->getScreenY(WINDOW_HEIGHT)))
			{
				m_SelectedPicture = picture;
				m_SelectedPicture->PinchOrSpreadEventHandler(one->getDistance(two));

				float angle = 0.f;
				
				if (one->getScreenX(PQLAB_WINDOW_WIDTH) - two->getScreenX(PQLAB_WINDOW_WIDTH) == 0)
				{

				}
				else
				{
					angle = atanf( (one->getY() - two->getY()) / (one->getX() - two->getX()) );
					angle *= 180 * PI;
					m_SelectedPicture->SetRotate(angle);
					break;
				}
			}
		}
	}
}
