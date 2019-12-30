#pragma once
#include "../Managers/EntityManager.h"
#include "System.h"
#include "../Platformer Test/Level.h"

class PlayerSystem : public System 
{
public:
	PlayerSystem(World* world, shared_ptr<Level> level);
	~PlayerSystem();

	virtual void update(sf::Time time);
	virtual void draw(sf::RenderWindow& window);

private:
	std::shared_ptr<Level> m_level;
};