#pragma once
#include "GameObject.h"
#include "Config.h"

class Ball : public GameObject
{
public:
	Ball();
	virtual ~Ball();
	
	void SetRadius(float rad) { m_Radius = rad; };
	void SetMoveVector(float x, float y);
	void init(float rad, ofPoint initPos);

	virtual void Render();
	virtual void Update(float dt);
	bool IsCollision( GameObject obj );
	void CheckBorderCollision();
	void Reflect(DIRECTION dir);

private:
	float m_Radius;
	ofVec2f m_MoveVector;
};