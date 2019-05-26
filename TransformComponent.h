#pragma once
#include "Entity.h"

class TransformComponent : public Component {
public:
	TransformComponent(ComponentEnum::Enum type, float x, float y) :
		Component(type), m_x(x), m_y(y) {

	}

	~TransformComponent() {

	}

	float getXpos() { return m_x; }
	float getYpos() { return m_y; }

private:
	float m_x;
	float m_y;
};