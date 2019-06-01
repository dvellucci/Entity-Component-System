#pragma once
#include "../Managers/EntityManager.h"
#include "System.h"

class RenderSystem : public System {
public:
	RenderSystem(World* world);
	~RenderSystem();

	virtual void update(sf::Time time);
	virtual void draw(sf::RenderWindow& window);

private:
	EntityManager* m_manager;
};