#include "MovementSystem.h"
#include <iostream>
MovementSystem::MovementSystem(World* world) : System(world) {

}

MovementSystem::~MovementSystem() {
}

void MovementSystem::update(sf::Time time)
{
	auto& motionComponents = m_world->getComponentManager<MotionComponent>()->getComponents();
	auto& transformComponents = m_world->getComponentManager<TransformComponent>()->getComponents();

	for (auto& motionComponent : motionComponents) {
		auto entity = motionComponent.getOwner();
		auto* motion = (MotionComponent*)entity->m_componentMap[typeid(MotionComponent)];
		motion->setActive(false);

		for (auto& transformComponent : transformComponents) {
			if (transformComponent.getOwner() == motionComponent.getOwner())
				if (motionComponent.getIsActive()) {
					transformComponent.getSprite().move(motionComponent.getNewPosition());
				}		
		} 

		//WANT TO DO THIS
		//auto entity = motionComponent.getOwner();
		//auto transformComponent = entity->m_componentMap[typeid(TransformComponent)].;
		//if (transformComponent->getIsActive() && motionComponent.getIsActive())
		//{
			//transformComponent->getSprite().move(motionComponent.getNewPosition());
		//} 
	}
}

void MovementSystem::draw(sf::RenderWindow& window)
{
}
