#pragma once
#include "GameObject.h"

class Block : public GameObject
{
public:
	Block(ofPoint position, float width, float height);
	virtual ~Block();
	
	virtual void Render();
	virtual void Update(float dt);

	void BreakBlock();
	// 충돌 체크하기 전에 검사
	bool IsBrokenAlready() { return IsBroken; };
	
private:
	Block();
	int color;
	bool IsBroken;
};