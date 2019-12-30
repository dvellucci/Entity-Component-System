#pragma once
#include "TransformComponent.h"


class MotionComponent : public Component {
public:
	MotionComponent(Entity* owner, float velocity, float jumpVelocity, float acceleration) : Component(owner),
		m_velocity(velocity), m_jumpVelocity(jumpVelocity), m_acceleration(acceleration) {
	}

	~MotionComponent() {

	}

	float setVelocity(float vel) { m_velocity = vel; }
	float setAcceleration(float acceleration) { m_acceleration = acceleration; }
	float setJumpVelocity(float jumpVel) { m_jumpVelocity = jumpVel; }

	inline float getVelocity() { return m_velocity; }
	inline float getJumpVelocity() { return m_jumpVelocity; }

	float getAcceleration() { return m_acceleration; }

private:
	float m_velocity;
	float m_jumpVelocity;
	float m_acceleration;
};