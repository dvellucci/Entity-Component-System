#pragma once
#include "Component.h"

class InputComponent : public Component
{
public:
	InputComponent(Entity* owner) : Component(owner) 
	{
		m_jumpKey = sf::Keyboard::Space;
		m_left = sf::Keyboard::Left;
		m_right = sf::Keyboard::Right;
	}

	~InputComponent() 
	{

	}

	inline sf::Keyboard::Key& getJumpKey() { return m_jumpKey; }
	inline sf::Keyboard::Key& getLeftKey() { return m_left; }
	inline sf::Keyboard::Key& getRightKey() { return m_right; }

private:
	sf::Keyboard::Key m_jumpKey;
	sf::Keyboard::Key m_left;
	sf::Keyboard::Key m_right;
};