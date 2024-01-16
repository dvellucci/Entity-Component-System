#include "RenderSystem.h"
#include <iostream>

RenderSystem::RenderSystem(World* world) : System(world) {

}

RenderSystem::~RenderSystem() {
}

void RenderSystem::update(sf::Time time) {

}

void RenderSystem::draw(sf::RenderWindow& window) {
	//auto transformComponents = m_world->getComponentManager<TransformComponent>()->getComponentsList();

	//for (auto& component : transformComponents) {

	//	if (component->getIsActive())
	//	{
	//	   window.draw(component->getSprite());
	//	}	
	//} 
}
