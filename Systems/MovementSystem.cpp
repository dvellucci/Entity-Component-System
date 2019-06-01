#include "MovementSystem.h"
#include <iostream>
MovementSystem::MovementSystem(World* world) : System(world) {
}

MovementSystem::~MovementSystem() {
}

void MovementSystem::update(sf::Time time)
{
	auto& transformComponents = m_world->getComponentManager<TransformComponent>()->getComponents();
	auto& motionComponents = m_world->getComponentManager<MotionComponent>()->getComponents();

	for (auto& motionComponent : motionComponents) {
		auto velocity = motionComponent.getVelocity();
		TransformComponent* temp = motionComponent.getTransform();

		for (auto& transformComponent : transformComponents) {
			if(transformComponent.getId() == motionComponent.getId()) 
				if(motionComponent.getIsActive())
					transformComponent.getSprite().move(sf::Vector2f(0.4f * time.asMilliseconds(), 0));
		}
	}

	/*for (auto& motionComponent : motionComponents) {
		auto velocity = motionComponent.getVelocity();
		TransformComponent* temp = motionComponent.getTransform();
		temp->getSprite().move(sf::Vector2f(1.0f * time.asMilliseconds(), 0));
	}*/
}

void MovementSystem::draw(sf::RenderWindow& window)
{
}
