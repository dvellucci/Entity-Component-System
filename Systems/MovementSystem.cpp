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
		auto collision = entity->getComponent<CollisionComponent>();
		if (motion->getIsActive())
		{
			transform->getSprite().move(transform->getPosition());

			//update the collision box of the object when it moves
			if (collision)
				collision->setRectBox(transform->getSprite().getGlobalBounds());
		}
	}
}

void MovementSystem::draw(sf::RenderWindow& window)
{
}
