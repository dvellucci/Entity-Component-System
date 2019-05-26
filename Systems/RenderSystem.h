#pragma once
#include <SFML/Graphics.hpp>
#include "../Managers/EntityManager.h"
#include "System.h"

class RenderSystem : public System {
public:
	RenderSystem(EntityManager* manager);
	~RenderSystem();

	void update(int dt);
	void draw(sf::RenderWindow& window);

private:
	EntityManager* m_manager;
};