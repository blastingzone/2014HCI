#include "GameObject.h"

void GameObject::UpdateCollisionBox( float posX, float posY, float w, float h )
{
	m_CollisionBox.minCoordinate.x = posX;
	m_CollisionBox.minCoordinate.y = posY;

	m_CollisionBox.maxCoordinate.x = posX + w;
	m_CollisionBox.maxCoordinate.y = posY + h;
}
