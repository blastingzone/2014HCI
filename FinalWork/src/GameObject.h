#pragma once
#include "of3dGraphics.h"

class GameObject
{
	struct CollisionBox
	{
	public:
		CollisionBox() : minCoordinate(ofPoint(0.f, 0.f)), maxCoordinate(ofPoint(0.f, 0.f)) {};
		ofPoint minCoordinate;
		ofPoint maxCoordinate;
	};

public:
	GameObject() {};
	virtual ~GameObject() {};
	
	void SetPosition(float x, float y) { m_Position.x = x; m_Position.y = y; };
	void SetPosition(ofPoint pos) { m_Position = pos; };
	ofPoint GetPosition() { return m_Position; };

	void IncreasePosition(float x, float y) { m_Position.x += x; m_Position.y += y; };
	void SetMovement(float x, float y) { m_Movement.x = x; m_Movement.y = y; };
	void IncreaseMovement(float x, float y) { m_Movement.x += x; m_Movement.y += y; };

	virtual void Render() {};
	virtual void Update(float dt) {};

	void UpdateCollisionBox(float posX, float posY, float w, float h);

	CollisionBox m_CollisionBox;

protected:
	ofPoint m_Position;
	ofVec2f m_Movement;
};