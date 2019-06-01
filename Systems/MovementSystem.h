#pragma once
#include "../Managers/EntityManager.h"
#include "System.h"

class MovementSystem : public System {
public:
	MovementSystem(World* world);
	~MovementSystem();

	virtual void update(sf::Time time);
	virtual void draw(sf::RenderWindow& window);
private:

};