#include "RenderSystem.h"
#include <iostream>

RenderSystem::RenderSystem(World* world) : System(world) {

}

RenderSystem::~RenderSystem() {
}

void RenderSystem::update(sf::Time time) {

}

void RenderSystem::draw(sf::RenderWindow& window) {
	auto transformComponents = m_world->getComponentManager<TransformComponent>()->getComponents();
	
	for (auto& component : transformComponents) {

		auto temp = reinterpret_cast<TransformComponent*>(component.getOwner()->getComponent<TransformComponent>());

		if (component.getIsActive())
		{
		   window.draw(component.getSprite());
		}	
	}
}
