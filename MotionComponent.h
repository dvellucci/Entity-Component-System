#pragma once
#include "TransformComponent.h"


class MotionComponent : public Component {
public:
	MotionComponent(Entity* owner, float velocity, float jumpVelocity, float acceleration) : Component(owner),
		m_velocity(velocity), m_jumpVelocity(jumpVelocity), m_acceleration(acceleration) {

	}

	~MotionComponent() {

	}

	inline void setNewPosition(sf::Vector2f newPosition) {
		m_newPosition = newPosition;
	}

	inline sf::Vector2f& getNewPosition() { return m_newPosition; }
	inline float getVelocity() { return m_velocity; }
	inline float getJumpVelocity() { return m_jumpVelocity; }

	float getAcceleration() { return m_acceleration; }

private:
	sf::Vector2f m_newPosition;

	float m_velocity;
	float m_jumpVelocity;
	float m_acceleration;
};