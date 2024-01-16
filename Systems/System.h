#pragma once
#include "../Entity.h"
#include "../World.h"
#include <SFML/Graphics.hpp>

class System 
{
public:
	System(World* world) : m_world(world) {
	}

	virtual ~System() {
	}

	virtual void init() = 0;
	virtual void update(sf::Time time) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	World* getWorld() { return m_world; }

protected:
	World* m_world;
};