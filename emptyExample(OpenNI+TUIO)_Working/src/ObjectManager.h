#pragma once
#include <vector>
#include "ofPoint.h"

class GameObject;
class Ball;
class ManipulatedBar;

class ObjectManager
{
public:
	ObjectManager() {};
	~ObjectManager();

	void Init();
	void Update( float dt, ofPoint LHandPos, ofPoint RHandPos );
	void Render();
	void AddObject(GameObject* obj);
	void CollisionCheck();

	void SetBarPosition(float x, float y);
	bool IsAllBroken();

private:
	std::vector<GameObject*> m_GameBlockList;
	Ball* m_Ball;
	ManipulatedBar* m_Bar;
};