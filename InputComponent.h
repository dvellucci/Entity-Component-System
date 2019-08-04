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
		m_up = sf::Keyboard::Up;
		m_down = sf::Keyboard::Down;
	}

	~InputComponent() 
	{

	}

	inline sf::Keyboard::Key& getJumpKey() { return m_jumpKey; }
	inline sf::Keyboard::Key& getLeftKey() { return m_left; }
	inline sf::Keyboard::Key& getRightKey() { return m_right; }
	inline sf::Keyboard::Key& getUpKey() { return m_up; }
	inline sf::Keyboard::Key& getDownKey() { return m_down; }
	

private:
	sf::Keyboard::Key m_jumpKey;
	sf::Keyboard::Key m_left;
	sf::Keyboard::Key m_right;
	sf::Keyboard::Key m_up;
	sf::Keyboard::Key m_down;
};