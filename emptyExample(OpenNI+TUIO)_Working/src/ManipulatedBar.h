#pragma once
#include "GameObject.h"

class ManipulatedBar : public GameObject
{
public:
	ManipulatedBar();
	virtual ~ManipulatedBar();
	
	virtual void Render();
	virtual void Update(float dt, ofPoint LHandPos, ofPoint RHandPos);

	void init();

	void SetHandsPoint(ofPoint posLeft, ofPoint posRight);

private:
	ofPoint m_LeftPoint;
	ofPoint m_RightPoint;
	float m_Rotate;
};