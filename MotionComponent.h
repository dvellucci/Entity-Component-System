#pragma once
#include "TransformComponent.h"


class MotionComponent : public Component {
public:
	MotionComponent(uint id, float velocity, int acceleration) : Component(id),
		m_velocity(velocity), m_acceleration(acceleration) {

	}

	~MotionComponent() {

	}

	TransformComponent* getTransform() { return m_transform; }
	float getVelocity() { return m_velocity; }
	int getAcceleration() { return m_acceleration; }

private:
	float m_velocity;
	int m_acceleration;
	TransformComponent* m_transform;
};