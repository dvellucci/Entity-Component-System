#pragma once
#include "Component.h"

class MotionComponent : public Component {
public:
	MotionComponent(ComponentEnum::Enum type, int velocity) : 
					Component(type), m_velocity(velocity) {

	}

	~MotionComponent() {

	}

	int getVelocity() { return m_velocity; }


private:
	int m_velocity;
};