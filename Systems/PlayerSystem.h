#pragma once
#include "../Managers/EntityManager.h"
#include "System.h"

class PlayerSystem : public System 
{
public:
	PlayerSystem(World* world, sf::RenderWindow* window);
	~PlayerSystem();

	virtual void update(sf::Time time);
	virtual void draw(sf::RenderWindow& window);

private:
	sf::RenderWindow* m_window;
};