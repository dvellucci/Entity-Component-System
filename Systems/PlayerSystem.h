#pragma once
#include "../Managers/EntityManager.h"
#include "System.h"

class PlayerSystem : public System 
{
public:
	PlayerSystem(World* world, sf::Event& event);
	~PlayerSystem();

	virtual void update(sf::Time time);
	virtual void draw(sf::RenderWindow& window);

private:
	sf::Event m_event;
	//PlayerState* state;
};