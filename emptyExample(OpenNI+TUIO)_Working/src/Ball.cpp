#pragma once
#include "Ball.h"

Ball::Ball()
{
	init(10.f, ofPoint(250.f, 250.f));
	SetMoveVector(-100.f, -100.f);
}

Ball::~Ball()
{

}

void Ball::Render()
{
	ofSetHexColor(0xff0000);
	ofCircle(m_Position, m_Radius);
}

void Ball::Update(float dt)
{
	m_Position.x += m_MoveVector.x * dt;
	m_Position.y += m_MoveVector.y * dt;
	CheckBorderCollision();
}

void Ball::init( float rad, ofPoint initPos )
{
	SetRadius(rad);
	SetPosition(initPos);
}

bool Ball::IsCollision( GameObject obj )
{
	ofPoint LeftTopDot(obj.m_CollisionBox.minCoordinate); 
	ofPoint RightBottomDot(obj.m_CollisionBox.maxCoordinate);
	ofPoint LeftBottomDot(obj.m_CollisionBox.minCoordinate.x, obj.m_CollisionBox.maxCoordinate.y);
	ofPoint RightTopDot(obj.m_CollisionBox.maxCoordinate.x, obj.m_CollisionBox.minCoordinate.y);

	// 측면에 있을 경우(좌, 우 동일)
	if( m_Position.y > LeftTopDot.y && m_Position.y < LeftBottomDot.y )
	{
		ofPoint leftSideProjected(LeftTopDot.x, m_Position.y);
		ofPoint rightSideProjected(RightTopDot.x, m_Position.y);

		float leftDist = m_Position.distance(leftSideProjected);
		float rightftDist = m_Position.distance(rightSideProjected);

		if (leftDist < m_Radius || rightftDist < m_Radius)
		{
			Reflect(X_DIR);
			return true;
		}
	}

	// 정면에 있을 때(위, 아래 동일)
	if( m_Position.x < RightBottomDot.x && m_Position.x > LeftBottomDot.x )
	{
		ofPoint bottomSideProjected(m_Position.x, LeftBottomDot.y);
		ofPoint topSideProjected(m_Position.x, LeftTopDot.y);

		float bottomDist = m_Position.distance(bottomSideProjected);
		float topDist = m_Position.distance(topSideProjected);

		if (bottomDist < m_Radius || topDist < m_Radius)
		{
			Reflect(Y_DIR);
			return true;
		}
	}

	return false;
}

void Ball::SetMoveVector( float x, float y )
{
	m_MoveVector.x = x;
	m_MoveVector.y = y;
}

void Ball::CheckBorderCollision()
{
	// 아래쪽(게임 끝)
	if(m_Position.y > WINDOW_HEIGHT)
	{
		return;
	}

	// 오른쪽 끝 && 왼쪽 끝
	if(m_Position.x > WINDOW_WIDTH)
	{
		if (m_MoveVector.x > 0)
		{
			Reflect(X_DIR);
		}
	}


	if(m_Position.x < 0)
	{
		if (m_MoveVector.x < 0)
		{
			Reflect(X_DIR);
		}
	}

	// 위쪽 끝
	if(m_Position.y < 0)
	{
		if (m_MoveVector.y < 0)
		{
			Reflect(Y_DIR);
		}
	}
}

void Ball::Reflect( DIRECTION dir )
{
	switch(dir)
	{
		case X_DIR:
			m_MoveVector.x = -1 * (m_MoveVector.x);
			break;
		case Y_DIR:
			m_MoveVector.y = -1 * (m_MoveVector.y);
			break;
	}
}

