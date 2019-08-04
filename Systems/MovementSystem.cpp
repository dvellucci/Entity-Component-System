#include "MovementSystem.h"
#include <iostream>
MovementSystem::MovementSystem(World* world) : System(world) {

}

MovementSystem::~MovementSystem() {
}

void MovementSystem::update(sf::Time time)
{
	auto motionComponents = m_world->getComponentManager<MotionComponent>()->getComponentsList();

	for (auto motion : motionComponents)
	{
		auto entity = motion->getOwner();
		auto transform = entity->getComponent<TransformComponent>();
		if (motion->getIsActive())
		{
			transform->getSprite().move(motion->getNewPosition());
		}
	}
}

void MovementSystem::draw(sf::RenderWindow& window)
{
}
