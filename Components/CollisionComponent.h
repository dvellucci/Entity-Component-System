#pragma once
#include "Component.h"

class CollisionComponent : public Component
{
public:
	CollisionComponent(Entity* owner, sf::Rect<int> box) : Component(owner), m_box(box) {}
	~CollisionComponent() {}

	inline void setRectBox(sf::Rect<float> box) { m_box = box; }
	inline sf::Rect<float>& getRectBox() { return m_box; }
	inline bool tileCollision(CollisionComponent* collision) { return false; }

private:
	//top, bottom, width, height
	sf::Rect<float> m_box;
	
};