#include "World.h"

World::World() {
	m_entityManager = std::make_unique<EntityManager>();

	m_componentManagers.emplace(typeid(DrawComponent), new ComponentManager<DrawComponent>());
	m_componentManagers.emplace(typeid(TransformComponent), new ComponentManager<TransformComponent>());
	m_componentManagers.emplace(typeid(MotionComponent), new ComponentManager<MotionComponent>());
	m_componentManagers.emplace(typeid(InputComponent), new ComponentManager<InputComponent>());
}

World::~World() {

}

Entity* World::createEntity() {
	return m_entityManager->createEntity();
}

void World::destroyEntity(Entity* e) {
	//destroy the entity
	m_entityManager->deleteEntity(e);

	//remove the components associated with the being destroyed
	
}
