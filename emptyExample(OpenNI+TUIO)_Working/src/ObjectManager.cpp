#include "ObjectManager.h"
#include "Ball.h"
#include "ManipulatedBar.h"
#include "Block.h"
#include "Config.h"


ObjectManager::~ObjectManager()
{
	for(auto iter : m_GameBlockList)
	{
		delete iter;
	}
}


void ObjectManager::Update( float dt, ofPoint LHandPos, ofPoint RHandPos )
{
	for(auto &elem : m_GameBlockList)
	{
		elem->Update(dt);
	}

	m_Ball->Update(dt);
	m_Bar->Update(dt, LHandPos, RHandPos);
	CollisionCheck();
}

void ObjectManager::Render()
{
	for(auto &elem : m_GameBlockList)
	{
		elem->Render();
	}

	m_Ball->Render();
	m_Bar->Render();
}

void ObjectManager::AddObject( GameObject* obj )
{
	m_GameBlockList.push_back(obj);
}

void ObjectManager::Init()
{
	m_Ball = new Ball();
	m_Bar = new ManipulatedBar();

	for(int i = 0; i < KINECT_BLOCK_NUMBER; ++i)
	{
		Block* block = new Block(KINECT_BLOCK_LOCATIONS[i], KINECT_BLOCK_WIDTH, KINECT_BLOCK_HEIGHT);
		AddObject(block);
	}
}

void ObjectManager::CollisionCheck()
{
	for(auto block : m_GameBlockList)
	{
		if ( !((Block*)block)->IsBrokenAlready() && m_Ball->IsCollision(*block) )
		{
			((Block*)block)->BreakBlock();
		}
	}

	m_Ball->IsCollision(*m_Bar);
}

void ObjectManager::SetBarPosition( float x, float y )
{
	m_Bar->SetPosition(x, y);
}

bool ObjectManager::IsAllBroken()
{
	bool checker = true;

	for(auto iter : m_GameBlockList)
	{
		checker = checker && ((Block*)iter)->IsBrokenAlready();
	}

	return checker;
}

