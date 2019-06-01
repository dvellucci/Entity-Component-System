#include "World.h"

World::World() {
	m_entityManager = std::make_unique<EntityManager>();

	//register the component managers
	m_componentManagers.emplace(typeid(DrawComponent), new ComponentManager<DrawComponent>());
	m_componentManagers.emplace(typeid(TransformComponent), new ComponentManager<TransformComponent>());
	m_componentManagers.emplace(typeid(MotionComponent), new ComponentManager<MotionComponent>());

	//register the systems

}

World::~World(){

}

Entity* World::createEntity() {
	return m_entityManager->createEntity();
}

void World::destroyEntity(Entity* e) {
	//set the components to inactive
	for (auto& component : e->getComponents()) {
		component->setActive(false);
	}
	//destroy the entity
	m_entityManager->deleteEntity(e);
}
